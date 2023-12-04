//
//

#include "Day03.h"
#include <string>

void Day03::run() {
    this->loadInput("../input/03.txt");
    this->part1();
}

void Day03::test() {
    this->loadInput("../input/03_test.txt");
    this->part1();
}

void Day03::part1() {
    std::vector<Day03::Number*> numbers = {};
    std::vector<Day03::Symbol> symbols = {};
    std::vector<std::vector<char>> grid = {};

    for (int i = 0; i < this->input.size(); ++i) {
        std::string currentInput = this->input[i];
        std::vector<char> row = {};

        std::string temp;
        auto *startPoint = new utils::Point(0,0);
        auto *currentPoint = new utils::Point(0,0);
        for (int j = 0; j < currentInput.size(); ++j) {
            char currentChar = currentInput[j];
            row.push_back(currentChar);
            currentPoint = new utils::Point(i,j);

            // If is symbol
            if(!std::isdigit(currentChar) && currentChar != '.'){
                symbols.emplace_back(currentChar, *currentPoint);
            }

            if(std::isdigit(currentChar)){
                if(temp.empty()){
                    startPoint->x = i;
                    startPoint->y = j;
                }
                temp.push_back(currentChar);
            } else if(!temp.empty()) {
                numbers.push_back(new Number(std::stoi(temp),*startPoint,*currentPoint));
                temp = "";
            }
        }

        if(!temp.empty()) {
            numbers.push_back(new Number(std::stoi(temp),*startPoint,*currentPoint));
            temp = "";
        }
        grid.push_back(row);
        delete currentPoint;
        delete startPoint;
    }

    int gearRatios = 0;

    for (auto symbol: symbols) {
        // Look around symbol position
        for (int i = symbol.position.x - 1; i <= symbol.position.x + 1; ++i) {
            for (int j = symbol.position.y - 1; j <= symbol.position.y + 1; ++j) {
                if(std::isdigit(grid[i][j])){
                    for (auto number:numbers) {
                        if(number->start.y <= j && number->end.y >= j && number->start.x == i){
                            number->isPartNumber = true;
                            symbol.adj.insert(number);
                        }
                    }
                }
            }
        }

        if(symbol.symbol == '*' && symbol.adj.size() == 2){
            int temp = 0;
            for (auto adj: symbol.adj) {
                if(temp == 0){
                    temp = adj->number;
                } else {
                    temp = temp * adj->number;
                }
            }
            gearRatios += temp;
        }
    }

    int total = 0;
    for (auto number:numbers) {
        if(number->isPartNumber){
            total += number->number;
        }
        delete number;
    }
    numbers.clear();

    std::cout << "total parts : " << total << "\n";
    std::cout << "total gear ratio : " << gearRatios << "\n";
}

void Day03::part2() {
    // included in part 1
}
