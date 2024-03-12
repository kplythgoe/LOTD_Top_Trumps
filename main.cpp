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
#include <algorithm>
#include "Deck.h"

using namespace std;

void rules();
void enterChoiceMessage();
void choiceValidation(int &userChoice);
void pushCards(Deck &pack);
void headerLayout();

int main() {
    srand((unsigned) time(0));
    string attribute;
    vector <string> attributes {"Resistance to Ring", "Age", "Resiliance", "Ferocity", "Magic", "Height"};
    int randomNumber;
    int playerTurn;
    int cnt;
    int roundDeckSize;
    int playerLoop;
    vector <int> cardsUsed;
    vector <float> stats;
    int players = 5; // for now
    Deck cards;
    Deck round;
    vector<string> aiNames {"John", "Fred", "Billy", "Rachael", "Maeve", "Houghie"};
    vector<string> aiPlayers;
    bool winner = false;
    bool startGame = true;
    pushCards(cards);
    cards.displayCards();
    cout << endl << endl;
    // CREATING VECTOR OF AI PLAYERS
    for (int i = 0; i < players; i++) {
        aiPlayers.push_back(aiNames[i]);
    }
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
    // RANDOMLY CHOSING WHICH PLAYER WILL GO FIRST (then will go in order)
    playerTurn = (rand() % players) + 0;
    // PLAY THE TOP CARD FROM PLAYERS' HANDS AND CHOSING ATTRIBUTE PLAYED
    while(!winner) {
        startGame ? cout << aiPlayers[playerTurn] << " will go first" : cout << "It's " << aiPlayers[playerTurn] << "'s turn";
        cout << endl << endl;
        headerLayout();
        cout << setw(15) << left << aiPlayers[playerTurn];
        allPlayers[playerTurn].topCard();
        cout << endl << endl;

        randomNumber = (rand() % 6) + 0;
        attribute = attributes[randomNumber];
        cout << "The chosen attribute is: " << attribute;
        cout << endl << endl;
        cout << "Let's see our combatants!\n" << endl;
        system("pause");
        system("cls");
        cout << "The chosen attribute is: " << attribute;
        cout << endl << endl;
        headerLayout();
        
        for (int i = 0; i < players; i++) {
            cout << setw(15) << left << aiPlayers[i];
            allPlayers[i].topCard();
            // PUSHING PLAYED CARDS INTO ROUND DECK
            round.inPlay(allPlayers[i]);
        }
        cout << endl << endl;
        // COMPARING THE ATTRIBUTES AND FINDING A WINNER
        
        for (int i = 0; i < players; i++) {
            stats.push_back(allPlayers[i].battle(randomNumber));
            // REMOVING CARD FROM PLAYERS HAND
            allPlayers[i].removeCard();
        }
        float winningValue = -1;
        for (auto a : stats) {
            if (a > winningValue) {
                winningValue = a;
            }
        }
        cnt = count(stats.begin(), stats.end(), winningValue);
        auto it = find(stats.begin(), stats.end(), winningValue);
        if (cnt > 1) {
            cout << "This round has resulted in a draw\n" << endl;
            cout << "The cards will be given to whoever next wins a round" << endl;
            playerLoop = players;
            for (int i = 0; i < playerLoop; i++) {
                for (int i = 0; i < playerLoop; i++) {
                    if (allPlayers[i].sizeOfDeck() ==0) {
                        allPlayers.erase(allPlayers.begin() + i);
                        aiPlayers.erase(aiPlayers.begin() + i);
                        players--;
                    }
                }
            }
        }
        else {
            cout << aiPlayers[distance(stats.begin(), it)] << " wins this round and has taken the spoils!" << endl << endl;
            // PUSH CARDS INTO WINNING PLAYERS DECK
            roundDeckSize = round.sizeOfDeck();
            for (int i = 0; i < roundDeckSize; i++) {
                allPlayers[distance(stats.begin(), it)].inPlay(round);
                round.removeCard();
            }
            cout << "Cards Remaining" << endl;
            cout << "=============" << endl;
            for (int i = 0; i < players; i++) {
                cout << setw(10) << left << aiPlayers[i] << allPlayers[i].sizeOfDeck();
                allPlayers[i].sizeOfDeck() == 0 ? cout << " - Out of the game\n" : cout << endl;  
            }
            playerLoop = players;
            for (int i = 0; i < playerLoop; i++) {
                for (int i = 0; i < playerLoop; i++) {
                    if (allPlayers[i].sizeOfDeck() ==0) {
                        allPlayers.erase(allPlayers.begin() + i);
                        aiPlayers.erase(aiPlayers.begin() + i);
                        players--;
                    }
                }
            }
            cout << endl << endl;
            cout << "PLAYERS LEFT" << endl;
            cout << "=============" << endl;
            for (auto n : aiPlayers) {
                cout << n << endl;
            }
        }
        cout << endl;
        system("pause");
        system("cls");
        playerTurn ++;
        if (playerTurn > players - 1) {
            playerTurn = 0;
        }
        stats.clear();
        startGame = false;
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
void headerLayout() {
    cout << setw(15) << left << "Player";
    cout << setw(30) << left << "Name";
    cout << setw(30) << "Culture";
    cout << setw(16) << right << "Ring Resistance";
    cout << setw(8) << "Age";
    cout << setw(14) << "Resilience";
    cout << setw(14) << "Ferocity";
    cout << setw(8) << "Magic";
    cout << setw(10) << "Height" << endl;
    cout << setfill('=') << setw(145) << "" << setfill(' ') << endl;
}