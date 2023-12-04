#include "usefulfunctions.h"

using namespace std;

extern void ParseInput(vector<string> &outputVec, string inputFilePath) {

    std::ifstream inputStream(inputFilePath);

    string s;
    while (getline(inputStream, s)) {
        outputVec.push_back(s); 
    }
}