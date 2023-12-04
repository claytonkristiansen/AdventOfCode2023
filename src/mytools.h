#pragma once
#include <string>
#include <vector>
#include <fstream>

namespace MyTools
{
    bool IsNumber(char c);

    void ParseInput(std::vector<std::string> &outputVec, std::string inputFilePath);  
}