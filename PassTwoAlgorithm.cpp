#include "PassTwoAlgorithm.h"
#include <cstring>
#include <sstream>

passOne parser;
vector<string> abslabels;
vector<string> namesOfTable;
vector<string> errors;
vector<int> lineOferrors;
PassTwoAlgorithm::PassTwoAlgorithm()
{
    //ctor
}
vector<string> PassTwoAlgorithm::getErrors()
{
    return errors;
}
vector<int> PassTwoAlgorithm::getLinesOfErrors()
{
    return lineOferrors;
}
void PassTwoAlgorithm::setAbsLabels(vector<string> labels)
{
    abslabels = labels;
}
void PassTwoAlgorithm::setNamesOfTables(vector<string> names)
{
    namesOfTable = names;
}
bool PassTwoAlgorithm::endWith(string const &fullString, string const &ending)
{
    if (fullString.length() >= ending.length())
    {
        return (0
                == fullString.compare(fullString.length() - ending.length(),
                                      ending.length(), ending));
    }
    else
    {
        return false;
    }
}

int PassTwoAlgorithm::getInt(string s)
{
    int i = std::atoi(s.c_str());
    return i;
}
bool PassTwoAlgorithm::strIsDigit(string s)
{
    unsigned int numOfdigits = 0;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (isdigit(s.at(i)))
            numOfdigits++;
    }
    return numOfdigits == s.length();
}

void PassTwoAlgorithm::decimalToBinary(int decimal, string& binary)
{
    int bitLocation = binary.length() - 1;
    for (int i = 0; decimal > 0; i++)
    {
        int bit = decimal % 2;
        char cBit = (bit == 0) ? '0' : '1';
        binary.at(bitLocation) = cBit;
        bitLocation--;
        decimal = decimal / 2;
    }
}

bool PassTwoAlgorithm::getE(bool flags[])
{
    return flags[5];
}
bool PassTwoAlgorithm::getP(bool flags[])
{
    return flags[4];
}
bool PassTwoAlgorithm::getB(bool flags[])
{
    return flags[3];
}
bool PassTwoAlgorithm::getX(bool flags[])
{
    return flags[2];
}
bool PassTwoAlgorithm::getI(bool flags[])
{
    return flags[1];
}
bool PassTwoAlgorithm::getN(bool flags[])
{
    return flags[0];
}

void PassTwoAlgorithm::setE(string opCode, int format, bool flags[])
{
    bool bit = (format == 4) ? true : false;
    flags[5] = bit;
}

void PassTwoAlgorithm::getAddressFromSymbol(string opCode, string operand,
        map<string, int> &symTable, map<string, string> &registersTable,
        int format, int* address, string& operandBinary,
        bool* undefinedSymbolError, bool* invalidExpression, int programCounter)
{
    if (operand.at(0) == '@' || operand.at(0) == '#')
    {
        operand = operand.substr(1);
    }
    if ((endWith(operand, ",X") || endWith(operand, ",x")) && format != 2)
    {
        operand = operand.substr(0, operand.length() - 2);
    }
    if (operand == "")
    {
        *address = 0;
        return;
    }

    if (parser.expressionChecker(operand))
    {
        string* groups = parser.getExpressionGroup(operand);
        int* expression = parser.expressionEvaluator(groups[0], groups[2],
                          groups[1], abslabels, symTable, namesOfTable);
        if (expression[1] == -2)
        {
            *address = 0;
            *undefinedSymbolError = false;
            return;
        }
        else if (expression[1] == -1)
        {
            *invalidExpression = true;
            *address = 0; //invalid expression
            return;
        }
        else
        {
            *address = expression[0];
            if (format == 3)
            {
                operandBinary = "000000000000"; // will change in setBP
                return;

                return;
            }
            else if (format == 4)
            {
                operandBinary = "00000000000000000000";
                decimalToBinary(*address, operandBinary);
                return;
            }
        }
    }

    if (format == 2)
    {
        operandBinary = "00000000";
        string r1B = "";
        string r2B = "";
        if (opCode == "CLEAR" || opCode == "TIXR")
        {
            string r1 = "" + (operand.at(0));
            r1B = registersTable.at(r1);
            r2B = "0000"; //constant in this case

        }
        else
        {
            string r1(1,operand.at(0));
            string r2(1,operand.at(2));
            r1B = registersTable.at(r1); //values for example
            r2B = registersTable.at(r2);
        }
        operandBinary = r1B + r2B;
    }
    else if (format == 3)
    {
        operandBinary = "000000000000"; // will change in setBP

        if (strIsDigit(operand))
        {
            *address = getInt(operand);
        }
        else if (operand == "*")
        {
        	*address = programCounter;
        }
        else if (symTable.count(operand) == 0)
        {
            *address = 0;
            *undefinedSymbolError = true;
        }
        else
        {
            *address = symTable.at(operand);
        }

    }
    else if (format == 4)
    {
        operandBinary = "00000000000000000000";
        if (strIsDigit(operand))
        {
            *address = getInt(operand);
        }
        else if (operand == "*")
        {
        	*address = programCounter;
        }
        else if (symTable.count(operand) == 0)
        {
            *address = 0;
            *undefinedSymbolError = true;
        }
        else
        {
            *address = symTable.at(operand);
        }
        decimalToBinary(*address, operandBinary);
    }
}

