#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


bool is_sum(const std::vector<int> & numbers, int pos, int pre)
{
    for(int i = pos-pre; i<pos; i++)
        for(int j = i+1; j<pos; j++)
        {
            int c = numbers[pos];
            int b = numbers[j];
            int a = numbers[i];
            if(numbers[pos] == numbers[i] + numbers[j])
            {
                return true;
            }
        }
    return false;
}

// returns the length of the range that fits to the value
int compute_range(const std::vector <int> & numbers, int pos, int val)
{
    if(numbers[pos] == val)
        return -1;

    int sum = 0;
    for(int i = pos; i < numbers.size() && sum < val; i++)
    {
        sum += numbers[i];
        if(sum == val)
            return i-pos+1;
    }
    return -1;
}


int main() {
    int pre = 25;
    std::vector<int> numbers;
    std::ifstream file("input.txt");
    int num;

    int sol1 = 0;
    while(file >> num)
    {
        numbers.push_back(num);
        if(numbers.size() > pre)
        {
            int p = numbers.size()-1;
            if(!is_sum(numbers, p, pre))
            {
                sol1 = numbers[p];
            }

        }
    }
    std::cout<<"Solution 1: "<<sol1<<std::endl;


    int sol2 = 0;
    auto first = numbers.begin();
    auto last = numbers.begin();
    int sum = *first;
    while(sum != sol1)
    {
        if(sum > sol1)
        {
            sum -= *first;
            first++;
        }
        else if(sum < sol1)
        {
            last++;
            sum += *last;
        }
    }
    auto [min, max] = std::minmax_element(first, last+1);
    sol2 = *min+*max;
    std::cout<<"Solution 2: "<<sol2<<std::endl;








    return 0;
}
