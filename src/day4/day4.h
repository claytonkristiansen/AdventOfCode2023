#include "mytools.h"

namespace Day4
{
    void GetHalves(std::string inputString, std::vector<int> &arr1, std::vector<int> &arr2);
    class ScratchCard 
    {
    public:
        int id;
        std::vector<int> leftSide;
        std::vector<int> rightSide;
        int winningNumbers;

        ScratchCard(std::string inputString, int winNum, int idNum) {
            GetHalves(inputString, leftSide, rightSide);
            winningNumbers = winNum;
            id = idNum;
        }
    };

    int Execute();
} // namespace Day4