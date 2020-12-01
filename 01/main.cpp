#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream file("input.txt");
    int num;
    std::vector<int> nums;
    while(file >> num)
    {
        nums.push_back(num);
    }


    for(int i = 0; i<nums.size()-1; i++)
    {
        for(int j = i+1; j<nums.size(); j++)
        {
            if(nums[i] + nums[j] == 2020)
            {
                std::cout<<nums[i]*nums[j]<<std::endl;
                return 0;
            }
        }
    }
    std::cout<<"no result found"<<std::endl;
    return 0;
}
