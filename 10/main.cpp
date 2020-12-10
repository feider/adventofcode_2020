#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>

int main(){
    std::ifstream file("input.txt");
    int num; 
    std::vector<int> numbers;
    while(file >> num)
    {
        numbers.push_back(num);
    }
    numbers.push_back(0);
    std::sort(numbers.begin(), numbers.end(), std::less<int>());
    int maxval = *(numbers.end()-1)+3;
    numbers.push_back(maxval);

    int jolts[3] = {0, 0, 0};
    for(auto n = numbers.begin(); n != numbers.end()-1; n++)
    {
        int n0 = *n;
        int n1 = *(n+1);
        int d = n1-n0-1;
        jolts[d] ++;
    }
    int sol1 = jolts[0] * jolts[2];

    std::cout<<jolts[0]<<" "<<jolts[1]<<" "<<jolts[2]<<std::endl;
    std::cout<<"Solution 1: "<<sol1<<std::endl;



    // this could be shortened, no need to keep the whole memory in mind, only
    // the three last entries are needed
    // maybe I'll change that later, got the star for now :)
    std::vector<bool> access;
    std::vector<long> ways;
    for(int i = 0; i<=numbers[numbers.size()-1]; i++)
    {
        access.push_back(false);
        ways.push_back(0);
    }
    ways[ways.size()-1] = 1;
    for(auto n : numbers)
        access[n] = true;

    int num_solutions = 0;
    for(int c = access.size()-2; c >= 0; c--)
    {
        if(!access[c])
            continue;

        for( int _c = c+1; _c <= c+3 && _c < access.size(); _c++)
        {
            if(access[_c])
                ways[c] += ways[_c];
        }
    }
    std::cout<<"Solution 2: "<<ways[0]<<std::endl;
    
    return 0;
}
