#include "passOneAlgorithm.h"

vector<string> namesOftable;
vector<string> absLabels;
int addressingCounter = 0;
string* returnedArray;
bool startVisited = false;
bool endVisited = false;
int length;
vector<int> numOfError;
vector<string> typeOfError;
map<string,int> symbolTable;
int *addresses;
passOneAlgorithm::passOneAlgorithm()
{
    //ctor
}
void passOneAlgorithm::setLength(int l)
{
    length = l;
    addresses = new int[l];
}
map<string,int> passOneAlgorithm::getSymbolTable()
{
    return symbolTable;
}
vector<string> passOneAlgorithm::getTypeOfError()
{
    return typeOfError;
}
vector<int> passOneAlgorithm::getNumOfError()
{
    return numOfError;
}
int* passOneAlgorithm::getAdresses()
{
    return addresses;
}
vector<string> passOneAlgorithm::getNamesOfTable()
{
    return namesOftable;
}
vector<string> passOneAlgorithm::getAbsLabels()
{
    return absLabels;
}
void passOneAlgorithm::doPass(vector<string>lines,map<string,string> opCodeSecondFormat,map<string,string> opCodeThirdForth,map<string,string> opCodeDirectives)
{
    passOne one;
    for (unsigned int i = 0; i < lines.size(); i++)
    {
        if (!one.commentChecker(lines.at(i)))
        {
            returnedArray = one.checkingGeneralRegex(lines.at(i));
            one.toUpper(returnedArray[2]);
            if (returnedArray[2].compare("START") == 0)
            {
                if (!startVisited)
                {
                    startVisited = true;
                    if (one.checkingOpRegex(returnedArray[3], opCodeDirectives.at("START")))
                    {
                        addressingCounter = one.getHex(returnedArray[3]);
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
            else if (returnedArray[2].compare("END") != 0)
            {
                if (returnedArray[1].compare("") != 0)
                {
                    if (namesOftable.size() == 0)
                    {
                        string t = returnedArray[1];
                        one.toLower(t);
                        namesOftable.push_back(t);
                        symbolTable[t] = addressingCounter;
                    }
                    else
                    {
                        string t = returnedArray[1];
                        one.toLower(t);
                        if ( std::find(namesOftable.begin(), namesOftable.end(), t) != namesOftable.end() )
                        {
                            numOfError.push_back(i);
                            typeOfError.push_back("duplicate label definition");
                        }
                        else
                        {
                            string t = returnedArray[1];
                            one.toLower(t);
                            namesOftable.push_back(t);
                            symbolTable[t] = addressingCounter;
                        }
                    }
                }
                if (returnedArray[2].compare("WORD") == 0)
                {
                    if (one.checkingOpRegex(returnedArray[3], opCodeDirectives.at("WORD")))
                    {
                        addresses[i] = addressingCounter;
                        int increament;
                        std::size_t found = returnedArray[3].find(",");
                        if(found!=std::string::npos)
                            increament = returnedArray[3].length() - static_cast<int>(returnedArray[3].length()/2);
                        else
                            increament = 3;
                        addressingCounter =addressingCounter + increament;
                    }
                    else
                    {
                        numOfError.push_back(i);
                        typeOfError.push_back("illegal operand");
                        addresses[i] = addressingCounter;
                        addressingCounter += 3;
                    }
                }
                else if (returnedArray[2].compare("RESW") == 0)
                {
                    if (one.checkingOpRegex(returnedArray[3], opCodeDirectives.at("RESW")))
                    {
                        addresses[i] = addressingCounter;

                        if (one.expressionChecker(returnedArray[3]))
                        {
                            string* arr = one.getExpressionGroup(returnedArray[3]);

                            int* flag = one.expressionEvaluator(arr[0], arr[2], arr[1], absLabels, symbolTable, namesOftable);

                            if (flag[0] == -2)
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("undefined label in operand");
                            }
                            else if (flag[0] == -1)
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("illegal expression");
                            }
                            else
                            {
                                addressingCounter += 3 * flag[0];

                            }
                        }
                        else if(one.strIsDigit(returnedArray[3]))
                            addressingCounter += 3 * one.getInt(returnedArray[3]);
                        else
                            addressingCounter = addressingCounter + 3;
                    }
                    else
                    {
                        numOfError.push_back(i);
                        typeOfError.push_back("illegal operand");
                        addresses[i] = addressingCounter;
                    }
                }
                else if (returnedArray[2].compare("RESB") == 0)
                {
                    if (one.checkingOpRegex(returnedArray[3], opCodeDirectives.at("RESB")))
                    {
                        addresses[i] = addressingCounter;

                        if (one.expressionChecker(returnedArray[3]))
                        {
                            string* arr = one.getExpressionGroup(returnedArray[3]);

                            int* flag = one.expressionEvaluator(arr[0], arr[2], arr[1], absLabels, symbolTable, namesOftable);

                            if (flag[0] == -2)
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("undefined label in operand");
                            }
                            else if (flag[0] == -1)
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("illegal expression");
                            }
                            else
                            {
                                addressingCounter += flag[0];

                            }
                        }
                        else if (one.strIsDigit(returnedArray[3]))
                            addressingCounter += one.getInt(returnedArray[3]);
                    }
                    else
                    {
                        numOfError.push_back(i);
                        typeOfError.push_back("illegal operand");
                        addresses[i] = addressingCounter;
                    }
                }
                else if (returnedArray[2].compare("BYTE") == 0)
                {
                    if (one.checkingOpRegex(returnedArray[3], opCodeDirectives.at("BYTE")))
                    {
                        addresses[i] = addressingCounter;
                        if(returnedArray[3].at(0) == 'x' ||returnedArray[3].at(0) == 'X')
                        {
                            if((returnedArray[3].length() - 3) % 2 == 0)
                            {
                                addressingCounter += (returnedArray[3].length() - 3)/2;
                            }
                            else
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("odd length for hex string");
                                addresses[i] = addressingCounter;
                            }
                        }
                        else
                        {
                            addressingCounter += (returnedArray[3].length() - 3);
                        }
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
                        if(opCodeSecondFormat.find(returnedArray[2]) != opCodeSecondFormat.end())
                        {
                            if (one.checkingOpRegex(returnedArray[3], opCodeSecondFormat.at(returnedArray[2])))
                            {
                                addresses[i] = addressingCounter;
                                addressingCounter += 2;
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
                            numOfError.push_back(i);
                            typeOfError.push_back("illegal second format");
                            addresses[i] = addressingCounter;
                            addressingCounter += 3;
                        }
                    }
                    else if (returnedArray[0].compare("3") == 0 || returnedArray[0].compare("4") == 0)
                    {
                        string opp = returnedArray[2];
                        one.toUpper(opp);
                        if (opp.compare("ORG") == 0)
                        {
                            if (returnedArray[3].compare("") != 0)
                            {
                                if (one.expressionChecker(returnedArray[3]))
                                {
                                    string* arr = one.getExpressionGroup(returnedArray[3]);

                                    int* flag = one.expressionEvaluator(arr[0], arr[2], arr[1], absLabels, symbolTable, namesOftable);

                                    if (flag[0] == -2)
                                    {
                                        numOfError.push_back(i);
                                        typeOfError.push_back("undefined label in operand");
                                        addresses[i] = addressingCounter;
                                    }
                                    else if (flag[0] == -1)
                                    {
                                        numOfError.push_back(i);
                                        typeOfError.push_back("illegal expression");
                                        addresses[i] = addressingCounter;
                                    }
                                    else
                                    {
                                        addresses[i] = addressingCounter;
                                        addressingCounter = flag[0];

                                    }
                                }
                                else if (!one.IsHex(returnedArray[3]))
                                {
                                    string t = returnedArray[3];
                                    one.toLower(t);
                                    if ( std::find(namesOftable.begin(), namesOftable.end(), t) != namesOftable.end() )
                                    {
                                        if(returnedArray[3].compare("*") != 0)
                                        {
                                            addresses[i] = addressingCounter;
                                            addressingCounter = symbolTable.at(t);
                                        }
                                        else
                                        {
                                            addresses[i] = addressingCounter;
                                        }
                                    }
                                    else
                                    {
                                        numOfError.push_back(i);
                                        typeOfError.push_back("undefined symbol in operand");
                                        addresses[i] = addressingCounter;
                                        addressingCounter = 0;
                                    }
                                }
                                else
                                {
                                    addresses[i] = addressingCounter;
                                    addressingCounter = one.getHex(returnedArray[3]);
                                }
                            }
                            else
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("missing operand field!");
                                addresses[i] = addressingCounter;
                                addressingCounter = 0;
                            }

                        }
                        else if (opp.compare("EQU") == 0)
                        {
                            if (returnedArray[1].compare("") != 0)
                            {
                                if (returnedArray[3].compare("") != 0)
                                {
                                    if (one.expressionChecker(returnedArray[3]))
                                    {
                                        string* arr = one.getExpressionGroup(returnedArray[3]);

                                        int* flag = one.expressionEvaluator(arr[0], arr[2], arr[1], absLabels, symbolTable, namesOftable);

                                        if (flag[0] == -2)
                                        {
                                            numOfError.push_back(i);
                                            typeOfError.push_back("undefined label in operand");
                                            addresses[i] = addressingCounter;
                                        }
                                        else if (flag[0] == -1)
                                        {
                                            numOfError.push_back(i);
                                            typeOfError.push_back("illegal expression");
                                            addresses[i] = addressingCounter;
                                        }
                                        else
                                        {
                                            addresses[i] = addressingCounter;
                                            string l = returnedArray[1];
                                            one.toLower(l);
                                            symbolTable[l] = flag[0];

                                            if (flag[1] == 0)
                                            {
                                                absLabels.push_back(l);
                                            }

                                        }
                                    }
                                    else if (!one.IsHex(returnedArray[3]))
                                    {
                                        string t = returnedArray[3];
                                        one.toLower(t);
                                        if ( std::find(namesOftable.begin(), namesOftable.end(), t) != namesOftable.end() )
                                        {
                                            addresses[i] = addressingCounter;
                                            string opCode = returnedArray[1];
                                            one.toLower(opCode);
                                            symbolTable[opCode] = symbolTable.at(t);
                                        }
                                        else
                                        {
                                            numOfError.push_back(i);
                                            typeOfError.push_back("undefined symbol in operand");
                                            addresses[i] = addressingCounter;
                                        }
                                    }
                                    else
                                    {
                                        addresses[i] = addressingCounter;
                                        string opCode = returnedArray[1];
                                        one.toLower(opCode);
                                        symbolTable[opCode] = one.getHex(returnedArray[3]);
                                        absLabels.push_back(opCode);
                                    }
                                }
                                else
                                {
                                    numOfError.push_back(i);
                                    typeOfError.push_back("this statement requires an operand");
                                    addresses[i] = addressingCounter;
                                }
                            }
                            else
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("this statement requires a label");
                                addresses[i] = addressingCounter;
                            }
                        }
                        else if(opp.compare("BASE") == 0)
                        {
                            if(returnedArray[1].compare("")==0)
                            {
                                if(one.checkingOpRegex(returnedArray[3], opCodeDirectives.at("BASE")))
                                {
                                    addresses[i] = addressingCounter;
                                }
                                else
                                {
                                    numOfError.push_back(i);
                                    typeOfError.push_back("illegal operation");
                                    addresses[i] = addressingCounter;
                                }
                            }
                            else
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("this statement can't have a label");
                                addresses[i] = addressingCounter;
                            }
                        }
                        else if(opp.compare("NOBASE") == 0)
                        {
                            if(returnedArray[1].compare("")==0)
                            {
                                if(one.checkingOpRegex(returnedArray[3], opCodeDirectives.at("NOBASE")))
                                {
                                    addresses[i] = addressingCounter;
                                }
                                else
                                {
                                    numOfError.push_back(i);
                                    typeOfError.push_back("this statement can't have operand");
                                    addresses[i] = addressingCounter;
                                }
                            }
                            else
                            {
                                numOfError.push_back(i);
                                typeOfError.push_back("this statement can't have a label");
                                addresses[i] = addressingCounter;
                            }
                        }
                        else
                        {
                            if(opCodeThirdForth.find(returnedArray[2]) != opCodeThirdForth.end())
                            {
                                if (one.checkingOpRegex(returnedArray[3], opCodeThirdForth.at(opp)))
                                {
                                    addresses[i] = addressingCounter;
                                    addressingCounter += one.getHex(returnedArray[0]);
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
                                numOfError.push_back(i);
                                typeOfError.push_back("illegal operation");
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
            else if (returnedArray[2].compare("END") == 0)
            {
                if(!endVisited)
                {
                    if (returnedArray[3].compare("") == 0)
                    {
                        if (returnedArray[1].compare("") != 0)
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
                        addressingCounter--;
                    }
                    else
                    {
                        if ( std::find(namesOftable.begin(), namesOftable.end(), returnedArray[3]) != namesOftable.end() )
                        {
                            numOfError.push_back(i);
                            typeOfError.push_back("undefined symbol in operand");
                        }
                        if (returnedArray[1].compare("") != 0)
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
                        addressingCounter--;

                    }
                    endVisited = true;
                }
                else
                {
                    numOfError.push_back(i);
                    typeOfError.push_back("statement should not follow END statement");
                    addresses[i] = addressingCounter;
                }
            }
            else if (returnedArray[2].compare("-1") == 0)
            {
                numOfError.push_back(i);
                typeOfError.push_back("unrecognized operation code");
                addresses[i] = addressingCounter;
            }
            startVisited = true;
        }
    }
    if(!endVisited)
    {
        numOfError.push_back(lines.size()-1);
        typeOfError.push_back("missing end statement!");
    }
}
