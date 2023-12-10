//
//

#ifndef AOC2023_DAY08_H
#define AOC2023_DAY08_H

#include "../core/Day.h"
#include <map>

struct Node {
    Node(const std::string& label, Node *right, Node *left) : label(label), right(right), left(left) {}
    std::string label;
    Node* right;
    Node* left;
};

class Day08: public aoc::Day {
public:
    void run() override;

    void test() override;

protected:
    void part1() override;

    void part2() override;
private:
    std::map<std::string, Node> lookAtThisGraph();
};


#endif //AOC2023_DAY08_H
