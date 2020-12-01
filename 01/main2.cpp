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


    for(int i = 0; i<nums.size()-2; i++)
    {
        for(int j = i+1; j<nums.size()-1; j++)
        {
            if(nums[i] + nums[j] > 2020)
                continue;
            for(int k = j+1; k<nums.size(); k++)
                if(nums[i] + nums[j] + nums[k] == 2020)
                {
                    std::cout<<nums[i]*nums[j]*nums[k]<<std::endl;
                    return 0;
                }
        }
    }
    std::cout<<"no result found"<<std::endl;
    return 0;
}
