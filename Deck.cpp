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

void Deck::inPlay(Deck playerPack) {
    vector player = playerPack.getVector();
    pack.push_back(player.front());
}

float Deck::battle(int randomNumber) {
    // random number 0 -5 - each number represents an attribute
    if (randomNumber == 0) {
        // get ringResistance - returns float
        return pack.front().getRingResistance();
    }
    else if (randomNumber == 1) {
        // get age - returns int
        return pack.front().getAge();
    }
    else if (randomNumber == 2) {
        // get resilience - returns int
        return pack.front().getResilience();
    }
    else if (randomNumber == 3) {
        // get ferocity - returns int
        return pack.front().getFerocity();
    }
    else if (randomNumber == 4) {
        // get magic - returns int
        return pack.front().getMagic();
    }
    else {
        // get height - returns float
        return pack.front().getHeight();
    }
}

void Deck::topCard() {
    pack.front().displayCard();
}

void Deck::removeCard() {
    pack.erase(pack.begin());
}

