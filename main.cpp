#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::vector, std::string;

void ParseInput(vector<string> &outputVec, string inputFilePath) {

    std::ifstream inputStream(inputFilePath);

    string s;
    while (getline(inputStream, s)) {
        outputVec.push_back(s); 
    }
}

int main() {
    vector<string> inputVector;
    ParseInput(inputVector, "input.txt");
    return 0;
}