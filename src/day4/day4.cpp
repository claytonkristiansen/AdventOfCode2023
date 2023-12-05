#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>

#include "day4.h"

using namespace std;

namespace Day4
{
    void GetHalves(string inputString, vector<int> &arr1, vector<int> &arr2) {
        istringstream ss(inputString);
        ss.ignore(10);

        string num = "";
        bool numStart = false;
        for (int i = 0 ;; ++i) {
            char c;
            ss.get(c);
            if (c == '|') {
                break;
            }
            else if (c >= '0' && c <= '9') {
                if (!numStart) {
                    numStart = true;
                }
                num += c;
            }
            else if (numStart) {
                numStart = false;
                arr1.push_back(stoi(num));
                num = "";
            }
        }

        for (int i = 0 ;; ++i) {
            char c;
            ss.get(c);

            if (ss.eof() && numStart) {
                if (num != "") {
                    arr2.push_back(stoi(num));
                }
                break;
            }

            if (c >= '0' && c <= '9') {
                if (!numStart) {
                    numStart = true;
                }
                num += c;
            }
            else if (numStart) {
                numStart = false;
                arr2.push_back(stoi(num));
                num = "";
            }
        }
    }

    int NumMatches(vector<int> arr1, vector<int> arr2) {
        int matches = 0;
        for (int i : arr1) {
            for (int k : arr2) {
                if (i == k) {
                    ++matches;
                }
            }
        }

        return matches;
    }

    int Execute() {
        vector<string> input;
        MyTools::ParseInput(input, "input.txt");

        vector<ScratchCard> cards;
        int sumPart1 = 0;
        
        for (int i = 0; i < input.size(); ++i) {
            vector<int> arr1, arr2;
            GetHalves(input[i], arr1, arr2);

            int matches = NumMatches(arr1, arr2);
            if (matches > 0) {
                sumPart1 += pow(2, matches - 1);
            }
            cards.push_back(ScratchCard(input[i], matches, i));
        }

        int totalScratchCards = 0;

        for (int i; i < cards.size(); ++i) {
            ++totalScratchCards;
            for (int k = 1; k <= cards[i].winningNumbers; ++k) {
                cards.push_back(cards[cards[i].id + k]);
            }
        }

        cout << "The total values is: " << sumPart1 << "\n\n";

        cout << "Total number of scratch cards: " << totalScratchCards << "\n\n";

        return 0;
    }       
}