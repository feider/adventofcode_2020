#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <list>

typedef std::map<std::string, std::vector<std::string>> bagmap;


int find_digit(const std::string & str, int start = 0)
{
    for(int i = start; i<str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            return i;
    }
    return -1;
}


int main() {

    bagmap bags;
    std::ifstream file("input.txt");
    std::string line;

    while(std::getline(file, line))
    {
        int bc = line.find("bags contain");
        std::string bcolor = line.substr(0, bc-1);
        if(!bags.contains(bcolor))
            bags[bcolor] = std::vector<std::string>();
        else
            std::cout<<bcolor<<" already exists!"<<std::endl;
        int startpos = find_digit(line);
        while(startpos != -1)
        {
            int endpos = line.find("bag", startpos)-1;
            std::string ccolor = line.substr(startpos+2, endpos-(startpos+2));
            bags[bcolor].push_back(ccolor);
            startpos = find_digit(line, endpos);
        }
    }



    int num_bags = 0;
    std::cout<<bags.size()<<" bag types"<<std::endl;
    std::string query("shiny gold");
    for(auto bag : bags)
    {
        if (bag.first == query)
            continue;

        std::list<std::string> testbags;
        testbags.push_back(bag.first);
        while(testbags.size() > 0)
        {
            std::string current_bag = testbags.front();
            testbags.pop_front();

            if(current_bag == query)
            {
                num_bags++;
                break;
            }

            for(std::string content : bags[current_bag])
                testbags.push_back(content);

        }
            
    };
    std::cout<<num_bags<<" bags contain shiny gold"<<std::endl;

    return 0;
}
