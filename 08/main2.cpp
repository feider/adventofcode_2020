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
    
    bool terminated = false;
    for(int i = 0; i<instructions.size() && !terminated; i++)
    {

        if(instructions[i].first == "nop" || instructions[i].first == "jmp")
        {
            acc = 0;
            cursor = 0;
            for(auto v : visited)
                v = false;
            auto ins_temp = instructions;
            if(ins_temp[i].first == "nop")
                ins_temp[i].first == "jmp";
            else
                ins_temp[i].first = "nop";

            while(cursor < ins_temp.size() && !visited[cursor])
            {
                visited[cursor] = true;
                const std::string & ins = ins_temp[cursor].first;
                const int & val = ins_temp[cursor].second;

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
            terminated = (cursor == ins_temp.size());
        }
    }
    std::cout<<acc<<std::endl;

    return 0;
}
