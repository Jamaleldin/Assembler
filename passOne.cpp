#include "passOne.h"
#include <stdio.h>
#include <stdlib.h>

passOne::passOne()
{
    //ctor
}
void passOne::initializMaps(map<string, string> &opCodeSecondFormat, map<string, string> &opCodeThirdForth, map<string, string> &opCodeDirectives, map<string, string> &opTable, map<string, string> &regestersOpCode)
{
    string operandCommonRegex = "^(((@|#)(([a-zA-Z0-9]{1,17})))|([a-zA-Z]{1}[a-zA-Z0-9]{1,17})|((([a-zA-Z]{1}[a-zA-Z0-9]{0,15}))\\s*\\,\\s*(x))|((#|@)?([a-zA-Z0-9]{1,8})(\\+|\\-|\\*|\\\\)(#|@)?([a-zA-Z0-9]{1,8})))$";
    /*Map for second format
    ========================*/
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
    opCodeThirdForth["ADD"] = operandCommonRegex;
    opCodeThirdForth["COMP"] = operandCommonRegex;
    opCodeThirdForth["DIV"] = operandCommonRegex;
    opCodeThirdForth["J"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))$";
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
    /*Map for directives
    ====================*/
    opCodeDirectives["START"] = "^[a-fA-F0-9]{0,4}$";
    opCodeDirectives["END"] =  "^((([a-zA-Z]{1})([a-zA-Z0-9]{1,7}))|(\\*)|((@|#)(([a-zA-Z]{1})([a-zA-Z0-9]{1,6}))))$";
    opCodeDirectives["BYTE"] = "^(([X]\\'[a-fA-F0-9]{0,14}\\')|([C]\\'[a-zA-Z0-9]{0,15}\\'))$";
    opCodeDirectives["RESB"] = "^(([0-9]{1,4})|(([a-zA-Z0-9]{1,8})(\\+|\\-|\\*|\\\\)([a-zA-Z0-9]{1,8})))$";
    opCodeDirectives["WORD"] = "^(([0-9]{1,4})|((#|@|-)([0-9]{1,4})))$";
    opCodeDirectives["RESW"] = "^(([0-9]{1,4})|(([a-zA-Z0-9]{1,8})(\\+|\\-|\\*|\\\\)([a-zA-Z0-9]{1,8})))$";
    opCodeDirectives["EQU"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{0,7}))|([a-fA-F0-9]{1,4})|(\\*)|((#|@)?([a-zA-Z0-9]{1,8})(\\+|\\-|\\*|\\\\)(#|@)?([a-zA-Z0-9]{1,8})))$";
    opCodeDirectives["ORG"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{0,7}))|([a-fA-F0-9]{1,4})|(\\*)|((#|@)?([a-zA-Z0-9]{1,8})(\\+|\\-|\\*|\\\\)(#|@)?([a-zA-Z0-9]{1,8})))$";
    opCodeDirectives["BASE"] = "^((([a-zA-Z]{1})([a-zA-Z0-9]{0,7}))|([a-fA-F0-9]{1,4})|(\\*)|((#|@)?([a-zA-Z0-9]{1,8})(\\+|\\-|\\*|\\\\)(#|@)?([a-zA-Z0-9]{1,8})))$";
    opCodeDirectives["NOBASE"] = "^$";
    /*Map for objectCode
    ====================*/
    opTable["ADD"] = "00011000";
    opTable["ADDR"] = "10010000";
    opTable["CLEAR"] = "10110100";
    opTable["COMP"] = "00101000";
    opTable["COMPR"] = "10100000";
    opTable["DIV"] = "00100100";
    opTable["DIVR"] = "10011100";
    opTable["J"] = "00111100";
    opTable["JEQ"] = "00110000";
    opTable["JLT"] = "00111000";
    opTable["JGT"] = "00110100";
    opTable["JSUB"] = "01001000";
    opTable["LDA"] = "00000000";
    opTable["LDB"] = "01101000";
    opTable["LDCH"] = "01010000";
    opTable["LDL"] = "00001000";
    opTable["LDS"] = "01101100";
    opTable["LDT"] = "01110100";
    opTable["LDX"] = "00000100";
    opTable["MUL"] = "00100000";
    opTable["MULR"] = "10011000";
    opTable["RMO"] = "10101100";
    opTable["RSUB"] = "01001100";
    opTable["STA"] = "00001100";
    opTable["STB"] = "01111000";
    opTable["STCH"] = "01010100";
    opTable["STL"] = "00010100";
    opTable["STS"] = "01111100";
    opTable["STT"] = "10000100";
    opTable["STX"] = "00010000";
    opTable["SUB"] = "00011100";
    opTable["SUBR"] = "10010100";
    opTable["RD"] = "11011000";
    opTable["TD"] = "11100000";
    opTable["WD"] = "11011100";
    opTable["TIX"] = "00101100";
    opTable["TIXR"] = "10111000";
    /*Map for registers
    ===================*/
    regestersOpCode["a"] = "0000";
    regestersOpCode["x"] = "0001";
    regestersOpCode["l"] = "0010";
    regestersOpCode["b"] = "0011";
    regestersOpCode["s"] = "0100";
    regestersOpCode["t"] = "0101";
    regestersOpCode["f"] = "0110";
    regestersOpCode["pc"] = "1000";
    regestersOpCode["sw"] = "1001";
}
string* passOne::checkingGeneralRegex (string line)
{
    regex secondFormat("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+([ABLSTX]\\s*(,\\s*[ABLSTX])?)\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    regex thirdFormat("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+(((@|#)([a-zA-Z0-9]{1,17}))|([^\\s.]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    regex forthFormat("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?((\\+)([a-zA-Z]{1,5}))\\s+(((@|#)([a-zA-Z0-9]{1,17}))|([^\\s.]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    regex returnSub("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?((\\+)?(rsub))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    regex endProg("^\\s*(end)(\\s+((\\*)|([a-zA-Z]{1}[a-zA-Z0-9]{1,17})|((@|#)([a-zA-Z]{1}[a-zA-Z0-9]{1,16}))))?\\s*(\\..*)?\\s*$",std::regex_constants::icase);
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
        data[1] = "";
        data[2] = match.str(1);
        data[3]= match.str(4);
    }
    else if(regex_search(sp, match, returnSub) == true)
    {
        if (match.str(4) != "")
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
        data[3] = match.str(4);
    }
    else if(regex_search(sp, match, forthFormat) == true)
    {
        data[0] = "4";
        data[1] = match.str(2);
        data[2] = match.str(5);
        data[3] = match.str(6);

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

bool passOne::expressionChecker(string operand)
{
    regex r("^(([a-zA-Z0-9]{1,8})(\\+|\\-|\\*|\\\\)([a-zA-Z0-9]{1,8}))$");



    if(regex_match(operand, r) == true)
    {
        return true;
    } else
    {
        return false;
    }
}

int* passOne::expressionEvaluator(string first, string second, string operation, vector<string> absLabels, map<string,int> symbolTable, vector<string> namesOftable)
{
    toLower(first);
    toLower(second);
    int op = 0;

    int* flags = new int[2];

    if (!strIsDigit(first))
    {
        if (!(std::find(namesOftable.begin(), namesOftable.end(), first) != namesOftable.end()))
        {
            flags[0] = -2;
            flags[1] = -2;
            return flags;
        }
    }

    if (!strIsDigit(second))
    {
        if (!(std::find(namesOftable.begin(), namesOftable.end(), second) != namesOftable.end()))
        {
            flags[0] = -2;
            flags[1] = -2;
            return flags;
        }
    }

    if (operation.compare("+") == 0){
        op = 0;
    } else if (operation.compare("-") == 0)
    {
        op = 1;
    } else if (operation.compare("*") == 0)
    {
        op = 2;
    } else if (operation.compare("/") == 0)
    {
        op = 3;
    }

    if (strIsDigit(first) && strIsDigit(second))
    {
        switch (op)
        {
            case 0 : flags[0] = getInt(first) + getInt(second); flags[1] = 0; return flags;
            case 1 : flags[0] = getInt(first) - getInt(second); flags[1] = 0; return flags;
            case 2 : flags[0] = getInt(first) * getInt(second); flags[1] = 0; return flags;
            case 3 : flags[0] = getInt(first) / getInt(second); flags[1] = 0; return flags;
        }
    } else if (strIsDigit(first) && std::find(absLabels.begin(), absLabels.end(), second) != absLabels.end())
    {
        switch (op)
        {
            case 0 : flags[0] = getInt(first) + symbolTable.at(second); flags[1] = 0; return flags;
            case 1 : flags[0] = getInt(first) - symbolTable.at(second); flags[1] = 0; return flags;
            case 2 : flags[0] = getInt(first) * symbolTable.at(second); flags[1] = 0; return flags;
            case 3 : flags[0] = getInt(first) / symbolTable.at(second); flags[1] = 0; return flags;
        }
    } else if (strIsDigit(first) && !(std::find(absLabels.begin(), absLabels.end(), second) != absLabels.end()))
    {
        switch (op)
        {
            case 0 : flags[0] = getInt(first) + symbolTable.at(second); flags[1] = 1; return flags;
            case 1 : flags[0] = -1; return flags;
            case 2 : flags[0] = -1; return flags;
            case 3 : flags[0] = -1; return flags;
        }
    } else if (std::find(absLabels.begin(), absLabels.end(), first) != absLabels.end() && strIsDigit(second))
    {
        switch (op)
        {
            case 0 : flags[0] = symbolTable.at(first) + getInt(second); flags[1] = 0; return flags;
            case 1 : flags[0] = symbolTable.at(first) - getInt(second); flags[1] = 0; return flags;
            case 2 : flags[0] = symbolTable.at(first) * getInt(second); flags[1] = 0; return flags;
            case 3 : flags[0] = symbolTable.at(first) / getInt(second); flags[1] = 0; return flags;
        }
    } else if (std::find(absLabels.begin(), absLabels.end(), first) != absLabels.end() && !(std::find(absLabels.begin(), absLabels.end(), second) != absLabels.end()))
    {
        switch (op)
        {
            case 0 : flags[0] = symbolTable.at(first) + symbolTable.at(second); flags[1] = 1; return flags;
            case 1 : flags[0] = -1; flags[1] = -1; return flags;
            case 2 : flags[0] = -1; flags[1] = -1; return flags;
            case 3 : flags[0] = -1; flags[1] = -1; return flags;
        }
    } else if (std::find(absLabels.begin(), absLabels.end(), first) != absLabels.end() && std::find(absLabels.begin(), absLabels.end(), second) != absLabels.end())
    {
        switch (op)
        {
            case 0 : flags[0] = symbolTable.at(first) + symbolTable.at(second); flags[1] = 0; return flags;
            case 1 : flags[0] = symbolTable.at(first) - symbolTable.at(second); flags[1] = 0; return flags;
            case 2 : flags[0] = symbolTable.at(first) * symbolTable.at(second); flags[1] = 0; return flags;
            case 3 : flags[0] = symbolTable.at(first) / symbolTable.at(second); flags[1] = 0; return flags;
        }
    } else if (!(std::find(absLabels.begin(), absLabels.end(), first) != absLabels.end()) && strIsDigit(second))
    {
        switch (op)
        {
            case 0 : flags[0] = symbolTable.at(first) + getInt(second); flags[1] = 1; return flags;
            case 1 : flags[0] = symbolTable.at(first) - getInt(second); flags[1] = 1; return flags;
            case 2 : flags[0] = -1; flags[1] = -1; return flags;
            case 3 : flags[0] = -1; flags[1] = -1; return flags;
        }
    } else if (!(std::find(absLabels.begin(), absLabels.end(), first) != absLabels.end()) && std::find(absLabels.begin(), absLabels.end(), second) != absLabels.end())
    {
        switch (op)
        {
            case 0 : flags[0] = symbolTable.at(first) + symbolTable.at(second); flags[1] = 1; return flags;
            case 1 : flags[0] = symbolTable.at(first) + symbolTable.at(second); flags[1] = 1; return flags;
            case 2 : flags[0] = -1; flags[1] = -1; return flags;
            case 3 : flags[0] = -1; flags[1] = -1; return flags;
        }
    } else if (!(std::find(absLabels.begin(), absLabels.end(), first) != absLabels.end()) && !(std::find(absLabels.begin(), absLabels.end(), second) != absLabels.end()))
    {
        switch (op)
        {
            case 0 : flags[0] = -1; flags[1] = -1; return flags;
            case 1 : flags[0] = symbolTable.at(first) - symbolTable.at(second); flags[1] = 0;  return flags;
            case 2 : flags[0] = -1; flags[1] = -1; return flags;
            case 3 : flags[0] = -1; flags[1] = -1; return flags;
        }
    }
}

string* passOne::getExpressionGroup(string expression)
{
    regex expressionRegex("^((([a-zA-Z]{1})([a-zA-Z0-9]{0,7}))|([a-fA-F0-9]{1,4})|(\\*)|(([a-zA-Z0-9]{1,8})(\\+|\\-|\\*|\\\\)([a-zA-Z0-9]{1,8})))$");

    string* groups = new string[3];
    string sp (expression);
    smatch match;

    if(regex_search(sp, match, expressionRegex) == true)
    {
        groups[0] = match.str(8);
        groups[1] = match.str(9);
        groups[2] = match.str(10);
    }
    return groups;
}

bool passOne::commentChecker(string mainStr)
{
    // std::string::find returns 0 if toMatch is found at starting
    if(mainStr.find(".") == 0)
        return true;
    else
        return false;
}
/*convert hex string to int*/
int passOne::getHex(string hexstr)
{
    return (int)strtol(hexstr.c_str(), 0, 16);
}
/*convert string to int*/
int passOne::getInt(string s)
{
    int i = std::atoi (s.c_str());
    return i;
}
bool passOne::strIsDigit(string s)
{
    int numOfdigits=0;
    for(int i=0; i<s.length(); i++)
    {
        if(isdigit(s.at(i)))
            numOfdigits++;
    }
    return numOfdigits==s.length();
}
bool passOne::checkingOpRegex(string line, string reg)
{
    regex r(reg,std::regex_constants::icase);

    if(regex_match(line,r))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void passOne::toUpper(basic_string<char>& s)
{
    for (basic_string<char>::iterator p = s.begin();
            p != s.end(); ++p)
    {
        *p = toupper(*p); // toupper is for char
    }
}

void passOne::toLower(basic_string<char>& s)
{
    for (basic_string<char>::iterator p = s.begin();
            p != s.end(); ++p)
    {
        *p = tolower(*p);
    }
}

bool passOne::IsHex(string& in)
{
    for (char d : in)
    {
        if (!isxdigit(d)) return false;
    }
    return true;
}
unsigned long long int passOne::baseToDecimal(char * number, int base) {
	return strtoull (number, NULL, base);

}

string passOne::decimalToHexa(unsigned long long int decimal) {
	int temp = decimal, r;
	string hexa = "";
	while (temp != 0) {
		r = temp % 16;
	    if (r < 10) {
	    	char d = r + 48;
			hexa = d + hexa;
	    } else {
	    	char d = r + 55;
	    	hexa = d + hexa;
	    }
	    temp = temp / 16;
	}
	return hexa;
}

string passOne::binaryToHexa(char * binary) {
	unsigned long long int decimal = baseToDecimal(binary, 2);
	return decimalToHexa(decimal);
}
