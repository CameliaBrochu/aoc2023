//
//

#ifndef AOC2023_DAY04_H
#define AOC2023_DAY04_H

#include "../core/Day.h"

class Day04: public aoc::Day {

    struct ScratchCard {
        int count = 1;
        int points = 0;
    };

public:
    void run() override;

    void test() override;

protected:
    void part1() override;

    void part2() override;
};


#endif //AOC2023_DAY04_H
