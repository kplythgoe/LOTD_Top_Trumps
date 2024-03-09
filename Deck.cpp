#include "Deck.h"
#include <iostream>
#include <vector>

Deck::Deck()
{
}

Deck::~Deck()
{
}

void Deck::addCards(string name, string culture, string info, float ringResistance, float height, int id, int age, int resilience, int ferocity, int magic, int feet, int inches) {
    Card temp {name, culture, info, ringResistance, height, id, age, resilience, ferocity, magic, feet, inches};
    pack.push_back(temp);
}

void Deck::displayCards() const {
    for (const auto &card : pack) {
        card.displayCard();
    }
}

int Deck::sizeOfDeck() const {
    return pack.size();
}

vector<Card> Deck::getVector() {
    return pack;
}

void Deck::deal(Deck mainPack, int randomNumber) {
    vector temp = mainPack.getVector();
    //random number --> if random number matches iteration counter --> do the below, otherwise don't
    int counter = 0;
    bool cardFound = false;
    while (!cardFound) {
        if (randomNumber == counter) {
            Card chosen = temp[randomNumber];
            pack.push_back(chosen);
            cardFound = true;
        }
        counter ++;
    }
}

