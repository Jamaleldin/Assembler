#include <iostream>
#include <bits/stdc++.h>
#include <regex>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "passOne.h"
#include "InOutFile.h"
#include "passOneAlgorithm.h"
#include "PassTwoAlgorithm.h"

using namespace std;

int main()
{
    /*initializing maps
    ====================*/
    map<string, string> opCodeSecondFormat;
    map<string, string> opCodeThirdForth;
    map<string, string> opCodeDirectives;
    map<string, string> opCode;
    map<string, string> regestersOpCode;
    passOne maps;
    maps.initializMaps(opCodeSecondFormat, opCodeThirdForth, opCodeDirectives, opCode, regestersOpCode);
    /*scanning input from user
    ==========================*/
    string inputFileName;
    cout<<"enter the file name with extension: ((ex:) input.txt) "<<endl;
    cin>>inputFileName;
    /*READING FROM FILE
    ===================*/
    InOutFile IO;
    vector<string> lines = IO.readingFile(inputFileName);
    /*doing pass1
    =============*/
    passOneAlgorithm pass;
    pass.setLength(lines.size());
    pass.doPass(lines,opCodeSecondFormat,opCodeThirdForth,opCodeDirectives);
    map<string, int>symTable = pass.getSymbolTable();
    /*writing to outputFile
    =======================*/
    IO.writtingFile(pass.getSymbolTable(), lines, pass.getNumOfError(), pass.getTypeOfError(), pass.getAdresses());
    return 0;
}
