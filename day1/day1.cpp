#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tuple>
#include <ctype.h>

using   std::vector,
        std::string,
        std::tuple, 
        std::make_tuple,
        std::get;

void ParseInput(vector<string> &outputVec, string inputFilePath) {

    std::ifstream inputStream(inputFilePath);

    string s;
    while (getline(inputStream, s)) {
        outputVec.push_back(s); 
    }
}

int GetCodePart1(string s) {
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

tuple<int, int> GetFirstNumber(string s) {
    int matchLength[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string numberStringArray[] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    for (int i = 0; i < s.length(); ++i) {
        for (int numToCheck = 0; numToCheck < 10; ++numToCheck) {
            if (s[i] == numberStringArray[numToCheck][matchLength[numToCheck]]) {
                if (++matchLength[numToCheck] == numberStringArray[numToCheck].length()) {
                    return make_tuple(numToCheck, i - numberStringArray[numToCheck].length() + 1);
                }
            }
            else if (s[i] == numberStringArray[numToCheck][0]) {
                matchLength[numToCheck] = 1;
            }
            else {
                matchLength[numToCheck] = 0;
            }
        }
    }

    return make_tuple(0, s.length());
}

tuple<int, int> GetLastNumber(string s) {
    int matchLength[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string backwardsNumberStringArray[] = {
        "orez",
        "eno",
        "owt",
        "eerht",
        "ruof",
        "evif",
        "xis",
        "neves",
        "thgie",
        "enin"
    };

    for (int i = s.length() - 1; i >= 0; --i) {
        for (int numToCheck = 0; numToCheck < 10; ++numToCheck) {
            if (s[i] == backwardsNumberStringArray[numToCheck][matchLength[numToCheck]]) {
                if (++matchLength[numToCheck] == backwardsNumberStringArray[numToCheck].length()) {
                    return make_tuple(numToCheck, i + backwardsNumberStringArray[numToCheck].length() - 1);
                }
            }
            else if (s[i] == backwardsNumberStringArray[numToCheck][0]) {
                matchLength[numToCheck] = 1;
            }
            else {
                matchLength[numToCheck] = 0;
            }
        }
    }

    return make_tuple(0, -1);
}

int GetCodePart2(string s) {
    int code = 0;
    
    tuple <int, int> firstNumberByString = GetFirstNumber(s);
    tuple <int, int> lastNumberByString = GetLastNumber(s);

    code += get<0>(firstNumberByString) * 10;
    code += get<0>(lastNumberByString);

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (isdigit(c)) {
            if (i < get<1>(firstNumberByString)) {
                code -= (code / 10) * 10;
                code += ((int)c - '0') * 10;
            }            
            break;
        }
    }
    for(int i = s.length() - 1; i >= 0; --i) {
        char c = s[i];
        if (isdigit(c)) {
            if (i > get<1>(lastNumberByString)) {
                code -= (code - (code / 10) * 10);
                code += (int)c - '0';
            }
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
        sum += GetCodePart1(s);
    }

    std::cout << "The sum of all the calibration values for part 1 is: " << sum << "\n\n";

    sum = 0;

    for (string s : inputVector) {
        sum += GetCodePart2(s);
    }

    std::cout << "The sum of all the calibration values for part 2 is: " << sum << "\n\n";

    return 0;
}