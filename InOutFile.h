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
        void wirtingFileFormatOne(vector<string> lines, vector<int> numOfError, vector<string> typeOfError,int* addresses, vector<pair<int, string>> objectCode);
        void wirtingFileFormatTwo(vector<string> lines,int* addresses, vector<pair<int, string>> objectCode);
    protected:

    private:
};

#endif // INOUTFILE_H
