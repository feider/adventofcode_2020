#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

typedef std::map<std::string, std::string> pmap;

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
        valid += is_valid;
    }
    std::cout<<valid<<std::endl;



    return 0;
}
