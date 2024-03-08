#include "Deck.h"
#include <iostream>
#include <vector>

Deck::Deck()
{
}

Deck::~Deck()
{
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

