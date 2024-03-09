#ifndef __CARD_H__
#define __CARD_H__
#include <string>
#include <vector>

using namespace std;

class Card
{
    string name, culture, info;
    float ringResistance, height;
    int id, age, resilience, ferocity, magic, feet, inches;
    
public:
    Card(string name, string culture, string info, float ringResistance, float height, int id, int age, int resilience, int ferocity, int magic, int feet, int inches);
    Card(const Card &source);
    ~Card();
    void displayCard() const;

};

#endif // __CARD_H__
