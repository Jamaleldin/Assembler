#ifndef PASSONEALGORITHM_H
#define PASSONEALGORITHM_H
#include <bits/stdc++.h>
#include <regex>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "passOne.h"
using namespace std;
class passOneAlgorithm
{
    public:
        passOneAlgorithm();
        void setLength(int l);
        map<string,int> getSymbolTable();
        vector<string> getTypeOfError();
        vector<int> getNumOfError();
        int* getAdresses();
        vector<string> getNamesOfTable();
        vector<string> getAbsLabels();
        void doPass(vector<string>lines,map<string,string> opCodeSecondFormat,map<string,string> opCodeThirdForth,map<string,string> opCodeDirectives);
    protected:

    private:

};

#endif // PASSONEALGORITHM_H
