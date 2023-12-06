#include "mytools.h"

using namespace std;

namespace MyTools
{
    bool IsNumber(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }

    extern void ParseInput(vector<string> &outputVec, string inputFilePath) {

        std::ifstream inputStream(inputFilePath);

        string s;
        while (getline(inputStream, s)) {
            if(!s.empty()) {
                outputVec.push_back(s);   
            } 
        }
    }
}