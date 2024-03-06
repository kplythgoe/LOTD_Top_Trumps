#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <chrono>
#include <thread>
#include <ctime>
#include <cmath>
#include <string>
#include <map>
#include <sstream>
#include "Deck.h"

using namespace std;

void rules();
void enterChoiceMessage();
void choiceValidation(int &userChoice);
void pushCards(Deck &pack, int randomNumber, bool dealing);

int main() {

    
    // CREATING DECK AND READING AND INSERTING INTO DECK FROM FILE
    Deck cards;
    srand((unsigned) time(0));
    int randomNumber = 0;
    bool dealing = false;
    pushCards(cards, randomNumber, dealing);
    dealing = true;

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
    float players;
    while(!(cin >> players)) {
        cout << "Please enter a valid number: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout << "\nYou have selected " << players << " players. This means there are " << players + 1 << " players including yourself." << endl;
    players++;
    
    // CREATING PLAYER DECKS
    vector<Deck> allPlayers;
    for (int i = 0; i < players; i++) {
        Deck player;
        allPlayers.push_back(player);
    }
   
    // DEALING CARDS
    vector <int> usedNumbers;
    int cnt;
    int tries;
    for (int i = 0; i < ceil(cards.sizeOfDeck()/players); i++) {
        for (int j = 0; j < players; j++) {
            tries = 0;
            randomNumber = (rand() % cards.sizeOfDeck()) + 1;
            cnt = count(usedNumbers.begin(), usedNumbers.end(), randomNumber);
            while (cnt > 0) {
                if (tries > cards.sizeOfDeck()) {
                    break;
                }
                randomNumber = (rand() % cards.sizeOfDeck()) + 1;
                cnt = count(usedNumbers.begin(), usedNumbers.end(), randomNumber);
                tries ++;
            }
            if (tries > cards.sizeOfDeck()) {
                break;
            }
            usedNumbers.push_back(randomNumber);
            pushCards(allPlayers[j], randomNumber, dealing);
        }
    }
    int participants = (int)players;
    randomNumber = (rand() % participants) + 0;
    randomNumber == 0 ? cout << "\nYou" : cout << "\nPlayer " << randomNumber + 1;
    cout << " will go first" << endl << endl;
    system("pause");
    system("cls");
    cout << "Their top card is... " << endl << endl;
    // name, culture, ring res, age, resil, feroc, magic, feet, inches
    cout << setw(20) << left << "Name";
    cout << setw(30) << "Culture";
    cout << setw(16) << right << "Ring Resistance";
    cout << setw(8) << "Age";
    cout << setw(14) << "Resilience";
    cout << setw(14) << "Ferocity";
    cout << setw(8) << "Magic";
    cout << setw(8) << "Height" << endl;
    cout << setfill('=') << setw(118) << "" << setfill(' ') << endl;
    allPlayers[randomNumber].showTop();
    
    map <string, int> attributeChoice;
    attributeChoice["Ring Resistance"] = 1; attributeChoice["Age"] = 2; attributeChoice["Resilience"] = 3; attributeChoice["Ferocity"] = 4; attributeChoice["Magic"] = 5; attributeChoice["Height"] = 6;
    randomNumber = (rand() % 6) + 1;
    cout << "\nThe chosen attribute is: ";
    map<string, int>::iterator it = attributeChoice.begin();
    while (it != attributeChoice.end()) {
        if (randomNumber == it->second) {
            cout << it->first << endl;
        }
        it++;
    }
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

void pushCards(Deck &pack, int randomNumber, bool dealing) {
    // CHECKING FILE CAN BE OPENED
    ifstream in_file {"LOTR_Top_Trumps//LOTR-TT.csv", ios::in };
    if (in_file.is_open()) {
    } else {
       cout << "Could not find file";
    }
    string line = "";
    while (getline(in_file, line)) {
        string name, culture, info;
        int id, age, resilience, ferocity, magic, feet, inches;
        float height, ringResistance;
        string tempString = "";
        
        stringstream inputString(line);
        
        tempString = "";
        getline(inputString, tempString, ',');
        id = atoi(tempString.c_str());
        if (id == randomNumber || !dealing) {
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
            
            pack.addCards(id, name, culture, ringResistance, age, resilience, ferocity, magic, feet, inches, height, info);
            
            line = "";
        }
    }
}
