//
//

#include "Day09.h"

#include <algorithm>
#include <functional>
#include <ranges>

int recGetExtrapolatedValue(const std::vector<int>& numbers){
    bool allZeros = true;
    for (const auto& n: numbers) {
        if(n != 0){
            allZeros = false;
            break;
        }
    }

    if(allZeros){
        return 0;
    } else {
        std::vector<int> diffs = {};
        for (int i = 1; i < numbers.size(); ++i) {
            diffs.push_back(numbers[i] - numbers[i-1]);
        }

        int nextValue = recGetExtrapolatedValue(diffs);

        return nextValue + numbers[numbers.size() - 1];
    }
}

int getExtrapolatedValue(const std::vector<int>& numbers){
    return recGetExtrapolatedValue(numbers);
}

void Day09::run() {
    this->loadInput("../input/09.txt");
    this->part1();
}

void Day09::test() {
    this->loadInput("../input/09_test.txt");
    this->part1();
}

void Day09::part1() {
    std::vector<int> extrapolatedValues = {};
    for (const auto& currentInput: this->input) {
        std::vector<std::string> numberStr = utils::splitString(' ', currentInput);
        std::vector<int> numbers = {};

        for (auto& n: numberStr) {
            numbers.push_back(std::stoi(n));
        }

        extrapolatedValues.push_back(getExtrapolatedValue(numbers));
    }

    int total = 0;
    for (const auto& v:extrapolatedValues) {
        total += v;
    }

    std::cout << "total : " << total << "\n";
}

void Day09::part2() {

}
