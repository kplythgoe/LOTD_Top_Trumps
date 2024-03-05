#include "Deck.h"
#include <iostream>

Deck::Deck()
{
}

Deck::~Deck()
{
}

void Deck::sayHello() {
    cout << "Hello world" << endl;
}

void Deck::addCards(string name, string culture, float ringResistance, int age, int resilience, int ferocity, int magic, int feet, int inches, float height, string info) {
    Card temp {name, culture, ringResistance, age, resilience, ferocity, magic, feet, inches, height, info};
    pack.push_back(temp);
}

void Deck::displayCards() const {
    for (const auto &card : pack) {
        card.displayCard();
    }
}

void Deck::show(vector <string> namesVec) const {
    for (const auto &card : pack) {
        namesVec.push_back(card.getName());
    }
}

int Deck::sizeOfDeck() const {
    return pack.size();
}



