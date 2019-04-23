#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkingRegex (string line){
regex r{"^([a-zA-z0-9]{1,8})*?(\\s*?)((\\+[A-Z]{1,5})|([A-Z]{1,6}))(\\s+)([@|#]?([a-zA-z0-9]+)|([a-zA-z0-9]+\\,{1}[X])|([ABLSTX]\\,{1}[ABLSTX]))$"};

if(regex_match(line,r)){
            return true;
    } else {
    return false;
    }
}

int main()
{
    /*initializing the map*/
    map<string,string> opCode;
    opCode["START"] = "^[a-fA-F0-9]{1,18}$";
    opCode["ADD"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"ADD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["ADDR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"ADDR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["CLEAR"] = "^[ABLSTX]$";
    //opCode.insert({"CLEAR","^[ABLSTX]$"});
    opCode["COMP"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"COMP","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["COMPR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"COMPR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["DIV"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"DIV","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["DIVR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"DIVR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["J"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"J","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["JEQ"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"JEQ","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["JLT"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"JLT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["JGT"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"JGT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["JSUB"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"JSUB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDA"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"LDA","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDB"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"LDB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDCH"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"LDCH","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDL"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"LDL","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDS"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"LDS","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDT"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"LDT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDX"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"LDX","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["MUL"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"MUL","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["MULR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"MULR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["RMO"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"RMO","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["RSUB"] = "^$";
    //opCode.insert({"RSUB","^$"});
    opCode["STA"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"STA","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STB"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"STB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STCH"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"STCH","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STL"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"STL","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STS"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"STS","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STT"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"STT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STX"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"STX","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["SUB"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"SUB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["SUBR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"SUBR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["RD"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"RD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["TD"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"TD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["WD"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"WD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["TIX"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    //opCode.insert({"TIX","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["TIXR"] = "^[ABLSTX]$}";
    //opCode.insert({"TIXR","^[ABLSTX]$}"});
    opCode["BYTE"] = "^(((?i)[X]\\'[a-fA-F0-9]{0,15}\\')|((?i)[C]\\'[a-zA-Z0-9]{0,15}\\'))$";
    //opCode.insert({"BYTE","^(((?i)[X]\\'[a-fA-F0-9]{0,15}\\')|((?i)[C]\\'[a-zA-Z0-9]{0,15}\\'))$"});
    opCode["RESB"] = "^[0-9]{1,18}$";
    //opCode.insert({"RESB","^[0-9]{1,18}$"});
    opCode["WORD"] = "^[0-9]{1,18}$";
    //opCode.insert({"WORD","^[0-9]{1,18}$"});
    opCode["RESW"] = "^[0-9]{1,18}$";
    //opCode.insert({"RESW","^[0-9]{1,18}$"});

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
    cout<<lines.at(0) + "\n";
    cout<<lines.at(1);
    if (opCode.find("aaa") != opCode.end()){
        cout<<opCode.at("ffd");
    } else {
    cout<<"ERROR";
    }

    regex r{"^([a-zA-z0-9]{1,8})*?(\\s*?)((\\+[A-Z]{1,5})|([A-Z]{1,6}))(\\s+)([@|#]?([a-zA-z0-9]+)|([a-zA-z0-9]+\\,{1}[X])|([ABLSTX]\\,{1}[ABLSTX]))$"};
    if(regex_match(lines.at(0),r)){
            cout<<"MATCH";
    }
    return 0;
}
