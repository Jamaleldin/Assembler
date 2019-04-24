#include <iostream>
#include <bits/stdc++.h>
#include <regex>

using namespace std;

bool checkingRegex (string line, string reg)
{
    regex r{reg};

    if(regex_match(line,r))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string getFirstGroup(string line)
{
    regex r{"^([a-zA-z0-9]{1,8})*?(\\s*?)(((\\+(?i)[A-Z]{1,5})|((?i)[A-Z]{1,6}))(\\s+)([@|#]?((?i)[a-zA-z0-9]+)|((?i)[a-zA-z0-9]+\\,{1}(?i)[X])|((?i)[ABLSTX]\\,{1}(?i)[ABLSTX])))|((?i)end)$"};

    smatch match;

    if (regex_search(line, match, r) == true)
    {
        return match.str(1);
    }
    else
    {
        return nullptr;
    }

}

string getSecondGroup(string line)
{
    regex r{"^([a-zA-z0-9]{1,8})*?(\\s*?)(((\\+(?i)[A-Z]{1,5})|((?i)[A-Z]{1,6}))(\\s+)([@|#]?((?i)[a-zA-z0-9]+)|((?i)[a-zA-z0-9]+\\,{1}(?i)[X])|((?i)[ABLSTX]\\,{1}(?i)[ABLSTX])))|((?i)end)$"};

    smatch match;

    if (regex_search(line, match, r) == true)
    {
        return match.str(5);
    }
    else
    {
        return nullptr;
    }

}


string getThirdGroup(string line)
{
    regex r{"^([a-zA-z0-9]{1,8})*?(\\s*?)(((\\+(?i)[A-Z]{1,5})|((?i)[A-Z]{1,6}))(\\s+)([@|#]?((?i)[a-zA-z0-9]+)|((?i)[a-zA-z0-9]+\\,{1}(?i)[X])|((?i)[ABLSTX]\\,{1}(?i)[ABLSTX])))|((?i)end)$"};

    smatch match;

    if (regex_search(line, match, r) == true)
    {
        return match.str(9);
    }
    else
    {
        return nullptr;
    }

}

bool commentChecker(string mainStr)
{
    // std::string::find returns 0 if toMatch is found at starting
    if(mainStr.find(".") == 0)
        return true;
    else
        return false;
}

int getHex(string hexstr)
{
    return (int)strtol(hexstr.c_str(), 0, 16);
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
    opCode["END"] = "^$";

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
    regex secondFormate("^\\s*([^\\s.@#]{1,8}\\s+){0,1}?([a-z]{1,6})\\s+([ABLSTX]\\s*,\\s*[ABLSTX])\\s*$",std::regex_constants::icase);
    regex thirdFormate("^\\s*([^\\s.@#]{1,8}\\s+){0,1}?([a-z]{1,6})\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    regex forthFormate("^\\s*([^\\s.@#]{1,8}\\s+){0,1}?((\\+)([a-z]{1,5}))\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    regex returnSub("^\\s*([^\\s.@#]{1,8}?\\s+){0,1}?((\\+)?(rsub))\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    regex endProg("^\\s*([^\\s.@#]{1,8}?\\s+){0,1}?(end)\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    regex startProg("^\\s*([^\\s.@#]{1,8}?\\s+){1}(start)\\s+([a-f0-9]{1,18})\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    if(regex_match(lines.at(0),startProg)){
            cout<<"start!";
    }else if(regex_match(lines.at(0),endProg)){
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
        cout<<"error";
    }

    int i = 0;
    int addressingCounter = 0;
    for (i = 0; i < lines.size(); i++)
    {
        if (!commentChecker(lines.at(i)))
        {
            if (getSecondGroup(lines.at(i)).compare("START") == 0)
            {
                if (checkingRegex(getThirdGroup(lines.at(i)), opCode.at(getSecondGroup(lines.at(i)))))
                {
                    addressingCounter = getHex(getThirdGroup(lines.at(i)));
                }
            }
            else if (getSecondGroup(lines.at(i)).compare("END") != 0)
            {
                if (!getFirstGroup(lines.at(i)).compare(" "))
                {
                    //search in symbol table and handle cases
                }
                string op = getSecondGroup(lines.at(i));

                if (op.compare("WORD"))
                {
                    if (checkingRegex(getThirdGroup(lines.at(i)), opCode.at("WORD")))
                    {
                        addressingCounter += 3;
                    }

                }
                else if (op.compare("RESW"))
                {
                    if (checkingRegex(getThirdGroup(lines.at(i)), opCode.at("RESW")))
                    {
                        addressingCounter += 3 * getHex(getThirdGroup(lines.at(i)));
                    }
                }
                else if (op.compare("RESB"))
                {
                    if (checkingRegex(getThirdGroup(lines.at(i)), opCode.at("RESB")))
                    {
                        addressingCounter += getHex(getThirdGroup(lines.at(i)));
                    }
                }
                else if (op.compare("BYTE"))
                {
                    if (checkingRegex(getThirdGroup(lines.at(i)), opCode.at("BYTE")))
                    {
                        addressingCounter += getThirdGroup(lines.at(i)).size() - 3;
                    }
                }
                else
                {
                    if (checkingRegex(getThirdGroup(lines.at(i)), opCode.at(getSecondGroup(lines.at(i)))))
                    {
                        addressingCounter += getThirdGroup(lines.at(i)).size();
                    }
                }
            }
            else if (getSecondGroup(lines.at(i)).compare("END") == 0)
            {
            }
        }
    }
    /*smatch match;
    string sp("LDA ZERO");
    if (regex_search(sp, match, r) == true)
    {
        if (match.str(5).compare(" "))
        {
            cout<<match.str(5).size();
            cout<<"\n";
            cout<<getHex("13");

        }
        //   cout<<match.str(1);
    }*/

    return 0;
}
