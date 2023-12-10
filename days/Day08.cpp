//
//

#include "Day08.h"
#include <map>

void Day08::run() {
    this->loadInput("../input/08.txt");
    //this->part1();

    this->part2();
}

void Day08::test() {
    this->loadInput("../input/08_test_02.txt");
    //this->part1();

    this->part2();
}

void Day08::part1() {
    std::string instructions = this->input[0];
    std::map<std::string, Node> network = this->lookAtThisGraph();

    int nbrOfSteps = 0;
    Node currentNode = network.begin()->second;

    while(currentNode.label != "ZZZ"){
        for (auto& instruction: instructions) {
            if(currentNode.label == "ZZZ"){
                break;
            }

            nbrOfSteps++;
            if(instruction == 'R'){
                currentNode = *(currentNode.right);
            } else if(instruction == 'L'){
                currentNode = *(currentNode.left);
            }
        }
    }


    std::cout << "total steps : " << nbrOfSteps << "\n";
}

void Day08::part2() {
    std::string instructions = this->input[0];
    std::map<std::string, Node> network = this->lookAtThisGraph();

    std::vector<Node> currentNodes = {};
    for (const auto& pair: network) {
        if(pair.second.label.substr(2,1) == "A"){
            currentNodes.push_back(pair.second);
        }
    }

    int nbrOfSteps = 0;
    int endCount = 0;

    while(endCount != currentNodes.size()){
        for (auto& instruction: instructions) {
            for (auto& currentNode :currentNodes) {
                if(instruction == 'R'){
                    currentNode = *(currentNode.right);
                } else if(instruction == 'L'){
                    currentNode = *(currentNode.left);
                }
            }

            nbrOfSteps++;
            endCount = 0;
            for (const auto& currentNode :currentNodes) {
                if(currentNode.label.substr(2,1) == "Z"){
                    endCount++;
                }
            }

            if(endCount == currentNodes.size()){
                break;
            }
        }
    }

    std::cout << "total steps : " << nbrOfSteps << "\n";
}

std::map<std::string, Node> Day08::lookAtThisGraph() {
    std::map<std::string, Node> network = {};

    for (int i = 2; i < this->input.size(); ++i) {
        std::string currentInput = this->input[i];
        std::string label = currentInput.substr(0,3);
        std::string left = currentInput.substr(7,3);
        std::string right = currentInput.substr(12,3);

        auto it = network.find(right);
        if(it == network.end()){
            Node emptyNode("",nullptr, nullptr);
            network.insert(std::make_pair(right, emptyNode));
        }

        it = network.find(left);
        if(it == network.end()){
            Node emptyNode("",nullptr, nullptr);
            network.insert(std::make_pair(left, emptyNode));
        }

        it = network.find(label);
        if(it == network.end()){
            Node node(label,&(network.at(right)), &(network.at(left)));
            network.insert(std::make_pair(label, node));
        } else {
            Node& node = network.at(label);
            node.label = label;
            node.right = &(network.at(right));
            node.left = &(network.at(left));
        }
    }

    return network;
}
