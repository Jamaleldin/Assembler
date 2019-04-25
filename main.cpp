#include <iostream>
#include <bits/stdc++.h>
#include <regex>
#include <algorithm>
#include <vector>

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
    string sp (line);
    smatch match;

    if(regex_search(sp, match, startProg) == true)
    {
        data[0] = "0";
        data[1] = match.str(1);
        data[2] = match.str(2);
        data[3] = match.str(3);
    }
    else if(regex_search(sp, match, endProg) == true)
    {
        data[0] = "0";
        data[1] = match.str(1);
        data[2] = match.str(2);
        data[3]= " ";
    }
    else if(regex_search(sp, match, returnSub) == true)
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
    else if(regex_search(sp, match, secondFormat) == true)
    {
        data[0] = "2";
        data[1] = match.str(1);
        data[2] = match.str(2);
        data[3] = match.str(3);
    }
    else if(regex_search(sp, match, thirdFormat) == true)
    {
        data[0] = "3";
        data[1] = match.str(1);
        data[2] = match.str(2);
        data[3] = match.str(7);
    }
    else if(regex_search(sp, match, forthFormat) == true)
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
        /* string * finalArrayP;
         finalArrayP = checkingGeneralRegex("sta buffer");

         for (int i = 0; i < 4; i++){
             cout<<finalArrayP[i];
         }*/

        return 0;
    }
