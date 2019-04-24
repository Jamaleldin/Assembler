#include <iostream>
#include <bits/stdc++.h>
#include <regex>

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
    string operandCommonRegex = "^(((@|#)([^\\s,.@#*]{1,17}))|([^\\s,.@#*]{1,18})|(([^\\s.@#*]{1,16})\\,(x)))$";
    /*initializing the map*/
    map<string,string> opCode;
    opCode["START"] = "^[a-fA-F0-9]{1,18}$";
    opCode["ADD"] = operandCommonRegex;
    //opCode.insert({"ADD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["ADDR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"ADDR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["CLEAR"] = "^[ABLSTX]$";
    //opCode.insert({"CLEAR","^[ABLSTX]$"});
    opCode["COMP"] = operandCommonRegex;
    //opCode.insert({"COMP","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["COMPR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"COMPR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["DIV"] = operandCommonRegex;
    //opCode.insert({"DIV","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["DIVR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"DIVR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["J"] = "^(((@|#)([^\\s.@#*]{1,17}))|([^\\s.@#*]{1,18})|(\\*))$";
    //opCode.insert({"J","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["JEQ"] = "^(((@|#)([^\\s.@#*]{1,17}))|([^\\s.@#*]{1,18})|(\\*))$";
    //opCode.insert({"JEQ","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["JLT"] = "^(((@|#)([^\\s.@#*]{1,17}))|([^\\s.@#]{1,18})|(\\*))$";
    //opCode.insert({"JLT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["JGT"] = "^(((@|#)([^\\s.@#*]{1,17}))|([^\\s.@*#]{1,18})|(\\*))$";
    //opCode.insert({"JGT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["JSUB"] = "^(((@|#)([^\\s.@#*]{1,17}))|([^\\s.@#*]{1,18})|(\\*))$";
    //opCode.insert({"JSUB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDA"] = operandCommonRegex;
    //opCode.insert({"LDA","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDB"] = operandCommonRegex;
    //opCode.insert({"LDB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDCH"] = operandCommonRegex;
    //opCode.insert({"LDCH","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDL"] = operandCommonRegex;
    //opCode.insert({"LDL","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDS"] = operandCommonRegex;
    //opCode.insert({"LDS","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDT"] = operandCommonRegex;
    //opCode.insert({"LDT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["LDX"] = operandCommonRegex;
    //opCode.insert({"LDX","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["MUL"] = operandCommonRegex;
    //opCode.insert({"MUL","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["MULR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"MULR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["RMO"] = "^[ABLSTX]\\,[ABLSTX]$}";
    //opCode.insert({"RMO","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["RSUB"] = "^\\s*(\\..*)?\\s*$";
    //opCode.insert({"RSUB","^$"});
    opCode["STA"] = operandCommonRegex;
    //opCode.insert({"STA","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STB"] = operandCommonRegex;
    //opCode.insert({"STB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STCH"] = operandCommonRegex;
    //opCode.insert({"STCH","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STL"] = operandCommonRegex;
    //opCode.insert({"STL","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STS"] = operandCommonRegex;
    //opCode.insert({"STS","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STT"] = operandCommonRegex;
    //opCode.insert({"STT","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["STX"] = operandCommonRegex;
    //opCode.insert({"STX","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["SUB"] = operandCommonRegex;
    //opCode.insert({"SUB","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["SUBR"] = operandCommonRegex;
    //opCode.insert({"SUBR","^[ABLSTX]\\,[ABLSTX]$}"});
    opCode["RD"] = "^(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18})|([X]\\'[a-fA-F0-9]{0,14}\\'))$";
    //opCode.insert({"RD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["TD"] = "^(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18})|([X]\\'[a-fA-F0-9]{0,14}\\'))$";
    //opCode.insert({"TD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["WD"] = "^(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18})|([X]\\'[a-fA-F0-9]{0,14}\\'))$";
    //opCode.insert({"WD","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["TIX"] = operandCommonRegex;
    //opCode.insert({"TIX","^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$"});
    opCode["TIXR"] = "^[ABLSTX]$}";
    //opCode.insert({"TIXR","^[ABLSTX]$}"});
    opCode["BYTE"] = "^(([X]\\'[a-fA-F0-9]{0,14}\\')|([C]\\'[a-zA-Z0-9]{0,15}\\'))$";
    //opCode.insert({"BYTE","^(((?i)[X]\\'[a-fA-F0-9]{0,15}\\')|((?i)[C]\\'[a-zA-Z0-9]{0,15}\\'))$"});
    opCode["RESB"] = "^[0-9]{1,18}$";
    //opCode.insert({"RESB","^[0-9]{1,18}$"});
    opCode["WORD"] = "^(([0-9]{1,18})|((#|@)([0-9]{1,17}))|(([0-9])(\\,)?))$";
    //opCode.insert({"WORD","^[0-9]{1,18}$"});
    opCode["RESW"] = "^[0-9]{1,18}$";
    //opCode.insert({"RESW","^[0-9]{1,18}$"});
    opCode["END"] = "^(((@|#)([^\\s.@#*]{1,17}))|([^\\s.@#*]{1,18}))?$";
    opCode["ORG"] = "^((\\w+)|(\\*))$";


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
   /* cout<<lines.at(0) + "\n";
    //cout<<lines.at(1);
    if (opCode.find("aaa") != opCode.end()){
        cout<<opCode.at("ffd");
    } else {
    cout<<"ERROR";
    }*/

    //regex r{"^([a-zA-z0-9]{1,8})*?(\\s*?)(((\\+(?i)[A-Z]{1,5})|((?i)[A-Z]{1,6}))(\\s+)([@|#]?((?i)[a-zA-z0-9]+)|((?i)[a-zA-z0-9]+\\,{1}(?i)[X])|((?i)[ABLSTX]\\,{1}(?i)[ABLSTX])))|((?i)end)|((?i)rsub)$"};
    std::regex secondFormate("^\\s*(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+([ABLSTX]\\s*,\\s*[ABLSTX])\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex thirdFormate("^\\s*(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex forthFormate("^\\s*(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+){0,1}?((\\+)([a-zA-Z]{1,5}))\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex returnSub("^\\s*(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+){0,1}?((\\+)?(rsub))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex endProg("^\\s*(end)(\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18})))?\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    if(regex_match(lines.at(0),endProg)){
        cout<<"end!";
    }else if(regex_match(lines.at(0),returnSub)){
        cout<<"return!";
    }else if(regex_match(lines.at(0),secondFormate)){
        cout<<"2nd formate!";
    }else if(regex_match(lines.at(0),thirdFormate)){
        cout<<"3rd formate!";
    }else if(regex_match(lines.at(0),forthFormate)){
        cout<<"4th formate!";
    }else{
        cout<<"error!";
    }
    return 0;
}
