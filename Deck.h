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
    void sayHello();
    void addCards(int id, string name, string culture, float ringResistance, int age, int resilience, int ferocity, int magic, int feet, int inches, float height, string info);
    void displayCards() const;
    void pushCard(Deck playerDeck);
    int sizeOfDeck() const;
    void showTop() const;
    int getAttribute(int attNum);
    int test() const;
    void remove();

};

#endif // __DECK_H__
