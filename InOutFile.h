#ifndef INOUTFILE_H
#define INOUTFILE_H
#include <bits/stdc++.h>
#include <iostream>
#include "passOne.h"

using namespace std;

class InOutFile
{
    public:
        InOutFile();
        vector<string> readingFile(string inputFileName);
        void writtingFile(map<string,int>symbolTable, vector<string> lines, vector<int> numOfError, vector<string> typeOfError,int* addresses);
    protected:

    private:
};

#endif // INOUTFILE_H
