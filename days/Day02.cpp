//
//

#include <iostream>
#include "Day02.h"

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

void Day02::run() {
    this->loadInput("../input/02.txt");
    this->part1();

    this->part2();
}

void Day02::test() {
    this->loadInput("../input/02_test.txt");
    this->part1();

    this->part2();
}

void Day02::part1() {
    int total = 0;

    for (const auto& currentInput: this->input) {
        std::vector<std::string> split = utils::splitString(':', currentInput);

        // Get game Id
        int gameId = std::stoi(split[0].substr(4));

        // Get game results
        std::vector<std::string> rawResults = utils::splitString(';',split[1]);
        std::vector<Day02::GameResult> gameResults = Day02::parseGameResults(rawResults);

        bool gameImpossible = false;
        for (const auto& gameResult: gameResults) {
            if(gameResult.red > MAX_RED){
                gameImpossible = true;
            }

            if(gameResult.green > MAX_GREEN){
                gameImpossible = true;
            }

            if(gameResult.blue > MAX_BLUE){
                gameImpossible = true;
            }
        }

        if(!gameImpossible){
            total += gameId;
        }
    }

    std::cout << "total ids : " << total << "\n";
}

void Day02::part2() {
    int total = 0;

    for (const auto& currentInput: this->input) {
        std::vector<std::string> split = utils::splitString(':', currentInput);

        // Get game Id
        int gameId = std::stoi(split[0].substr(4));

        // Get game results
        std::vector<std::string> rawResults = utils::splitString(';',split[1]);
        std::vector<Day02::GameResult> gameResults = Day02::parseGameResults(rawResults);

        size_t maxRed = 0;
        size_t maxGreen = 0;
        size_t maxBlue = 0;

        for (const auto& gameResult: gameResults) {
            if(gameResult.red > maxRed){
                maxRed = gameResult.red;
            }

            if(gameResult.green > maxGreen){
                maxGreen = gameResult.green;
            }

            if(gameResult.blue > maxBlue){
                maxBlue = gameResult.blue;
            }
        }
        total += (maxRed * maxGreen * maxBlue);
    }

    std::cout << "total powers : " << total << "\n";
}

std::vector<Day02::GameResult> Day02::parseGameResults(const std::vector<std::string> &rawResults) {
    std::vector<Day02::GameResult> gameResults = {};

    for (const auto& rawResult: rawResults) {
        std::vector<std::string> rawPulls = utils::splitString(',', rawResult);

        Day02::GameResult gameResult;

        for (const auto& rawPull: rawPulls) {
            std::vector<std::string> test = utils::splitString(' ', rawPull);

            if(test[2] == "red"){
                gameResult.red = std::stoi(test[1]);
            } else if (test[2] == "green"){
                gameResult.green = std::stoi(test[1]);
            } else if (test[2] == "blue"){
                gameResult.blue = std::stoi(test[1]);
            }
        }

        gameResults.push_back(gameResult);
    }

    return gameResults;
}
