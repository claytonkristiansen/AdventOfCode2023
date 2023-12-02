#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>

using std::vector, std::string;

void ParseInput(vector<string> &outputVec, string inputFilePath) {

    std::ifstream inputStream(inputFilePath);

    string s;
    while (getline(inputStream, s)) {
        outputVec.push_back(s); 
    }
}

int GetCode(string s) {
    int code = 0;

    for(int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (isdigit(c)) {
            code += ((int)c - '0') * 10;
            break;
        }
    }
    for(int i = s.length() - 1; i >= 0; --i) {
        char c = s[i];
        if (isdigit(c)) {
            code += (int)c - '0';
            break;
        }
    }

    return code;
}

int main() {
    vector<string> inputVector;
    ParseInput(inputVector, "input.txt");

    int sum = 0;

    for (string s : inputVector) {
        sum += GetCode(s);
    }

    std::cout << "The sum of all the calibration values is: " << sum << "\n\n";

    return sum;
}