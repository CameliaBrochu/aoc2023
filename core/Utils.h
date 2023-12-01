//
//

#ifndef AOC2023_UTILS_H
#define AOC2023_UTILS_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

namespace utils{
    inline std::vector<std::string> parseFile(const std::string& filename){
        std::vector<std::string> input;

        std::ifstream f(filename, std::ios::in);
        std::string line;

        while(getline(f,line)){
            input.push_back(line);
        }
        f.close();
        return input;
    }
};


#endif //AOC2023_UTILS_H
