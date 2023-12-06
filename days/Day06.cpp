//
//

#include "Day06.h"

void Day06::run() {
    //this->loadInput("../input/06.txt");
    //this->part1();

    this->loadInput("../input/06_2.txt");
    this->part1();
}

void Day06::test() {
    //this->loadInput("../input/06_test.txt");
    //this->part1();

    this->loadInput("../input/06_2_test.txt");
    this->part1();
}

void Day06::part1() {
    std::vector<long long> times = {};
    std::vector<long long> distances = {};

    std::string timeInput = this->input[0];
    std::vector<std::string> timeSplit = utils::splitString(':',timeInput);
    for (auto& number: utils::splitString(' ', timeSplit[1])) {
        if(!number.empty()){
            times.push_back(std::stoll(number));
        }
    }

    std::string distanceInput = this->input[1];
    std::vector<std::string> distanceSplit = utils::splitString(':',distanceInput);
    for (auto& number: utils::splitString(' ', distanceSplit[1])) {
        if(!number.empty()){
            distances.push_back(std::stoll(number));
        }
    }

    int total = 1;

    for (int i = 0; i < times.size(); ++i) {
        long long time = times[i];
        long long distance = distances[i];
        int nbrOfWays = 0;

        for (int j = 1; j < time; ++j) {
            int hold = j;
            long long race = time - j;

            if(hold * race > distance){
                nbrOfWays++;
            }
        }

        total *= nbrOfWays;
    }

    std::cout << "total : " << total << "\n";
}

void Day06::part2() {

}
