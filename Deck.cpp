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

void Deck::addCards(int id, string name, string culture, float ringResistance, int age, int resilience, int ferocity, int magic, int feet, int inches, float height, string info) {
    Card temp {id, name, culture, ringResistance, age, resilience, ferocity, magic, feet, inches, height, info};
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

void Deck::showTop() const {
    int i = 0;
    for (const auto &card : pack) {
        if (i > 0) {
            break;
        }
        card.displayCard();
        i++;
    }
}



