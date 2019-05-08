#include "PassTwoAlgorithm.h"

PassTwoAlgorithm::PassTwoAlgorithm()
{
    //ctor
}
string* PassTwoAlgorithm::doPass(vector<string> lines, map<string, int> symTable, map<string, string> opTable, map<string, string> regestersOpCode)
{
    for(unsigned int i = 0; i<lines.size(); i++)
    {
    }
}

string* PassTwoAlgorithm::getingLineInfo(string line)
{
    regex secondFormat("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+([ABLSTX]\\s*(,\\s*[ABLSTX])?)\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    regex thirdFormat("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?([a-zA-Z]{1,6})\\s+(((@|#)([a-zA-Z0-9]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    regex forthFormat("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?((\\+)([a-zA-Z]{1,5}))\\s+(((@|#)([a-zA-Z0-9]{1,17}))|([^\\s.@#]{1,18}))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    regex returnSub("^\\s*(([a-zA-Z]{1}[a-zA-Z0-9]{0,7})\\s+){0,1}?((\\+)?(rsub))\\s*(\\..*)?\\s*$",std::regex_constants::icase);
    string* data = new string[4];
    smatch match;

    if(regex_search(line, match, returnSub) == true)
    {
        if (match.str(4) != "")
        {
            data[0] = "4";
        }
        else
        {
            data[0] = "3";
        }
        data[1] = match.str(5);
        data[2] = "";
    }
    else if(regex_search(line, match, secondFormat) == true)
    {
        data[0] = "2";
        data[1] = match.str(3);
        string registers = match.str(4);
        registers.erase(remove(registers.begin(), registers.end(), ' '), registers.end());
        data[2] = registers;

    }
    else if(regex_search(line, match, thirdFormat) == true)
    {
        data[0] = "3";
        data[1] = match.str(2);
        data[2] = match.str(3);
    }
    else if(regex_search(line, match, forthFormat) == true)
    {
        data[0] = "4";
        data[1] = match.str(2);
        data[2] = match.str(5);

    }
    else
    {
        data[0] = "-1";
        data[1] = "-1";
        data[2] = "-1";
    }
    return data;
}
