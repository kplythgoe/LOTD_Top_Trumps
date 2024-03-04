#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Deck.h"

using namespace std;

int main() {
    ifstream in_file {"LOTR_Top_Trumps//LOTR-TT.csv", ios::in };
    if (in_file.is_open()) {
    } else {
       cout << "Could not find file";
    }
    
    Deck cards;
    string line = "";
    while (getline(in_file, line)) {
        string name, culture, info;
        int ringResistance, age, resilience, ferocity, magic, feet, inches;
        float height;
        string tempString = "";
        
        stringstream inputString(line);
        
        getline(inputString, name, ',');
        getline(inputString, culture, ',');
        
        getline(inputString, tempString, ',');
        ringResistance = atoi(tempString.c_str());
        
        tempString = "";
        getline(inputString, tempString, ',');
        age = atoi(tempString.c_str());
        
        tempString = "";
        getline(inputString, tempString, ',');
        resilience = atoi(tempString.c_str());
        
        tempString = "";
        getline(inputString, tempString, ',');
        ferocity = atoi(tempString.c_str());
        
        tempString = "";
        getline(inputString, tempString, ',');
        magic = atoi(tempString.c_str());
        
        tempString = "";
        getline(inputString, tempString, ',');
        feet = atoi(tempString.c_str());
        
        tempString = "";
        getline(inputString, tempString, ',');
        inches = atoi(tempString.c_str());
        
        tempString = "";
        getline(inputString, tempString, ',');
        height = atof(tempString.c_str());
        
        cards.addCards(name, culture, ringResistance, age, resilience, ferocity, magic, feet, inches, height, info);
        line = "";
    }
    
//    while (!in_file.eof()) {
//        string name, culture, info;
//        int ringResistance, age, resilience, ferocity, magic;
//        float height;
//        in_file >> name >> culture >> ringResistance >> age >> resilience >> ferocity >> magic >> height >> info;
//        cout << name << culture << ringResistance << age << resilience << ferocity << magic << height <<  info;
//        cards.addCards(name, culture, ringResistance, age, resilience, ferocity, magic, height, info);
//    }
//    cards.addCards("Aragorn", "Human", 1, 1, 1, 1, 1, 5.5, "example"); 
    cards.displayCards();
    return 0;
}
