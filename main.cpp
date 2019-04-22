#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*initializing the map*/
    map<string,int> opCode;
    opCode.insert({"ADD",0x18});opCode.insert({"ADDR",0x90});opCode.insert({"CLEAR",0xB4});opCode.insert({"COMP",0x18});
    opCode.insert({"COMPR",0xA0});opCode.insert({"DIV",0x24});opCode.insert({"DIVR",0x9C});opCode.insert({"J",0x3C});
    opCode.insert({"JEQ",0x30});opCode.insert({"JLT",0x38});opCode.insert({"JGT",0x34});opCode.insert({"JSUB",0x48});
    opCode.insert({"LDA",0x00});opCode.insert({"LDB",0x68});opCode.insert({"LDCH",0x50});opCode.insert({"LDL",0x08});
    opCode.insert({"LDS",0x6C});opCode.insert({"LDT",0x74});opCode.insert({"LDX",0x04});opCode.insert({"MUL",0x20});
    opCode.insert({"MULR",0x98});opCode.insert({"RMO",0xAC});opCode.insert({"RSUB",0x4C});opCode.insert({"COMP",0x18});
    opCode.insert({"STA",0x0C});opCode.insert({"STB",0x78});opCode.insert({"STCH",0x54});opCode.insert({"STL",0x14});
    opCode.insert({"STS",0x7C});opCode.insert({"STT",0x84});opCode.insert({"STX",0x10});opCode.insert({"SUB",0x1C});
    opCode.insert({"SUBR",0x94});opCode.insert({"RD",0xD8});opCode.insert({"TD",0xE0});opCode.insert({"WD",0xDC});
    opCode.insert({"TIX",0x2C});opCode.insert({"TIXR",0xB8});

    /*READING FROM FILE
    ===================*/
    ifstream inputFile("input.txt");
    vector<string> lines;
    if(inputFile.is_open()){
        string line;
        while(getline(inputFile,line)){
            lines.push_back(line);
        }
        inputFile.close();
    }
    regex r{"^([a-zA-z0-9]+)?(\\s*?)([+]?[A-Z]+)(\\s+)([@|#]?([a-zA-z0-9]+)|([a-zA-z0-9]+\\,{1}[X])|([ABLSTX]\\,{1}[ABLSTX]))$"};
    if(regex_match(lines.at(0),r)){
            cout<<"MATCH";
    }
    return 0;
}
