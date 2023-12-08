//
//

#include "Day07.h"
#include <map>
#include <algorithm>

std::map<char,int> labels = {
        std::make_pair('A', 1),
        std::make_pair('K', 2),
        std::make_pair('Q', 3),
        std::make_pair('J', 4),
        std::make_pair('T', 5),
        std::make_pair('9', 6),
        std::make_pair('8', 7),
        std::make_pair('7', 8),
        std::make_pair('6', 9),
        std::make_pair('5', 10),
        std::make_pair('4', 11),
        std::make_pair('3', 12),
        std::make_pair('2', 13),
};

struct Hand {
    Hand(const std::string &hand, int bid) : hand(hand), bid(bid) {}
    std::string hand;
    int bid = 0;
};



bool sortHands(const Hand& h1, const Hand& h2){
    for (int i = 0; i < h1.hand.size(); ++i) {
        char card1 = h1.hand[i];
        char card2 = h2.hand[i];
        if(labels[card1] > labels[card2]){
            return true;
        } else if(labels[card1] < labels[card2]){
            return false;
        }
    }

    return false;
}

void Day07::run() {
    this->loadInput("../input/07.txt");
    this->part1();
}

void Day07::test() {
    this->loadInput("../input/07_test.txt");
    this->part1();
}

void Day07::part1() {
    std::vector<Hand> fiveOfKind = {};
    std::vector<Hand> fourOfKind = {};
    std::vector<Hand> fullHouse = {};
    std::vector<Hand> threeOfKind = {};
    std::vector<Hand> twoPairs = {};
    std::vector<Hand> onePair = {};
    std::vector<Hand> highCard = {};
    std::vector<Hand>* correctHandType = &highCard;

    for (auto& currentInput: this->input) {
        std::vector<std::string> split = utils::splitString(' ', currentInput);
        Hand currentHand(split[0], std::stoi(split[1]));
        std::map<char,int> cardCount;
        for (auto& card: currentHand.hand) {

            auto it = cardCount.find(card);
            if(it != cardCount.end()){
                it->second++;
            } else {
                cardCount.insert(std::make_pair(card, 1));
            }
        }

        switch (cardCount.size()) {
            case 5:
                correctHandType = &highCard;
                break;
            case 4:
                correctHandType = &onePair;
                break;
            case 3:
                correctHandType = &twoPairs;
                for (auto& count: cardCount) {
                    if(count.second == 3){
                        correctHandType = &threeOfKind;
                    }
                }
                break;
            case 2:
                correctHandType = &fullHouse;
                for (auto& count: cardCount) {
                    if(count.second == 4){
                        correctHandType = &fourOfKind;
                    }
                }
                break;
            case 1:
                correctHandType = &fiveOfKind;
                break;
        }

        correctHandType->push_back(currentHand);
    }

    int64_t total = 0;
    int rank = 1;
    std::vector<std::vector<Hand>*> types = { &highCard, &onePair, &twoPairs, &threeOfKind, &fullHouse, &fourOfKind, &fiveOfKind};

    for (auto& type:types) {
        std::sort(type->begin(), type->end(), sortHands);

        for (auto& hand: *type) {
            total += hand.bid * rank;
            rank++;
        }
    }
    std::cout << "total : " << total << "\n";
}

void Day07::part2() {

}
