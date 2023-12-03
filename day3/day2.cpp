#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Game 
{
public:
    int id = 0;
    int maxRed = 0;
    int maxGreen = 0;
    int maxBlue = 0;
};

void ParseInput(vector<string> &outputVec, string inputFilePath) {

    std::ifstream inputStream(inputFilePath);

    string s;
    while (getline(inputStream, s)) {
        outputVec.push_back(s); 
    }
}

int main(int argc, char* argv[]) {
    vector<string> input; 
    ParseInput(input, "input.txt");

    return 0;
}