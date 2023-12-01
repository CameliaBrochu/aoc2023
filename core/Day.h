//
//

#ifndef AOC2023_DAY_H
#define AOC2023_DAY_H

#include <vector>
#include <string>
#include "Utils.h"

namespace aoc{
    class Day {
    public:
        virtual void run() = 0;
        virtual void test() = 0;

    protected:
        virtual void part1() = 0;

        void loadInput(const std::string& filename){
            this->input = utils::parseFile(filename);
        }

        int day;
        std::vector<std::string> input;
    };
}

#endif //AOC2023_DAY_H
