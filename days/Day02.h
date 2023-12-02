//
//

#ifndef AOC2023_DAY02_H
#define AOC2023_DAY02_H

#include "../core/Day.h"

class Day02: public aoc::Day {

    struct GameResult {
        size_t red = 0;
        size_t green = 0;
        size_t blue = 0;
    };

public:
    void run() override;

    void test() override;

protected:
    void part1() override;

    void part2() override;
};


#endif //AOC2023_DAY02_H
