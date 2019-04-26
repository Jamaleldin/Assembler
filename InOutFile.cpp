#include "InOutFile.h"
#include <bits/stdc++.h>
#include <iostream>
#include "passOne.h"
using namespace std;
passOne one;
InOutFile::InOutFile()
{
    //ctor
}
vector<string> InOutFile::readingFile(string inputFileName)
{
    ifstream inputFile(inputFileName);
    vector<string> lines;
    if(inputFile.is_open())
    {
            string line;
            while(getline(inputFile,line))
            {
                lines.push_back(line);
            }
            inputFile.close();
    }
    return lines;
}
void InOutFile::writtingFile(map<string,int>symbolTable, vector<string> lines, vector<int> numOfError, vector<string> typeOfError, int* addresses)
{

    ofstream outFile;
    outFile.open("output.txt");
    outFile.setf(std::ios_base::left, std::ios_base::adjustfield);
    int j = 0;
    for (int i = 0; i < lines.size(); i ++)
    {
        if(!one.commentChecker(lines.at(i)))
        {
            outFile<<std::setw(10)<<std::hex<<std::uppercase<<addresses[i];
            outFile<<lines.at(i)<<endl;
            if(!numOfError.empty() && j < numOfError.size())
            {
                if(numOfError.at(j) == i)
                {
                    outFile<<"***"<<typeOfError.at(j)<<endl;
                    j++;
                }
            }
        }
        else
        {
            outFile<<lines.at(i)<<endl;
        }
    }
    if(typeOfError.size()==0)
    {
        outFile<<"============================================="<<endl;
        outFile<<std::setw(10)<<"Label"<<std::setw(10)<<"Address"<<endl;
        map<string,int>::iterator in;
        for(in=symbolTable.begin(); in!=symbolTable.end(); in++)
        {
            outFile<<std::setw(10)<<in->first<<std::setw(10)<<std::dec<<in->second<<endl;
        }
    }
    outFile.close();
}
