#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "day3.h"

using namespace std;

namespace Day3 
{
    void CNumber::Reset() {
        this->startIndex = 0;
        this->stopIndex = 0;
        this->val = 0;
    }

    bool IsSymbol(char c) {
        vector<char> symbols = {'@', '#', '$', '%', '&', '*', '-', '=', '+', '/'};

        for (char symbol : symbols) {
            if (symbol == c) {
                return true;
            }
        }

        return false;
    }

    

    vector<CNumber> FindNumbers(std::string line) {
        vector<CNumber> numbersVec;
        CNumber number;
        string numString;

        bool onNumber = false;

        for (int i = 0; i < line.length(); ++i) {
            if (MyTools::IsNumber(line[i])) {
                numString.push_back(line[i]);
                if (!onNumber) {
                    onNumber = true;
                    number.startIndex = i;
                }

                if (i == line.length() - 1) {
                    onNumber = false;
                    number.stopIndex = i;
                    number.val = stoi(numString);
                    numbersVec.push_back(number);
                }
            }
            else if (onNumber) {
                onNumber = false;
                number.stopIndex = i - 1;
                number.val = stoi(numString);
                numbersVec.push_back(number);
                number.Reset();
                numString = "";
            }
        }

        return numbersVec;
    }

    bool IsSymbolAdjacent(CNumber number, vector<string> &input, int rowNum) {
        int width = input[rowNum].length();
        int startLookIndex = 0;
        int stopLookIndex = width - 1;
        if (number.startIndex > 0) {
            startLookIndex = number.startIndex - 1;
        }
        if (number.stopIndex < width - 1) {
            stopLookIndex = number.stopIndex + 1;
        }
        
        // Check line above first, if it exists
        if (rowNum > 0) {
            for (int i = startLookIndex; i <= stopLookIndex; ++i) {
                if (IsSymbol(input[rowNum - 1][i])) {
                    return true;
                }
            }
        }

        // Next check line it is on
        if ((number.startIndex > 0 && IsSymbol(input[rowNum][number.startIndex - 1])) ||
            (number.stopIndex < width - 1  && IsSymbol(input[rowNum][number.stopIndex + 1]))
            ) {
            return true;
        }

        // Finally check the line below, if it exists
        if (rowNum < input.size() - 1) {
            for (int i = startLookIndex; i <= stopLookIndex; ++i) {
                if (IsSymbol(input[rowNum + 1][i])) {
                    return true;
                }
            }
        }

        return false;
    }

    int Execute() {
        vector<string> input; 
        MyTools::ParseInput(input, "input.txt");

        int sum = 0;

        for (int i = 0; i < input.size(); ++i) {
            vector<CNumber> numbersInLine = FindNumbers(input[i]);
            for (CNumber number : numbersInLine) {
                if (IsSymbolAdjacent(number, input, i)) {
                    sum += number.val;
                }
            }
        }

        cout << "The sum of the part number is: " << sum << "\n\n";

        return 0;
    }       
}