#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream file("input.txt");
    std::string range, letter, password;
    char l;
    int valid = 0;
    while(file >> range >> letter >> password)
    {
        l = letter.c_str()[0];
        int dashpos = range.find("-");
        int f = atoi(range.substr(0, dashpos).c_str())-1;
        int s = atoi(range.substr(dashpos+1).c_str())-1;
        int num_letter = 0;
        if( (password.c_str()[f] == l) ^ (password.c_str()[s] == l))
            valid ++;
    }
    std::cout<<valid<<std::endl;

    return 0;
}
