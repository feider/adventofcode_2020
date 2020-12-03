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
        int min = atoi(range.substr(0, dashpos).c_str());
        int max = atoi(range.substr(dashpos+1).c_str());
        int num_letter = 0;
        for(int i = 0; i<password.size(); i++)
        {
            if(password.c_str()[i] == l)
                num_letter ++;
        }
        if ( (min <= num_letter ) && (max >= num_letter) )
            valid ++;
    }
    std::cout<<valid<<std::endl;

    return 0;
}
