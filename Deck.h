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
    void addCards(int id, string name, string culture, float ringResistance, int age, int resilience, int ferocity, int magic, int feet, int inches, float height, string info);
    void displayCards() const;
    int sizeOfDeck() const;
    
};

#endif // __DECK_H__
