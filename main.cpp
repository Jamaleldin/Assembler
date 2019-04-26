#include <iostream>
#include <bits/stdc++.h>
#include <regex>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "passOne.h"
#include "InOutFile.h"
#include "passOneAlgorithm.h"

using namespace std;

int main()
{
    /*initializing maps
    ====================*/
    map<string,string> opCodeSecondFormat;
    map<string,string> opCodeThirdForth;
    map<string,string> opCodeDirectives;
    passOne maps;
    maps.initializMaps(opCodeSecondFormat,opCodeThirdForth,opCodeDirectives);
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
    map<string, int>symTable = pass.doPass(lines,opCodeSecondFormat,opCodeThirdForth,opCodeDirectives);
    /*writing to outputFile
    =======================*/
    IO.writtingFile(pass.getSymbolTable(), lines, pass.getNumOfError(), pass.getTypeOfError(), pass.getAdresses());
    return 0;
}
