#include "mytools.h"

namespace Day3
{
    class CNumber
    {
    public:
        int val = 0;
        int startIndex = 0;
        int stopIndex = 0;

        void Reset();
    };

    // Returns true if the char c is one of the pre-defined symbols
    bool IsSymbol(char c);

    std::vector<CNumber> FindNumbers(std::vector<std::string> input);

    bool IsSymbolAdjacent(CNumber number, std::vector<std::string> &input, int rowNum);

    int Execute();
} // namespace Day3