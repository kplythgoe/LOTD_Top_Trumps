#include "Card.h"
#include <iostream>
#include <iomanip>

using namespace std;

Card::Card(string name, string culture, string info, float ringResistance, float height, int id, int age, int resilience, int ferocity, int magic, int feet, int inches)
    :name(name), culture(culture), info(info), ringResistance(ringResistance), height(height), id(id), age(age), resilience(resilience), ferocity(ferocity), magic(magic), feet(feet), inches(inches){
}

Card::Card(const Card &source)
    :Card(source.name, source.culture, source.info, source.ringResistance, source.height, source.id, source.age, source.resilience, source.ferocity, source.magic, source.inches, source.feet){
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

float Card::getRingResistance() const {
    return ringResistance;
}

int Card::getAge() const {
    return age;
}

int Card::getResilience() const {
    return resilience;
}

int Card::getFerocity() const {
    return ferocity;
}

int Card::getMagic() const {
    return magic;
}

float Card::getHeight() const {
    return height;
}

