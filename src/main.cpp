#include "mytools.h"
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"
#include "day6/day6.h"

using namespace std;


int main(int argc, char* argv[]) {
    if (argc == 2) {
        switch (stoi(argv[1]))
        {
        case 1:
            Day1::Execute();
            break;
        case 2:
            Day2::Execute();
            break;
        case 3:
            Day3::Execute();
            break;
        case 4:
            Day4::Execute();
            break;
        case 5:
            Day5::Execute();
            break;
        case 6:
            Day6::Execute();
            break;
        default:
            break;
        }
    }

    return 0;
}