#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

typedef std::map<std::string, std::string> pmap;

bool is_number(const std::string & str)
{
    bool number = !str.empty();
    for(auto s = str.begin(); s!=str.end(); s++)
    {
        number = number && std::isdigit(*s);
    }
    return number;
}

int main()
{
    std::vector<pmap> passports;

    passports.push_back(pmap());

    std::ifstream file("input.txt");
    std::string line;
    while(std::getline(file, line))
    {
        if(line.size() == 0)
        {
            passports.push_back(pmap());
            continue;
        }

        pmap & p = passports.back();
        std::stringstream l;
        std::string pair;
        l << line;
        while(l >> pair)
        {
            int cpos = pair.find(":");
            std::string key = pair.substr(0, cpos);
            std::string val = pair.substr(cpos+1);
            p[key] = val;
        }
    }

    std::vector<std::string> keys = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};


    int valid = 0;
    for(int i = 0; i<passports.size(); i++)
    {
        pmap & p = passports[i];
        int is_valid = 1;
        for(int k = 0; k<keys.size(); k++)
        {

            if(p.find( keys[k] ) == p.end())
                is_valid = 0;
        }
        if(is_valid == 1)
        {
            int byr = atoi(p["byr"].c_str());
            if(byr < 1920 || byr > 2002 || !is_number(p["byr"]))
                is_valid = 0;

            int iyr = atoi(p["iyr"].c_str());
            if(iyr < 2010 || iyr > 2020 || !is_number(p["iyr"]))
                is_valid = 0;

            int eyr = atoi(p["eyr"].c_str());
            if(eyr < 2020 || eyr > 2030 || !is_number(p["eyr"]))
                is_valid = 0;

            std::string hgt = p["hgt"];
            if(hgt.find("cm") == hgt.size()-2)
            {
                int cm = atoi(hgt.substr(0, hgt.find("cm")).c_str());
                if(cm < 150 || cm > 193)
                    is_valid = 0;
            }
            else if(hgt.find("in") == hgt.size()-2)
            {
                int in = atoi(hgt.substr(0, hgt.find("in")).c_str());
                if(in < 59 || in > 76)
                    is_valid = 0;
            }
            else
                is_valid = 0;

            // could do regex, won't
            std::string hcl = p["hcl"];
            if(hcl.size() != 7)
                is_valid = 0;
            if(hcl.c_str()[0] != '#')
                is_valid = 0;
            for(int ic = 1; ic <7; ic++)
            {
                char c = hcl.c_str()[ic];
                if( (c<'0' || c>'9') && (c<'a' || c>'f'))
                    is_valid = 0;
            }


            std::string ecl = p["ecl"];
            if( !(
                        ecl == "amb" ||
                        ecl == "blu" ||
                        ecl == "brn" ||
                        ecl == "gry" ||
                        ecl == "grn" ||
                        ecl == "hzl" ||
                        ecl == "oth"
                    ) )
                is_valid = 0;

            std::string pid = p["pid"];
            if(pid.size() != 9)
                is_valid = 0;
            if(!is_number(pid))
                is_valid = 0;


        }

        valid += is_valid;
    }
    std::cout<<valid<<std::endl;



    return 0;
}
