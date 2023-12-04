//
//

#ifndef AOC2023_DAY03_H
#define AOC2023_DAY03_H

#include <set>
#include "../core/Day.h"
#include "../core/Utils.h"

class Day03: public aoc::Day {

    struct Number {
        Number(int i, utils::Point pPoint, utils::Point pPoint1) : number(i), start(pPoint), end(pPoint1) {}

        int number;
        utils::Point start;
        utils::Point end;
        bool isPartNumber = false;
    };

    struct Symbol {
        Symbol(char i, utils::Point pPoint) : symbol(i), position(pPoint) {}

        char symbol;
        utils::Point position;
        std::set<Number*> adj = {};
    };

public:
    void run() override;

    void test() override;

protected:
    void part1() override;

    void part2() override;
};


#endif //AOC2023_DAY03_H
