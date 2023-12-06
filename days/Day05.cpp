//
//

#include "Day05.h"
#include <algorithm>
#include <iostream>

void Day05::run() {
    this->loadInput("../input/05.txt");
    this->part1();
}

void Day05::test() {
    this->loadInput("../input/05_test.txt");
    this->part1();
}

void Day05::part1() {
    //std::vector<long long> seeds = {};
    std::vector<SeedRange> seeds = {};

    std::string seedsInput = this->input[0];
    std::vector<std::string> seedSplit = utils::splitString(' ', seedsInput);

    long long first = 0;
    long long second = 0;


    for (auto& str: seedSplit) {
        if(str != "seeds:"){
            if(first == 0){
                first = std::stoll(str);
            } else if(second == 0){
                second = std::stoll(str);
            } else {
                SeedRange seedRange = SeedRange(first, second);
                seeds.push_back(seedRange);
                first = 0;
                second = 0;
            }

            //seeds.push_back(std::stoll(str));
        }
    }

    std::vector<Mapping>* storeIn = nullptr;
    std::vector<Mapping> seedSoilMapping = {};
    std::vector<Mapping> soilToFertilizerMapping = {};
    std::vector<Mapping> fertilizerToWaterMapping = {};
    std::vector<Mapping> waterToLightMapping = {};
    std::vector<Mapping> lightToTempMapping = {};
    std::vector<Mapping> tempToHumidityMapping = {};
    std::vector<Mapping> humidityToLocationMapping = {};

    for (int i = 1; i < this->input.size(); ++i) {
        std::string currentInput = this->input[i];

        // Skip empty lines
        if(currentInput.empty()){
            continue;
        }

        if(currentInput == "seed-to-soil map:"){
            storeIn = &seedSoilMapping;
        } else if(currentInput == "soil-to-fertilizer map:"){
            storeIn = &soilToFertilizerMapping;
        } else if(currentInput == "fertilizer-to-water map:"){
            storeIn = &fertilizerToWaterMapping;
        } else if(currentInput == "water-to-light map:"){
            storeIn = &waterToLightMapping;
        } else if(currentInput == "light-to-temperature map:"){
            storeIn = &lightToTempMapping;
        } else if(currentInput == "temperature-to-humidity map:"){
            storeIn = &tempToHumidityMapping;
        }else if(currentInput == "humidity-to-location map:"){
            storeIn = &humidityToLocationMapping;
        } else {
            std::vector<std::string> numbersInput = utils::splitString(' ', currentInput);
            long long destStart = std::stoll(numbersInput[0]);
            long long sourceStart = std::stoll(numbersInput[1]);
            int length = std::stoi(numbersInput[2]);

            storeIn->push_back(Mapping(sourceStart,destStart, length));
        }
    }

    std::vector<long long> locations = {};
    for (auto& seed: seeds) {
        for (long long i = seed.start; i < seed.length; ++i) {
            long long next = getNextFromMapping(i , &seedSoilMapping);
            next = getNextFromMapping(next, &soilToFertilizerMapping);
            next = getNextFromMapping(next, &fertilizerToWaterMapping);
            next = getNextFromMapping(next, &waterToLightMapping);
            next = getNextFromMapping(next, &lightToTempMapping);
            next = getNextFromMapping(next, &tempToHumidityMapping);
            next = getNextFromMapping(next, &humidityToLocationMapping);

            locations.push_back(next);
        }
    }

    std::cout << "Min location : " << *std::min_element(locations.begin(), locations.end()) << "\n";
}

void Day05::part2() {

}

long long Day05::getNextFromMapping(long long source, std::vector<Mapping> *mapVector) {

    for (auto& map: *mapVector) {
        if(source >= map.source && source <= map.source + map.length){
            long long offset = source - map.source;

            return map.destination + offset;
        }
    }
    return source;
}
