#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*initializing the map*/
    map<string,string> opCode;
    opCode.insert({"ADD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"ADDR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode.insert({"CLEAR","^[ABLSTX]$"});
    opCode.insert({"COMP","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"COMPR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode.insert({"DIV","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"DIVR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode.insert({"J","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"JEQ","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"JLT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"JGT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"JSUB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"LDA","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"LDB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"LDCH","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"LDL","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"LDS","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"LDT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"LDX","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"MUL","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"MULR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode.insert({"RMO","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode.insert({"RSUB","^$"});
    opCode.insert({"STA","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"STB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"STCH","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"STL","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"STS","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"STT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"STX","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"SUB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"SUBR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode.insert({"RD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"TD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"WD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"TIX","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode.insert({"TIXR","^[ABLSTX]$}"});

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
    regex r{"^([a-zA-z0-9]{1,8})?(\\s*?)((\\+[A-Z]{1,5})|([A-Z]{1,6}))(\\s+)([@|#]?([a-zA-z0-9]+)|([a-zA-z0-9]+\\,{1}[X])|([ABLSTX]\\,{1}[ABLSTX]))$"};
    if(regex_match(lines.at(0),r)){
            cout<<"MATCH";
    }
    return 0;
}
