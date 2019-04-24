#include <iostream>
#include <bits/stdc++.h>
#include <regex>

using namespace std;

string* checkingGeneralRegex (string line)
{
    std::regex secondFormate("^\\s*(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+([ABLSTX]\\s*,\\s*[ABLSTX])\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex thirdFormate("^\\s*(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex forthFormate("^\\s*(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+){0,1}?((\\+)([a-zA-Z]{1,5}))\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex returnSub("^\\s*(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+){0,1}?((\\+)?(rsub))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex endProg("^\\s*(end)(\\s+(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18})))?\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    regex startProg("^\\s*(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+){0,1}?(start)\\s+([a-f0-9]{1,18})\\s*(\\..*)?\\s*$",std::regex_constants::icase);
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
    string operandCommonRegex = "^(((@|#)([^\\s,.@#*]{1,17}))|([^\\s,.@#*]{1,18})|(([^\\s.@#*]{1,16})\\,(x)))$";
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
    opCodeThirdForth["ADD"] = operandCommonRegex;
    opCodeThirdForth["COMP"] = operandCommonRegex;
    opCodeThirdForth["DIV"] = operandCommonRegex;
    opCodeThirdForth["J"] = "^\\s*((([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+)|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))\\s*$";
    opCodeThirdForth["JEQ"] = "^\\s*((([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+)|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))\\s*$";
    opCodeThirdForth["JLT"] = "^\\s*((([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+)|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))\\s*$";
    opCodeThirdForth["JGT"] = "^\\s*((([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+)|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))\\s*$";
    opCodeThirdForth["JSUB"] = "^\\s*((([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+)|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))\\s*$";
    opCodeThirdForth["LDA"] = operandCommonRegex;
    opCodeThirdForth["LDB"] = operandCommonRegex;
    opCodeThirdForth["LDCH"] = operandCommonRegex;
    opCodeThirdForth["LDL"] = operandCommonRegex;
    opCodeThirdForth["LDS"] = operandCommonRegex;
    opCodeThirdForth["LDT"] = operandCommonRegex;
    opCodeThirdForth["LDX"] = operandCommonRegex;
    opCodeThirdForth["MUL"] = operandCommonRegex;
    opCodeThirdForth["RSUB"] = "^\\s*(\\..*)?\\s*$";
    opCodeThirdForth["STA"] = operandCommonRegex;
    opCodeThirdForth["STB"] = operandCommonRegex;
    opCodeThirdForth["STCH"] = operandCommonRegex;
    opCodeThirdForth["STL"] = operandCommonRegex;
    opCodeThirdForth["STS"] = operandCommonRegex;
    opCodeThirdForth["STT"] = operandCommonRegex;
    opCodeThirdForth["STX"] = operandCommonRegex;
    opCodeThirdForth["SUB"] = operandCommonRegex;
    opCodeThirdForth["RD"] = "^(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18})|([X]\\'[a-fA-F0-9]{0,14}\\'))$";
    opCodeThirdForth["TD"] = "^(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18})|([X]\\'[a-fA-F0-9]{0,14}\\'))$";
    opCodeThirdForth["WD"] = "^(((@|#)([^\\s.@#]{1,17}))|([^\\s.@#]{1,18})|([X]\\'[a-fA-F0-9]{0,14}\\'))$";
    opCodeThirdForth["TIX"] = operandCommonRegex;
    opCodeThirdForth["BYTE"] = "^(([X]\\'[a-fA-F0-9]{0,14}\\')|([C]\\'[a-zA-Z0-9]{0,15}\\'))$";
    opCodeThirdForth["RESB"] = "^[0-9]{1,18}$";
    opCodeThirdForth["WORD"] = "^(([0-9]{1,18})|((#|@)([0-9]{1,17}))|(([0-9])(\\,)?))$";
    opCodeThirdForth["RESW"] = "^[0-9]{1,18}$";
    opCodeThirdForth["END"] =  "^\\s*((([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+)|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))\\s*$";
    opCodeThirdForth["ORG"] = "^((\\w+)|(\\*))$";

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
    return 0;
}
