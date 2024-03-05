#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include "Deck.h"

using namespace std;

void rules();
void enterChoiceMessage();
void choiceValidation(int &userChoice);

int main() {
    // CHECKING FILE CAN BE OPENED
    ifstream in_file {"LOTR_Top_Trumps//LOTR-TT.csv", ios::in };
    if (in_file.is_open()) {
    } else {
       cout << "Could not find file";
    }
    
    // CREATING DECK AND READING AND INSERTING INTO DECK FROM FILE
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
    
    // MAIN MENU
    cout << "Top Trumps - The Lord of the Rings Edition" << endl;
    cout << "==========================================\n" << endl;
    cout << "Do you know how to play?\n" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    enterChoiceMessage();
    int userChoice = 0;
    choiceValidation(userChoice);
    if (userChoice == 2) {
        rules();
    }
    cout << "\nGet Ready!\n" << endl;
    system("pause");
    system("cls");
    cout << "Please enter your name: ";
    string userName;
    cin.ignore();
    getline(cin, userName);
    cout << "\nHow many other AI players do you want to play with: ";
    int players;
    while(!(cin >> players)) {
        cout << "Please enter a valid number: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout << "You have selected " << players << " players. This means there are " << players + 1 << " including yourself." << endl;
    players++;
    
    // CREATING PLAYER DECKS
    vector<Deck> allPlayers;
    vector<string> names;
    for (int i = 0; i < players; i++) {
        Deck player;
        allPlayers.push_back(player);
    }
    
    cards.show(names);
    if (names.empty()) {
        cout << "Names vector is empty" << endl;
    } 
    for (auto n : names) {
        cout << n << endl;
    }
//    for (size_t i = 0; i < names.size(); i++) {
//        cout << i + 1 << ". " << names[i] << endl;
//    }
    // DEALING THE CARDS - need to find a way to iterate through main deckand push deck objects into player decks
    // Something like
    //allPlayers[1].addCards("Aragorn", "Human", 1, 1, 1, 1, 1, 1, 1, 1.1, "Example");
//    allPlayers[1].addCards(// a card from cards deck);
    return 0;
}

void enterChoiceMessage() {
    cout << "\nPlease enter your choice by the number from the options above: "; 
}

void choiceValidation(int &userChoice) {
    while(!(cin >> userChoice) || (userChoice != 1 && userChoice != 2)) {
        enterChoiceMessage();
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
}

void rules() {
    cout << "\nRULES OF TOP TRUMPS" << endl;
    cout << "==================" << endl;
    cout << "Cards are randomly dealt evenly among players A player is chosen at random to start and will choose an attribute from their top card. The other players will then read out the same attribute. The one with the best of highest value wins and places all cards from the round to the bottom of their deck. It is then that players turn to choose an attribute from their top card\n" << endl;
    
    cout << "If two or more cards share the top value or data is not available for that particular attribute then the cards will remain in the pile. The same player will choose another attribute from their next card and the winner takes all card from this round, and the previous round\n" << endl;
    
    cout << "The person with all the cards at the end is the winner" << endl;
}
