#ifndef __CARD_H__
#define __CARD_H__
#include <string>
#include <vector>

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
    Card(Card &source);
    ~Card();
    void displayCard() const;
    int getRingResistance() const;
    int getAge() const;
    int getResilience() const;
    int getFerocity() const;
    int getMagic() const;
    float getHeight() const;

};

#endif // __CARD_H__
