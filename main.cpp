#include <iostream>
#include <bits/stdc++.h>
#include <regex>
#include <algorithm>
#include <vector>

using namespace std;

string* checkingGeneralRegex (string line)
{
    std::regex secondFormat("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+([ABLSTX]\\s*(,\\s*[ABLSTX])?)\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex thirdFormat("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+(((@|#)([a-zA-Z0-9]{1,17}))|([^\\s.@#*]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex forthFormat("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?((\\+)([a-zA-Z]{1,5}))\\s+(((@|#)([a-zA-Z0-9]{1,17}))|([^\\s.@#*]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex returnSub("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?((\\+)?(rsub))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    std::regex endProg("^\\s*(end)(\\s+((\\*)|([a-zA-Z]{1}[a-zA-Z0-9]{1,17})|((@|#)([a-zA-Z]{1}[a-zA-Z0-9]{1,16}))))?\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    regex startProg("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?(start)\\s+([a-f0-9]{1,18})\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    string* data = new string[4];
    string sp (line);
    smatch match;

    if(regex_search(sp, match, startProg) == true)
    {
        data[0] = "0";
        data[1] = match.str(2);
        data[2] = match.str(3);
        data[3] = match.str(4);
    }
    else if(regex_search(sp, match, endProg) == true)
    {
        data[0] = "0";
        data[1] = " ";
        data[2] = match.str(1);
        data[3]= match.str(3);
    }
    else if(regex_search(sp, match, returnSub) == true)
    {
        if (match.str(4) != " ")
        {
            data[0] = "4";
        }
        else
        {
            data[0] = "3";
        }
        data[1] = match.str(2);
        data[2] = match.str(5);
        data[3] = " ";
    }
    else if(regex_search(sp, match, secondFormat) == true)
    {
        data[0] = "2";
        data[1] = match.str(2);
        data[2] = match.str(3);
        data[3] = match.str(4);
    }
    else if(regex_search(sp, match, thirdFormat) == true)
    {
        data[0] = "3";
        data[1] = match.str(2);
        data[2] = match.str(3);
        if (match.str(6) != " ")
        {
            data[3] = match.str(7);
        }
        else
        {
            data[3] = match.str(8);
        }

    }
    else if(regex_search(sp, match, forthFormat) == true)
    {
        data[0] = "4";
        data[1] = match.str(2);
        data[2] = match.str(5);
        if (match.str(8) != " ")
        {
            data[3] = match.str(9);
        }
        else
        {
            data[3] = match.str(10);
        }

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

bool checkingOpRegex(string line, string reg)
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

void toUpper(basic_string<char>& s)
{
    for (basic_string<char>::iterator p = s.begin();
            p != s.end(); ++p)
    {
        *p = toupper(*p); // toupper is for char
    }
}

int main()
{
    string operandCommonRegex = "^(((@|#)(([a-zA-Z0-9]{1,17})))|(([a-zA-Z]{1}[a-zA-Z0-9]{1,17}))|((([a-zA-Z]{1}[a-zA-Z0-9]{0,15}))\\s*\\,\\s*(x)))$";
    /*Map for second format
    ========================*/
    map<string,string> opCodeSecondFormat;
    opCodeSecondFormat["ADDR"] = "^[ABLSTX]\\s*\\,\\s*[ABLSTX]$";
    opCodeSecondFormat["CLEAR"] = "^[ABLSTX]\\s*$";
    opCodeSecondFormat["COMPR"] = "^[ABLSTX]\\s*\\,\\s*[ABLSTX]$";
    opCodeSecondFormat["DIVR"] = "^[ABLSTX]\\s*\\,\\s*[ABLSTX]$";
    opCodeSecondFormat["MULR"] = "^[ABLSTX]\\s*\\,\\s*[ABLSTX]$";
    opCodeSecondFormat["RMO"] = "^[ABLSTX]\\s*\\,\\s*[ABLSTX]$";
    opCodeSecondFormat["SUBR"] = "^[ABLSTX]\\s*\\,\\s*[ABLSTX]$";
    opCodeSecondFormat["TIXR"] = "^[ABLSTX]\\s*$";

    /*Map for third & forth format
    ==============================*/
    map<string,string> opCodeThirdForth;
    opCodeThirdForth["ADD"] = operandCommonRegex;
    opCodeThirdForth["COMP"] = operandCommonRegex;
    opCodeThirdForth["DIV"] = operandCommonRegex;
    opCodeThirdForth["J"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7})\\s+)|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))$";
    opCodeThirdForth["JEQ"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))$";
    opCodeThirdForth["JLT"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))$";
    opCodeThirdForth["JGT"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))$";
    opCodeThirdForth["JSUB"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))$";
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
    opCodeThirdForth["RD"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,17}))|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,16})))|([X]\\'[a-fA-F0-9]{0,14}\\'))$";
    opCodeThirdForth["TD"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,17}))|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,16})))|([X]\\'[a-fA-F0-9]{0,14}\\'))$";
    opCodeThirdForth["WD"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,17}))|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,16})))|([X]\\'[a-fA-F0-9]{0,14}\\'))$";
    opCodeThirdForth["TIX"] = operandCommonRegex;
    opCodeThirdForth["BYTE"] = "^(([X]\\'[a-fA-F0-9]{0,14}\\')|([C]\\'[a-zA-Z0-9]{0,15}\\'))$";
    /*Map for directives
    ====================*/
    map<string,string> opCodeDirectives;
    opCodeDirectives["START"] = "^[a-fA-F0-9]{1,18}$";
    opCodeDirectives["END"] =  "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))$";
    opCodeDirectives["RESB"] = "^[0-9]{1,18}$";
    opCodeDirectives["WORD"] = "^(([0-9]{1,4})|((#|@|-)([0-9]{1,4}))|(([0-9])(\\,)?)|(([a-zA-Z]{1})([a-zA-Z0-9]{1,7})))$";
    opCodeDirectives["RESW"] = "^[0-9]{1,4}$";
    opCodeDirectives["EQU"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(([a-zA-Z0-9])(\\+|-)([a-zA-Z0-9])))$";
    opCodeDirectives["ORG"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(([a-zA-Z0-9])(\\+|-)([a-zA-Z0-9])))$";
    opCodeDirectives["BASE"] = "^(([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(\\*)$";
    opCodeDirectives["NOBASE"] = "^$";

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
    for(int i=0;i<lines.size();i++){
        cout<<lines.at(i)<<endl;
    }
    int length = lines.size();
    vector<int> numOfError;
    vector<string> typeOfError;
    map<string,int> symbolTable;
    vector<string> namesOftable;
    int *addresses = new int[length];
    int i = 0;
    int addressingCounter = 0;
    string * returnedArray;
    for (i = 0; i < lines.size(); i++)
    {
        if (!commentChecker(lines.at(i)))
        {
            returnedArray = checkingGeneralRegex(lines.at(i));
            if (returnedArray[2].compare("start") == 0)
            {
                if (i == 0)
                {
                    if (checkingOpRegex(returnedArray[3], opCodeThirdForth.at("START")))
                    {
                        addressingCounter = getHex(returnedArray[3]);
                        addresses[i] = addressingCounter;
                    }
                    else
                    {
                        numOfError.push_back(i);
                        typeOfError.push_back("illegal operand");
                        addresses[i] = addressingCounter;
                    }
                }
                else
                {
                    numOfError.push_back(i);
                    typeOfError.push_back("duplicate or misplaced START statement");
                    addresses[i] = addressingCounter;
                }

            }
            else if (returnedArray[2].compare("end") != 0)
            {
                if (returnedArray[1].compare(" ") != 0)
                {
                    if (namesOftable.size() == 0)
                    {
                        namesOftable.push_back(returnedArray[1]);
                        symbolTable[returnedArray[1]] = addressingCounter;
                    }
                    else
                    {
                        if ( std::find(namesOftable.begin(), namesOftable.end(), returnedArray[1]) != namesOftable.end() )
                        {
                            numOfError.push_back(i);
                            typeOfError.push_back("duplicate label definition");
                        }
                        else
                        {
                            namesOftable.push_back(returnedArray[1]);
                            symbolTable[returnedArray[1]] = addressingCounter;
                        }
                    }
                }
                string op = returnedArray[2];

                if (op.compare("word") == 0)
                {
                    if (checkingOpRegex(returnedArray[3], opCodeThirdForth.at("WORD")))
                    {
                        addresses[i] = addressingCounter;
                        addressingCounter += 3;
                    }
                    else
                    {
                        numOfError.push_back(i);
                        typeOfError.push_back("illegal operand");
                        addresses[i] = addressingCounter;
                        addressingCounter += 3;
                    }
                }
                else if (op.compare("resw") == 0)
                {
                    if (checkingOpRegex(returnedArray[3], opCodeThirdForth.at("RESW")))
                    {
                        addresses[i] = addressingCounter;
                        addressingCounter += 3 * getHex(returnedArray[3]);
                    }
                    else
                    {
                        numOfError.push_back(i);
                        typeOfError.push_back("illegal operand");
                        addresses[i] = addressingCounter;
                        addressingCounter += 3;
                    }
                }
                else if (op.compare("resb") == 0)
                {
                    if (checkingOpRegex(returnedArray[3], opCodeThirdForth.at("RESB")))
                    {
                        addresses[i] = addressingCounter;
                        addressingCounter += getHex(returnedArray[3]);
                    }
                    else
                    {
                        numOfError.push_back(i);
                        typeOfError.push_back("illegal operand");
                        addresses[i] = addressingCounter;
                        addressingCounter += 3;
                    }
                }
                else if (op.compare("byte") == 0)
                {
                    if (checkingOpRegex(returnedArray[3], opCodeThirdForth.at("BYTE")))
                    {
                        addresses[i] = addressingCounter;
                        addressingCounter += returnedArray[3].size() - 3;
                    }
                    else
                    {
                        numOfError.push_back(i);
                        typeOfError.push_back("illegal operand");
                        addresses[i] = addressingCounter;
                        addressingCounter += 3;
                    }
                }
                else
                {
                    if (returnedArray[0].compare("2") == 0)
                    {
                        if (checkingOpRegex(returnedArray[3], opCodeSecondFormat.at(returnedArray[2])))
                        {
                            addresses[i] = addressingCounter;
                            addressingCounter += getHex(returnedArray[0]);
                        }
                        else
                        {
                            numOfError.push_back(i);
                            typeOfError.push_back("illegal operand");
                            addresses[i] = addressingCounter;
                            addressingCounter += 3;
                        }
                    }
                    else if (returnedArray[0].compare("3") == 0 || returnedArray[0].compare("4") == 0)
                    {
                        string opp = returnedArray[2];
                        toUpper(opp);
                        if (checkingOpRegex(returnedArray[3], opCodeThirdForth.at(opp)))
                        {
                            addresses[i] = addressingCounter;
                            addressingCounter += getHex(returnedArray[0]);
                        }
                        else
                        {
                            numOfError.push_back(i);
                            typeOfError.push_back("illegal operand");
                            addresses[i] = addressingCounter;
                            addressingCounter += 3;
                        }
                    }
                }
            }
            else if (returnedArray[2].compare("END") == 0)
            {
                if (returnedArray[3].compare(" ") == 0)
                {
                    if (returnedArray[1].compare(" ") != 0)
                    {
                        if (namesOftable.size() == 0)
                        {
                            namesOftable.push_back(returnedArray[1]);
                            symbolTable[returnedArray[1]] = addressingCounter;
                        }
                        else
                        {
                            if ( std::find(namesOftable.begin(), namesOftable.end(), returnedArray[1]) != namesOftable.end() )
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("duplicate label definition");
                            }
                            else
                            {
                                namesOftable.push_back(returnedArray[1]);
                                symbolTable[returnedArray[1]] = addressingCounter;
                            }
                        }
                    }
                    addresses[i] = addressingCounter;
                }
                else
                {
                    if ( std::find(namesOftable.begin(), namesOftable.end(), returnedArray[3]) != namesOftable.end() )
                    {
                        numOfError.push_back(i);
                        typeOfError.push_back("undefined symbol in operand");
                    }
                    if (returnedArray[3].compare(" ") == 0)
                    {
                        if (returnedArray[1].compare(" ") != 0)
                        {
                            if (namesOftable.size() == 0)
                            {
                                namesOftable.push_back(returnedArray[1]);
                                symbolTable[returnedArray[1]] = addressingCounter;
                            }
                            else
                            {
                                if ( std::find(namesOftable.begin(), namesOftable.end(), returnedArray[1]) != namesOftable.end() )
                                {
                                    numOfError.push_back(i);
                                    typeOfError.push_back("duplicate label definition");
                                }
                                else
                                {
                                    namesOftable.push_back(returnedArray[1]);
                                    symbolTable[returnedArray[1]] = addressingCounter;
                                }
                            }
                        }
                        addresses[i] = addressingCounter;
                    }
                }
            }
                else if (returnedArray[2].compare("-1") == 0)
                {
                    numOfError.push_back(i);
                    typeOfError.push_back("unrecognized operation code");
                    addresses[i] = addressingCounter;
                }
            }
        }
        for (i = 0; i < lines.size(); i ++)
        {
            cout<<addresses[i];
            cout<<"\n";
        }

        delete [] addresses;
        return 0;
    }
