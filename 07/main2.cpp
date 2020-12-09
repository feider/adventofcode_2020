#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <list>

typedef std::map<std::string, std::vector<std::string>> bagmap;
typedef std::map<std::string, std::vector<int>> bagnums;


int find_digit(const std::string & str, int start = 0)
{
    for(int i = start; i<str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            return i;
    }
    return -1;
}

int count_bags(std::string col, bagmap & bags, bagnums & nums)
{
    const std::vector<int> counts = nums[col];
    const std::vector<std::string> content = bags[col];
    std::cout<<content.size()<<std::endl;

    std::cout<<col<<std::endl;
    if(content.size() == 0)
        return 1;
    
    int num = 0;

    for(int i = 0; i<counts.size(); i++)
    {
        num += (counts[i] * count_bags(content[i], bags, nums));
    }

    return num;


}


int main() {

    bagmap bags;
    bagnums nums;
    std::ifstream file("input.txt");
    std::string line;

    while(std::getline(file, line))
    {
        int bc = line.find("bags contain");
        std::string bcolor = line.substr(0, bc-1);
        if(!bags.contains(bcolor))
        {
            bags[bcolor] = std::vector<std::string>();
            nums[bcolor] = std::vector<int>();
        }
        else
            std::cout<<bcolor<<" already exists!"<<std::endl;
        int startpos = find_digit(line);
        while(startpos != -1)
        {
            std::cout<<line[startpos]<<std::endl;
            int num = line[startpos]-'0';
            int endpos = line.find("bag", startpos)-1;
            std::string ccolor = line.substr(startpos+2, endpos-(startpos+2));
            bags[bcolor].push_back(ccolor);
            nums[bcolor].push_back(num);
            startpos = find_digit(line, endpos);
        }
    }

    std::list<std::string> testbags;
    std::list<int> testnums;

    testbags.push_back("shiny gold");
    testnums.push_back(1);

    int all = -1; // minus one for the initial bag

    while(testbags.size() > 0)
    {
        std::string current_bag = testbags.front();
        int current_num = testnums.front();
        testbags.pop_front();
        testnums.pop_front();

        all += current_num;
        
        for(int i = 0; i<bags[current_bag].size(); i++)
        {
            int n = nums[current_bag][i];
            std::string b = bags[current_bag][i];
            

            testbags.push_back(b);
            testnums.push_back(n*current_num);
        }
    }
    std::cout<<all<<std::endl;


    return 0;
}
