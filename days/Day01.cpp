//
//

#include <iostream>
#include "Day01.h"

void Day01::run() {
    this->loadInput("../input/01.txt");
    //this->part1();
    this->part2();
}

void Day01::test() {
    //this->loadInput("../input/01_test.txt");
    //this->part1();

    this->loadInput("../input/01_2_test.txt");
    this->part2();
}

void Day01::part1() {
    int total = 0;
    for (auto currentInput : this->input) {
        size_t front = 0;
        size_t back = currentInput.size() - 1;
        bool found = false;

        while(!found){
            if(front >= back){
                found = true;
            } else {

                if(!std::isdigit(currentInput[front])){
                    front++;
                }


                if(!std::isdigit(currentInput[back])){
                    back--;
                }

                if(std::isdigit(currentInput[front]) && std::isdigit(currentInput[back])){
                    found = true;
                }
            }
        }

        char firstDigit = currentInput[front];
        char secondDigit = currentInput[back];

        std::stringstream ss;

        ss << firstDigit << secondDigit;

        total += std::stoi(ss.str());
        ss.clear();
    }

    std::cout << "PART 1 : " << total << "\n";
}

void Day01::part2() {
    int total = 0;
    for (auto currentInput : this->input) {

        // Handle spelled digits
        std::vector<std::string> spelledDigits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        std::string firstSpelledDigit;
        size_t firstSpelledDigitPosition = SIZE_MAX;

        std::string lastSpelledDigit;
        size_t lastSpelledDigitPosition = 0;

        for (auto digit: spelledDigits) {
            size_t firstPos = currentInput.find(digit);
            if(firstPos < firstSpelledDigitPosition){
                firstSpelledDigit = digit;
                firstSpelledDigitPosition = firstPos;
            }

            size_t lastPos = currentInput.rfind(digit);
            if(lastPos != std::string::npos && lastPos > lastSpelledDigitPosition) {
                lastSpelledDigit = digit;
                lastSpelledDigitPosition = lastPos;
            }
        }


        // Handle digits
        size_t front = 0;
        size_t back = currentInput.size() - 1;
        bool found = false;

        while(!found){
            if(front >= back){
                found = true;
            } else {

                if(!std::isdigit(currentInput[front])){
                    front++;
                }


                if(!std::isdigit(currentInput[back])){
                    back--;
                }

                if(std::isdigit(currentInput[front]) && std::isdigit(currentInput[back])){
                    found = true;
                }
            }
        }

        char firstDigit;
        char secondDigit;

        if(firstSpelledDigitPosition < front){
            firstDigit = convertSpelledDigit(firstSpelledDigit);
        } else {
            firstDigit = currentInput[front];
        }

        if(lastSpelledDigitPosition > back){
            secondDigit = convertSpelledDigit(lastSpelledDigit);
        } else {
            secondDigit = currentInput[back];
        }

        //std::cout << "[" << currentInput << " : " << firstDigit << secondDigit << "]\n";
        std::stringstream ss;

        ss << firstDigit << secondDigit;

        total += std::stoi(ss.str());
        ss.clear();
    }

    std::cout << "PART 2 : " << total << "\n";
}