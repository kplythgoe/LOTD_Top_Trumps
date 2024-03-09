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
void pushCards(Deck &pack);

int main() {
    srand((unsigned) time(0));
    int randomNumber;
    int cnt;
    vector <int> cardsUsed;
    int players = 5; // for now
    Deck cards;
    vector<string> aiPlayers {"John", "Fred", "Billy", "Rachael", "Maeve", "Houghie"};
    pushCards(cards);
    cards.displayCards();
    cout << endl << endl;
    // DEAL THE CARDS - BY TAKING A RANDOM CARD FROM cards AND PUSHING TO A PLAYER DECK
    
    // CREATING DECKS BASED ON HOW MANY PLAYERS
    vector <Deck> allPlayers;
    for (int i = 0; i < players; i++) {
        Deck player;
        allPlayers.push_back(player);
    }
    // DEALING CARDS FROM CARDS DECK
    for (int i = 0; i < cards.sizeOfDeck()/players; i++) {
        for (int j = 0; j < players; j++) {
            randomNumber = (rand() % cards.sizeOfDeck()) + 0;
            cnt = count(cardsUsed.begin(), cardsUsed.end(), randomNumber);
            while (cnt > 0) {
                randomNumber = (rand() % cards.sizeOfDeck()) + 0;
                cnt = count(cardsUsed.begin(), cardsUsed.end(), randomNumber);
            }
            cardsUsed.push_back(randomNumber);
            allPlayers[j].deal(cards, randomNumber);
        }
    }
    system("pause");
    system("cls");
    cout << "PLAYER 1 CARDS" << endl;
    cout << "==================" << endl;
    allPlayers[0].displayCards();
    cout << endl << endl;
    cout << "PLAYER 2 CARDS" << endl;
    cout << "==================" << endl;
    allPlayers[1].displayCards();
    cout << endl << endl;
    cout << "PLAYER 3 CARDS" << endl;
    cout << "==================" << endl;
    allPlayers[2].displayCards();
    cout << endl << endl;
    cout << "PLAYER 4 CARDS" << endl;
    cout << "==================" << endl;
    allPlayers[3].displayCards();
    cout << endl << endl;
    cout << "PLAYER 5 CARDS" << endl;
    cout << "==================" << endl;
    allPlayers[4].displayCards();
    cout << endl << endl;
    system("pause");
    system("cls");
    allPlayers[0].displayCards();
    cout << endl << endl;
    system("pause");
    system("cls");
    cards.displayCards();
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
void pushCards(Deck &pack) {
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
            
        pack.addCards(name, culture, info, ringResistance, height, id, age, resilience, ferocity, magic, feet, inches);
            
        line = "";

    }
}
