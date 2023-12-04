//
//

#include "Day04.h"
#include <unordered_set>
#include <cmath>

void Day04::run() {
    this->loadInput("../input/04.txt");
    this->part1();
}

void Day04::test() {
    this->loadInput("../input/04_test.txt");
    this->part1();
}

void Day04::part1() {
    double total = 0;

    for (const auto& currentInput: this->input) {
        std::vector<std::string> card = utils::splitString(':',currentInput);
        std::vector<std::string> numbers = utils::splitString('|',card[1]);

        // Set hashmap of winning numbers
        std::unordered_set<std::string> winningNumbers;
        for (auto& number:utils::splitString(' ',numbers[0])) {
            if(!number.empty()){
                winningNumbers.insert(number);
            }
        }

        // Check have numbers
        int nbrOfWinningNumbers = 0;
        for (auto& number:utils::splitString(' ',numbers[1])) {
            if(!number.empty()){
                if(winningNumbers.find(number) != winningNumbers.end()){
                    nbrOfWinningNumbers++;
                }
            }
        }

        double totalPerCard = 0;

        if(nbrOfWinningNumbers > 0){
            totalPerCard = pow(2.0,nbrOfWinningNumbers - 1);
        }

        total += totalPerCard;
    }

    std::cout << "total : " << total << "\n";
}

void Day04::part2() {

}
