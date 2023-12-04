#include "mytools.h"
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"

using namespace std;


int main(int argc, char* argv[]) {
    if (argc == 2) {
        switch (stoi(argv[1]))
        {
        case 1:
            ExecuteDay1();
            break;
        case 2:
            ExecuteDay2();
            break;
        case 3:
            Day3::Execute();
            break;
        default:
            break;
        }
    }

    return 0;
}