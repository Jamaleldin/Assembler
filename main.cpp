#include <iostream>
#include <bits/stdc++.h>
#include <regex>

using namespace std;

string* checkingGeneralRegex (string line)
{
    regex secondFormat("^\\s*([^\\s.@#]{1,8}\\s+){0,1}?([a-z]{1,6})\\s+([ABLSTX]\\s*,\\s*[ABLSTX])\\s*$",std::regex_constants::icase);
    regex thirdFormat("^\\s*([^\\s.@#]{1,8}\\s+){0,1}?([a-z]{1,6})\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    regex forthFormat("^\\s*([^\\s.@#]{1,8}\\s+){0,1}?((\\+)([a-z]{1,5}))\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    regex returnSub("^\\s*([^\\s.@#]{1,8}?\\s+){0,1}?((\\+)?(rsub))\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    regex endProg("^\\s*([^\\s.@#]{1,8}?\\s+){0,1}?(end)\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    regex startProg("^\\s*([^\\s.@#]{1,8}?\\s+){1}(start)\\s+([a-f0-9]{1,18})\\s*(\\..{0,31})*?\\s*$",std::regex_constants::icase);
    string* data = new string[4];
    smatch match;

    if(regex_search(line, match, startProg) == true)
    {
        data[0] = "0";
        data[1] = match.str(1);
        data[2] = match.str(2);
        data[3] = match.str(3);
    }
    else if(regex_search(line, match, endProg) == true)
    {
        data[0] = "0";
        data[1] = match.str(1);
        data[2] = match.str(2);
        data[3]= " ";
    }
    else if(regex_search(line, match, returnSub) == true)
    {
        if (match.str(3) != " ")
        {
            data[0] = "4";
        }
        else
        {
            data[0] = "3";
        }
        data[1] = match.str(1);
        data[2] = match.str(4);
        data[3] = " ";
    }
    else if(regex_search(line, match, secondFormat) == true)
    {
        data[0] = "2";
        data[1] = match.str(1);
        data[2] = match.str(2);
        data[3] = match.str(3);
    }
    else if(regex_search(line, match, thirdFormat) == true)
    {
        data[0] = "3";
        data[1] = match.str(1);
        data[2] = match.str(2);
        data[3] = match.str(6);
    }
    else if(regex_search(line, match, forthFormat) == true)
    {
        data[0] = "4";
        data[1] = match.str(1);
        data[2] = match.str(4);
        data[3] = match.str(9);

    }
    else
    {
        data[0] = "-1";
        data[1] = "-1";
        data[2] = "-1";
        data[3] = "-1";

        return data;
    }
    return data;
}

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
    // Map for second format
    map<string,string> opCodeSecondFormat;
    opCodeSecondFormat["ADDR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    opCodeSecondFormat["CLEAR"] = "^[ABLSTX]$";
    opCodeSecondFormat["COMPR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    opCodeSecondFormat["DIVR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    opCodeSecondFormat["MULR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    opCodeSecondFormat["RMO"] = "^[ABLSTX]\\,[ABLSTX]$}";
    opCodeSecondFormat["SUBR"] = "^[ABLSTX]\\,[ABLSTX]$}";
    opCodeSecondFormat["TIXR"] = "^[ABLSTX]$}";

    // Map for third & forth format
    map<string,string> opCodeThirdForth;
    opCodeThirdForth["START"] = "^[a-fA-F0-9]{1,18}$";
    opCodeThirdForth["ADD"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["COMP"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["DIV"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["J"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["JEQ"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["JLT"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["JGT"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["JSUB"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["LDA"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["LDB"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["LDCH"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["LDL"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["LDS"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["LDT"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["LDX"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["MUL"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["RSUB"] = "^$";
    opCodeThirdForth["STA"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["STB"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["STCH"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["STL"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["STS"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["STT"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["STX"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["SUB"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["RD"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["TD"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["WD"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["TIX"] = "^((\\@[a-zA-Z0-9]{1,17})|(\\#[a-zA-Z0-9]{1,17})|([a-zA-Z0-9]{1,18}))$";
    opCodeThirdForth["BYTE"] = "^(((?i)[X]\\'[a-fA-F0-9]{0,15}\\')|((?i)[C]\\'[a-zA-Z0-9]{0,15}\\'))$";
    opCodeThirdForth["RESB"] = "^[0-9]{1,18}$";
    opCodeThirdForth["WORD"] = "^[0-9]{1,18}$";
    opCodeThirdForth["RESW"] = "^[0-9]{1,18}$";
    opCodeThirdForth["END"] = "^$";

    /*READING FROM FILE
    ===================*/
    ifstream inputFile("input.txt");
    vector<string> lines;
    if(inputFile.is_open())
    {
        string line;
        while(getline(inputFile,line))
        {
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
