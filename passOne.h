#ifndef PASSONE_H
#define PASSONE_H
#include <bits/stdc++.h>
#include <regex>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class passOne
{
    public:
        passOne();
        void initializMaps(map<string, string> &opCodeSecondFormat , map<string, string> &opCodeThirdForth, map<string, string> &opCodeDirectives, map<string, string> &opTable, map<string, string> &regestersOpCode);
        string* checkingGeneralRegex (string line);
        bool commentChecker(string mainStr);
        int getHex(string hexstr);
        int getInt(string s);
        bool strIsDigit(string s);
        bool checkingOpRegex(string line, string reg);
        void toUpper(basic_string<char>& s);
        void toLower(basic_string<char>& s);
        bool IsHex(string& in);
        bool expressionChecker(string operand);
        int* expressionEvaluator(string first, string second, string operation, vector<string> absLabels, map<string,int> symbolTable, vector<string> namesOftable);
        string* getExpressionGroup(string expression);
        unsigned long long int baseToDecimal(char * number, int base);
        string decimalToHexa(unsigned long long int decimal);
        string binaryToHexa(char * binary);
    protected:

    private:
};

#endif // PASSONE_H
