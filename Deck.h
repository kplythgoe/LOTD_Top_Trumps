#ifndef __DECK_H__
#define __DECK_H__
#include <vector>
#include <string>
#include "Card.h"

using namespace std;

class Deck
{
    vector<Card> pack;
public:
    Deck();
    ~Deck();
    void addCards(string name, string culture, string info, float ringResistance, float height, int id, int age, int resilience, int ferocity, int magic, int feet, int inches);
    void displayCards() const;
    int sizeOfDeck() const;
    vector<Card> getVector();
    void deal(Deck mainPack, int randomNumber);
};

#endif // __DECK_H__
