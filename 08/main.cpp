#include <iostream>
#include <vector>
#include <fstream>
#include <utility>




int main(){
    std::vector<std::pair< std::string, int >> instructions;
    std::vector<bool> visited;
    std::ifstream file("input.txt");
    std::string line;
    while(std::getline(file, line))
    {
        int spos = line.find(" ");
        std::string cmd = line.substr(0, spos);
        int val = atoi(line.substr(spos+1).c_str());
        instructions.push_back( {cmd, val} );
        visited.push_back(false);
    }

    int cursor = 0;
    int acc = 0;

    while(!visited[cursor])
    {
        visited[cursor] = true;
        const std::string & ins = instructions[cursor].first;
        const int & val = instructions[cursor].second;

        if(ins == "acc")
        {
            cursor ++;
            acc += val;
        }
        else if(ins == "jmp")
        {
            cursor += val;
        }
        else if(ins == "nop")
        {
            cursor ++;
        }
    }
    std::cout<<acc<<std::endl;

    return 0;
}