void PassTwoAlgorithm::setBP(int format, int* address, string operand,
                             string& operandBinary, int programCounter, bool baseAvailable, int base,
                             bool* relativeAddressError, bool flags[])
{
    if (operand.at(0) == '@' || operand.at(0) == '#')
    {
        operand = operand.substr(1, operand.length() - 1);
    }
    *relativeAddressError = false;
    int absAddress = *address;
    if (format == 4)
    {
        flags[3] = false;
        flags[4] = false;
        *relativeAddressError = false;
    }
    else       //(format == 3)
    {
        if (strIsDigit(operand))
        {
            decimalToBinary(*address, operandBinary);
            *relativeAddressError = false;
            flags[4] = false;
            flags[5] = false;
            return;
        }
        *address = absAddress - programCounter;
        if (*address >= -2048 && *address <= 2047)
        {
            flags[3] = false;
            flags[4] = true;
            decimalToBinary(*address, operandBinary);
            *relativeAddressError = false;
        }
        else
        {
            if (baseAvailable)
            {
                *address = absAddress - base;
                if (*address >= 0 && *address <= 4095)
                {
                    flags[3] = true;
                    flags[4] = false;
                    decimalToBinary(*address, operandBinary);
                    *relativeAddressError = false;
                }
                else
                {
                    flags[4] = false;
                    flags[5] = false;
                    *address = 0;
                    *relativeAddressError = true; //error occured
                }
            }
            else
            {
                flags[4] = false;
                flags[5] = false;
                *address = 0;
                *relativeAddressError = true; //error occured
            }
        }

    }
}

void PassTwoAlgorithm::setNI(string operand, bool flags[])
{
    if (operand.at(0) == '@')
    {
        flags[0] = true;
        flags[1] = false;
    }
    else if (operand.at(0) == '#')
    {
        flags[0] = false;
        flags[1] = true;
    }
    else
    {
        flags[0] = true;
        flags[1] = true;
    }
}

void PassTwoAlgorithm::setX(string operand, bool* indexedAddressError,
                            bool flags[], int format)
{
    *indexedAddressError = false;
    if ((endWith(operand, ",X") || endWith(operand, ",x")) && format != 2)
    {
        if ((getN(flags) && getI(flags)) || !(getN(flags) || getI(flags)))
        {
            flags[2] = true;
        }
        else
        {
            *indexedAddressError = true;
        }
    }
    else
    {
        flags[2] = false;
    }
}
string PassTwoAlgorithm::flagsToString(bool flags[])
{
    string f = "";
    for (int i = 0; i < 6; i++)
    {
        f += (flags[i]) ? "1" : "0";
    }
    return f;
}

void PassTwoAlgorithm::machineCode(string opCode, string opBinary, int format,
                                   int* address, string operand, string& operandBinary,
                                   string& machineCodeBinary, bool* relativeAddressError,
                                   bool* indexedAddressError, bool* invalidExpression, bool flags[], int programCounter,
                                   bool baseAvailable, int base)
{
    machineCodeBinary = "";
    if (*relativeAddressError || *invalidExpression)
    {
        //no machine code
        return;
    }
    if (format == 2)
    {
        machineCodeBinary += opBinary;
        machineCodeBinary += operandBinary;
        return;
    }
    else       //(format == 3 || format == 4)
    {
        setE(opCode, format, flags);
        setBP(format, address, operand, operandBinary, programCounter,
              baseAvailable, base, relativeAddressError, flags);
        setNI(operand, flags);
        setX(operand, indexedAddressError, flags,format);
        machineCodeBinary += opBinary.substr(0, 6);
        string sFlags = flagsToString(flags);
        machineCodeBinary += sFlags;
        machineCodeBinary += operandBinary;
    }
}

