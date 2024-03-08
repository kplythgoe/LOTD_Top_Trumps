#include "Card.h"
#include <iostream>
#include <iomanip>

using namespace std;

Card::Card(int id, string name, string culture, float ringResistance, int age, int resilience, int ferocity, int magic, int feet, int inches, float height, string info)
    :id(id), name(name), culture(culture), ringResistance(ringResistance), age(age), resilience(resilience), ferocity(ferocity), magic(magic), feet(feet), inches(inches), height(height), info(info){
}

Card::Card(const Card &source)
    :Card(source.id, source.name, source.culture, source.ringResistance, source.age, source.resilience, source.ferocity, source.magic, source.feet, source.inches, source.height, source.info){
}

Card::~Card()
{
}

void Card::displayCard() const {
    cout << setw(30) << left << name;
    cout << setw(30) << culture;
    cout << setw(16) << right << ringResistance;
    cout << setw(8) << age;
    cout << setw(14) << resilience;
    cout << setw(14) << ferocity;
    cout << setw(8) << magic;
    cout << setw(7) << right << feet << "'" << inches << "\"" << endl;
}

