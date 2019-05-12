#ifndef PASSTWOALGORITHM_H
#define PASSTWOALGORITHM_H
#include <iostream>
#include <bits/stdc++.h>
#include "passOne.h"

using namespace std;

class PassTwoAlgorithm
{
    public:
        PassTwoAlgorithm();
        void setAbsLabels(vector<string> labels);
        void setNamesOfTables(vector<string> names);
        vector<string> doPass(vector<string> lines, map<string, int> symTable, map<string, string> opTable, map<string, string> regestersOpCode,int* adresses);

    protected:

    private:
        string* getingLineInfo(string line);
        bool endWith(string const &fullString, string const &ending);
        int getInt(string s);
        bool strIsDigit(string s);
        void decimalToBinary(int decimal, string& binary);
        bool getE(bool flags[]);
        bool getP(bool flags[]);
        bool getB(bool flags[]);
        bool getX(bool flags[]);
        bool getI(bool flags[]);
        bool getN(bool flags[]);
        void setE(string opCode, int format, bool flags[]);
        void getAddressFromSymbol(string opCode, string operand,
        map<string, int> &symTable, map<string, string> &registersTable,
        int format, int* address, string& operandBinary,
        bool* undefinedSymbolError, bool* invalidExpression);
        void setBP(int format, int* address, string operand, string& operandBinary,
                             int programCounter, bool baseAvailable, int base,
                             bool* relativeAddressError, bool flags[]);
        void setNI(string operand, bool flags[]);
        void setX(string operand, bool* indexedAddressError, bool flags[], int format);
        string flagsToString(bool flags[]);
        void machineCode(string opCode, string opBinary, int format, int* address,
                                   string operand, string& operandBinary, string& machineCodeBinary,
                                   bool* relativeAddressError, bool* indexedAddressError,
								   bool* invalidExpression, bool flags[],
                                   int programCounter, bool baseAvailable, int base);
};

#endif // PASSTWOALGORITHM_H
