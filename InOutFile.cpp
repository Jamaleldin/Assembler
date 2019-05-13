#include "InOutFile.h"

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
void InOutFile::wirtingFileFormatOne(vector<string> lines, vector<int> numOfError, vector<string> typeOfError,int* addresses, vector<pair<int, string>> objectCode)
{
    ofstream outFile;
    outFile.open("listFile.txt");
    int j = 0;
    int x = 0;
    for (int i = 0; i < lines.size(); i ++)
    {
        if(!one.commentChecker(lines.at(i)))
        {
            outFile.setf(std::ios_base::left, std::ios_base::adjustfield);
            outFile<<std::setw(10)<<std::hex<<std::uppercase<<addresses[i];
            outFile<<lines.at(i);
            if(!objectCode.empty() && x < objectCode.size())
            {
                if(objectCode.at(x).first == i)
                {
                    outFile.setf(std::ios_base::right, std::ios_base::adjustfield);
                    outFile<<std::setw(20)<<objectCode.at(x).second;
                    x++;
                }
            }
            outFile<<endl;
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
    outFile.close();
}
void InOutFile::wirtingFileFormatTwo(vector<string> lines,int* addresses, vector<pair<int, string>> objectCode)
{
    ofstream outFile;
    outFile.open("objectFile.txt");
    vector<int> sum;
    int counter = 0;
    string progName = "      ";
    int startAddress = 0;
    int endAddress;
    int L;
    for(int i = 0; i < objectCode.size(); i++)
    {
        counter = counter + (objectCode.at(i).second.size()/2) ;
        if((i+1)%5 == 0)
        {
            sum.push_back(counter);
            counter = 0;
        }
        else if(i == objectCode.size()-1)
        {
            sum.push_back(counter);
            counter = 0;
        }
    }
    for(int i = 0; i < lines.size(); i++)
    {
        if(!one.commentChecker(lines.at(i)))
        {
            string* data = one.checkingGeneralRegex(lines.at(i));
            one.toUpper(data[2]);
            if(data[2] == "START")
            {
                progName = data[1];
                if(progName.size()>=6)
                {
                    progName = progName.substr(0,6);
                }
                else
                {
                    while(progName.size() < 6)
                    {
                        progName = progName + " ";
                    }
                }
                startAddress = one.getHex(data[3]);
                break;
            }
        }
    }
    for(int i = lines.size()-1; i>=0; i--)
    {
        if(!one.commentChecker(lines.at(i)))
        {
            string* data = one.checkingGeneralRegex(lines.at(i));
            one.toUpper(data[2]);
            if(data[2] == "END")
            {
                for(int j = i; i>=0; i--)
                {
                    if(j!=i && !one.commentChecker(lines.at(j)))
                    {
                        endAddress = addresses[j];
                    }
                }
            }
        }
    }
    if(startAddress==0)
    {
        L = endAddress + 2;
    }
    else
    {
        L = endAddress - startAddress;
    }
    outFile<<"H^"<<progName<<"^";
    string sadr = "000000";
    string objectL = "000000";
    string temp = one.decimalToHexa(startAddress);
    int x = 0;
    for(int i=6 - temp.size(); i<6; i++)
    {
        sadr.at(i) = temp.at(x);
    }
    outFile<<sadr<<"^";
    temp = one.decimalToHexa(L);
    x = 0;
    for(int i=6 - temp.size(); i<6; i++)
    {
        objectL.at(i) = temp.at(x);
    }
    outFile<<objectL<<endl;
    int j = 0;
    int adr;
    for(int i=0; i<sum.size(); i++)
    {
        outFile<<"T^";
        if(i == 0)
        {
            outFile<<sadr<<"^";
            adr = one.getHex(sadr);
        }
        else
        {
            temp = "000000";
            adr = adr + sum.at(i-1);
            string temp2 = one.decimalToHexa(adr);
            x = 0;
            for(int i=6 - temp2.size(); i<6; i++)
            {
                temp.at(i) = temp2.at(x);
            }
            outFile<<temp<<"^";

        }
        string textLength;
        if(sum.at(i) < 16)
        {
            textLength = "0" + one.decimalToHexa(sum.at(i));
        }
        else
        {
            textLength = one.decimalToHexa(sum.at(i));
        }
        outFile<<textLength<<"^";
        int counter = 0;
        while(counter<5 && j < objectCode.size())
        {
            if(counter == 4 || j == objectCode.size()-1)
            {
                outFile<<objectCode.at(j).second<<endl;
                counter++;
                j++;
            }
            else
            {
                outFile<<objectCode.at(j).second<<"^";
                counter++;
                j++;
            }
        }
    }
    outFile<<"E^"<<sadr;
    outFile.close();
}
