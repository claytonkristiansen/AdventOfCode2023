#include <chrono>
#include <iostream>

#include "mytools.h"
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"
#include "day4/day4.h"
#include "day5/day5.h"

using namespace std;


int main(int argc, char* argv[]) {
    if (argc == 2) {
        int day = stoi(argv[1]);
        chrono::_V2::system_clock::time_point t1;
        chrono::_V2::system_clock::time_point t2;
        t1 = chrono::high_resolution_clock::now();
        switch (day)
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
        default:
            break;
        }
        t2 = chrono::high_resolution_clock::now();
        chrono::nanoseconds time_ns = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
        chrono::duration<double, std::milli> ms_double = t2 - t1;

        cout << "Day " << day << " algorithm took " << time_ns.count() << " ns     ( " << ms_double.count() << " ms)\n\n";
    }

    return 0;
}