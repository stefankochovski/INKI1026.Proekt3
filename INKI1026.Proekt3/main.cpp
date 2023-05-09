#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

int generateRandomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}

std::vector<std::string> drawCards() {
    std::vector<std::string> cards;

    std::vector<std::string> suits = {"Srce", "Lokum", "Detelina", "Pik"};
    std::vector<std::string> values = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Dzandar", "Dama", "Pop"};

    while (cards.size() < 5) {
        int suitIndex = generateRandomNumber(0, suits.size() - 1);
        int valueIndex = generateRandomNumber(0, values.size() - 1);

        std::string card = suits[suitIndex] + " " + values[valueIndex];

        bool isDuplicate = false;
        for (const std::string& drawnCard : cards) {
            if (drawnCard == card) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            cards.push_back(card);
        }
    }

    return cards;
}

int main() {

    std::cout << std::endl;
    std::cout << "5te IZVLECENI KARTI" << std::endl;
    std::cout << "...................." << std::endl;
    std::cout << std::endl;

    srand(time(0));

    std::vector<std::string> hand = drawCards();

    for (const std::string& card : hand) {
        std::cout << card << std::endl;

    }

    std::cout << std::endl;
    std::cout << "...................." << std::endl;


   std::ofstream outputFile("5te_izvleceni_karti.txt");
    if (outputFile.is_open()) {
        for (const std::string& card : hand) {
            outputFile << card << std::endl;
        }
        outputFile.close();
    } else {
        std::cout << "Otvaranjeto na dadotekata ne e uspesno." << std::endl;
    }


    return 0;
}
