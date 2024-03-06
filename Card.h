#ifndef __CARD_H__
#define __CARD_H__
#include <string>

using namespace std;

class Card
{
    int id;
    string name;
    string culture;
    float ringResistance;
    int age;
    int resilience;
    int ferocity;
    int magic;
    int feet;
    int inches;
    float height;
    string info;
public:
    Card(int id, string name, string culture, float ringResistance, int age, int resilience, int ferocity, int magic, int feet, int inches, float height, string info);
    Card(const Card &source);
    ~Card();
    void displayCard() const;
    string getName() const;

};

#endif // __CARD_H__
