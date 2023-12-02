//
//

#ifndef AOC2023_DAY01_H
#define AOC2023_DAY01_H

#include "../core/Day.h"

class Day01: public aoc::Day {
public:
    void run();

    void test();

protected:
    void part1();
    void part2();
private:
    static void findFirstAndLastDigitsPosition(const std::string& input, size_t &first, size_t &last);

    static inline char convertSpelledDigit(std::string& spelledDigit){
        // This is cursed...

        char returnedChar;
        if(spelledDigit == "one"){
            returnedChar = '1';
        } else if(spelledDigit == "two"){
            returnedChar = '2';
        } else if(spelledDigit == "three"){
            returnedChar = '3';
        } else if(spelledDigit == "four"){
            returnedChar = '4';
        } else if(spelledDigit == "five"){
            returnedChar = '5';
        } else if(spelledDigit == "six"){
            returnedChar = '6';
        } else if(spelledDigit == "seven"){
            returnedChar = '7';
        } else if(spelledDigit == "eight"){
            returnedChar = '8';
        } else if(spelledDigit == "nine"){
            returnedChar = '9';
        }

        return returnedChar;
    }
};


#endif //AOC2023_DAY01_H
