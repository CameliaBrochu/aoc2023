//
//

#ifndef AOC2023_DAY05_H
#define AOC2023_DAY05_H

#include "../core/Day.h"

class Day05: public aoc::Day {
    struct Mapping{
        Mapping(long long n, long long m, int l): source(n), destination(m), length(l) {}
        long long source;
        long long destination;
        int length;
    };

    struct SeedRange{
        SeedRange(long long int start, long long int length) : start(start), length(length) {}
        long long start;
        long long length;
    };
public:
    void run() override;

    void test() override;

protected:
    void part1() override;

    void part2() override;
private:
    static long long getNextFromMapping(long long source, std::vector<Mapping>* mapVector);
};


#endif //AOC2023_DAY05_H