vector<pair<int, string>> PassTwoAlgorithm::doPass(vector<string> lines,
                       map<string, int> symTable, map<string, string> opTable,
                       map<string, string> registersTable, int* adresses)
{
    bool baseAvailable = false;
    int base = 0; // value of base register (for testing)
    int programCounter = 0;
    vector<pair<int, string>> objectCode;
    for (int i = 0; i < lines.size(); i++)
    {
        if(!parser.commentChecker(lines.at(i)))
        {
            string* returndInfo = getingLineInfo(lines.at(i));
            int format = getInt(returndInfo[0]);
            string opCode = returndInfo[1];
            parser.toUpper(opCode);
            string operand = returndInfo[2];
            parser.toLower(operand);
            string operandBinary = "";
            int address = 0;
            bool flags[6] = { };
            bool undefinedSymbolError = false;
            bool relativeAddressError = false;
            bool indexedAddressError = false;
            bool invalidExpression = false;
            string machineCodeBinary = "";
            if (opCode == "BASE")
            {
                baseAvailable = true;
                /*initialize the base variable*/
            }
            else if (opCode == "NOBASE")
            {
                baseAvailable = false;
            }
            else if (opCode == "ORG" || opCode == "EQU" || opCode == "START"
                     || opCode == "END" || opCode == "RESW" || opCode == "RESB")
            {
                continue;
            }
            else if (opCode == "WORD" || opCode == "BYTE")
            {
                if(opCode == "WORD")
                {
                    string hexCode = "000000";
                    pair<int,string> code;
                    code.first = i;
                    string op = operand;
                    if(op.at(0) == '@' || op.at(0) == '#')
                    {
                        op = op.substr(1);
                    }
                    int number = parser.getInt(op);
                    string s = parser.decimalToHexa(number);
                    int x = 0;
                    for(int k = hexCode.size() - s.size(); k < hexCode.size(); k++)
                    {
                        hexCode.at(k) = s.at(x);
                        x++;
                    }
                    code.second = hexCode;
                    objectCode.push_back(code);
                }
                else
                {
                    if(operand.at(0)=='X' || operand.at(0)=='x')
                    {
                        pair<int,string> code;
                        code.first = i;
                        code.second = operand.substr(2,operand.size()-2-1);
                        objectCode.push_back(code);
                    }
                    else
                    {
                        pair<int,string> code;
                        code.first = i;
                        string s = operand.substr(2,operand.size()-2-1);
                        int arr[s.size()];
                        string hexCode = "";
                        for(int k = 0; k < s.size(); k++)
                        {
                            arr[k] = s.at(k);
                            hexCode = hexCode + parser.decimalToHexa(arr[k]);
                        }
                        code.second = hexCode;
                        objectCode.push_back(code);
                    }
                }
            }
            else if(operand != "")
            {
                string opBinary = opTable.at(opCode);
                programCounter = adresses[i] + format;
                getAddressFromSymbol(opCode, operand, symTable, registersTable,
                                     format, &address, operandBinary, &undefinedSymbolError, &invalidExpression, programCounter);
                // this function check if operand != "" and check if found in symTable & get address & generate operandBinary for format 2 and 4

                machineCode(opCode, opBinary, format, &address, operand,
                            operandBinary, machineCodeBinary, &relativeAddressError,
                            &indexedAddressError, &invalidExpression, flags, programCounter, baseAvailable,
                            base);
                if(undefinedSymbolError)
                {
                    errors.push_back("undefinedSymbolError");
                    lineOferrors.push_back(i);
                }
                else if(relativeAddressError)
                {
                    errors.push_back("relativeAddressError");
                    lineOferrors.push_back(i);
                }
                else if(indexedAddressError)
                {
                    errors.push_back("indexedAddressError");
                    lineOferrors.push_back(i);
                }
                else if(invalidExpression)
                {
                    errors.push_back("invalidExpression");
                    lineOferrors.push_back(i);
                }
                else
                {
                    pair<int,string> code;
                    code.first = i;
                    char strArr[machineCodeBinary.size()];
                    strcpy(strArr,machineCodeBinary.c_str());
                    string hexCode = parser.binaryToHexa(strArr);
                    if(hexCode.size()%2!=0)
                    {
                        string temp = "0";
                        temp = temp + hexCode;
                        hexCode = temp;
                    }
                    code.second = hexCode;
                    objectCode.push_back(code);
                }
            }
        }
    }

    return objectCode;
}

string* PassTwoAlgorithm::getingLineInfo(string line)
{
    regex secondFormat(
        "^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+([ABLSTX]\\s*(,\\s*[ABLSTX])?)\\s*(\\..*)?\\s*$",
        std::regex_constants::icase);
    regex thirdFormat(
        "^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+(((@|#)([a-zA-Z0-9]{1,17}))|([^\\s.]{1,18}))\\s*(\\..*)?\\s*$",
        std::regex_constants::icase);
    regex forthFormat(
        "^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?((\\+)([a-zA-Z]{1,5}))\\s+(((@|#)([a-zA-Z0-9]{1,17}))|([^\\s.]{1,18}))\\s*(\\..*)?\\s*$",
        std::regex_constants::icase);
    regex returnSub(
        "^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?((\\+)?(rsub))\\s*(\\..*)?\\s*$",
        std::regex_constants::icase);
    string* data = new string[3];
    string sp(line);
    smatch match;

    if (regex_search(sp, match, returnSub) == true)
    {
        if (match.str(4) != "")
        {
            data[0] = "4";
        }
        else
        {
            data[0] = "3";
        }
        data[1] = match.str(5);
        data[2] = "";
    }
    else if (regex_search(sp, match, secondFormat) == true)
    {
        data[0] = "2";
        data[1] = match.str(3);
        string registers = match.str(4);
        registers.erase(remove(registers.begin(), registers.end(), ' '),
                        registers.end());
        data[2] = registers;

    }
    else if (regex_search(sp, match, thirdFormat) == true)
    {
        data[0] = "3";
        data[1] = match.str(3);
        data[2] = match.str(4);
    }
    else if (regex_search(sp, match, forthFormat) == true)
    {
        data[0] = "4";
        data[1] = match.str(5);
        data[2] = match.str(6);

    }
    return data;
}
