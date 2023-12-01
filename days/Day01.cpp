//
//

#include <iostream>
#include "Day01.h"

void Day01::run() {
    this->loadInput("../input/01.txt");
    this->part1();
}

void Day01::test() {
    this->loadInput("../input/01_test.txt");
    this->part1();
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

    std::cout << "PART 1 : " << total;
}