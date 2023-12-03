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

    struct Point {
        Point(int i, int j){
            x = i;
            y = j;
        }

        int x;
        int y;
    };

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

    inline std::vector<std::string> splitString(char sep, const std::string& s){
        std::vector<std::string> sepString;

        std::string part;
        int count = 0;
        for (char i : s) {
            ++count;
            if(i == sep){
                sepString.push_back(part);
                part = "";
                continue;
            }
            part += i;

            if(count == s.size()){
                sepString.push_back(part);
            }
        }

        return sepString;
    }
};


#endif //AOC2023_UTILS_H
