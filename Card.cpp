#include "Card.h"
#include <iostream>
#include <iomanip>

using namespace std;

Card::Card(string name, string culture, float ringResistance, int age, int resilience, int ferocity, int magic, int feet, int inches, float height, string info)
    :name(name), culture(culture), ringResistance(ringResistance), age(age), resilience(resilience), ferocity(ferocity), magic(magic), feet(feet), inches(inches), height(height), info(info){
}

Card::Card(const Card &source)
    :Card(source.name, source.culture, source.ringResistance, source.age, source.resilience, source.ferocity, source.magic, source.feet, source.inches, source.height, source.info){
}

Card::~Card()
{
}

void Card::displayCard() const {
    cout << setw(25) << left << "Name: " << name << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    cout << setw(25) << "Culture: " << culture << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    cout << setw(25) << "Resistance to Ring: " << ringResistance << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    cout << setw(25) << "Age: " << age << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    cout << setw(25) << "Resilience: " << resilience << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    cout << setw(25) << "Ferocity: " << ferocity << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    cout << setw(25) << "Magic: " << magic << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    cout << setw(25) << "Height: " << feet << "'" << inches << "\"" << endl;
    cout << endl;
}

string Card::getName() const {
    return name;
}

