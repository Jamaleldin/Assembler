#ifndef PASSTWOALGORITHM_H
#define PASSTWOALGORITHM_H
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class PassTwoAlgorithm
{
    public:
        PassTwoAlgorithm();
        vector<string> doPass(vector<string> lines, map<string, int> symTable, map<string, string> opTable, map<string, string> regestersOpCode);

    protected:

    private:
        string* getingLineInfo(string line);
};

#endif // PASSTWOALGORITHM_H
