#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <chrono>
#include <thread>
#include <ctime>
#include <typeinfo>
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
void deleteLoser(vector<string> &gamePlayers, vector<Deck> &allPlayers, bool &alive, float &players);

int main() {
    srand((unsigned) time(0));
    string attribute;
    string userName;
    vector <string> attributes {"Resistance to Ring", "Age", "Resiliance", "Ferocity", "Magic", "Height"};
    int randomNumber;
    int playerTurn;
    int cnt;
    int roundDeckSize;
    int userChoice;
    vector <int> cardsUsed;
    vector <float> stats;
    float players; // for now
    Deck cards;
    Deck round;
    vector<string> aiNames {"John", "Fred", "Billy", "Maeve", "Houghie", "Stan", "Nadia", "Annie"};
    vector<string> gamePlayers;
    bool winner = false;
    bool startGame = true;
    bool alive = true;
    pushCards(cards);
    // CREATING VECTOR OF AI PLAYERS
    cout << "Welcome to Top Trumps - The Lord of the Rings Edition!" << endl;
    cout << "=====================================" << endl;
    cout << "Do you know how to play Top Trumps?\n" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    enterChoiceMessage();
    choiceValidation(userChoice);
    if (userChoice == 2) {
        rules();
    }
    cout << endl;
    system("pause");
    system("cls");
    cout << "Please enter your name: ";
    cin >> userName;
    gamePlayers.insert(gamePlayers.begin(), userName);
    cout << "How many AI players do you want to play against? ";
    cin >> players;
    players++;
    cout << "\nThere are " << players << " players including yourself" << endl;
    for (int i = 0; i < players-1; i++) {
        gamePlayers.push_back(aiNames[i]);
    }
    // DEAL THE CARDS - BY TAKING A RANDOM CARD FROM cards AND PUSHING TO A PLAYER DECK
    // CREATING DECKS BASED ON HOW MANY PLAYERS
    vector <Deck> allPlayers;
    for (int i = 0; i < players; i++) {
        Deck player;
        allPlayers.push_back(player);
    }
    // DEALING CARDS FROM CARDS DECK
    for (int i = 0; i < ceil(cards.sizeOfDeck()/players); i++) {
        for (size_t j = 0; j < players; j++) {
            if (cardsUsed.size() == cards.sizeOfDeck()) {
                break;
            }
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
    cout << endl;
    system("pause");
    system("cls");
    cout << ceil(cards.sizeOfDeck()/players) << endl;
    cout << cardsUsed.size() << endl;
    cout << cards.sizeOfDeck() << endl << endl;
    for (int i = 0; i < players; i++) {
        cout << gamePlayers[i] << endl;
        cout << "============" << endl;
        allPlayers[i].displayCards();
        cout << endl << endl;
    }
    // RANDOMLY CHOSING WHICH PLAYER WILL GO FIRST (then will go in order)
    playerTurn = (rand() % gamePlayers.size()) + 0;
    // PLAY THE TOP CARD FROM PLAYERS' HANDS AND CHOSING ATTRIBUTE PLAYED
    while(!winner) {
        cout << "[ ";
        for (auto name : gamePlayers) {
            cout << name << " ";
        }
        cout << "]" << endl << endl;
        cout << "Decks left in game: " << allPlayers.size() << endl << endl;
        startGame ? cout << gamePlayers[playerTurn] << " will go first" : cout << "It's " << gamePlayers[playerTurn] << "'s turn";
        cout << endl << endl;
        headerLayout();
        cout << setw(15) << left << gamePlayers[playerTurn];
        allPlayers[playerTurn].topCard();
        cout << endl << endl;
        if (playerTurn == 0 && alive) {
            cout << "It's your turn. Which attribute would you like to choose?\n" << endl;
            cout << "1. Resistance to Ring" << endl;
            cout << "2. Age" << endl;
            cout << "3. Resilience" << endl;
            cout << "4. Ferocity" << endl;
            cout << "5. Magic" << endl;
            cout << "6. Height" << endl;
            cout << "\nEnter your chosen attribute from the numbers listed above: ";
            cin >> randomNumber;
            randomNumber -= 1;
        }
        else {
            randomNumber = (rand() % 6) + 0;
        }
        attribute = attributes[randomNumber];
        cout << "The chosen attribute is: " << attribute;
        cout << endl << endl;
        cout << "Let's see our combatants!\n" << endl;
        system("pause");
        system("cls");
        cout << "The chosen attribute is: " << attribute;
        cout << endl << endl;
        headerLayout();
        
        for (size_t i = 0; i < gamePlayers.size(); i++) {
            cout << setw(15) << left << gamePlayers[i];
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
            deleteLoser(gamePlayers, allPlayers, alive, players);
        }
        else {
            cout << gamePlayers[distance(stats.begin(), it)] << " wins this round and has taken the spoils!" << endl << endl;
            // PUSH CARDS INTO WINNING PLAYERS DECK
            roundDeckSize = round.sizeOfDeck();
            for (int i = 0; i < roundDeckSize; i++) {
                allPlayers[distance(stats.begin(), it)].inPlay(round);
                round.removeCard();
            }
            cout << "Cards Remaining" << endl;
            cout << "=============" << endl;
            for (size_t i = 0; i < gamePlayers.size(); i++) {
                cout << setw(10) << left << gamePlayers[i] << allPlayers[i].sizeOfDeck();
                allPlayers[i].sizeOfDeck() == 0 ? cout << " - Out of the game\n" : cout << endl;  
            }
            // NEEDS WORK
            // SECTION FROM HERE //////////////////////////////////
            deleteLoser(gamePlayers, allPlayers, alive, players);
            cout << endl << endl;
        }
        cout << endl << endl << endl;
        cout << "PLAYERS LEFT" << endl;
        cout << "============" << endl;
        for (auto player : gamePlayers) {
            cout << player << endl;
        }
        if (gamePlayers.size() == 1) {
            winner = true;
            cout << "\nWINNER IS" << endl;
            cout << "============" << endl;
            cout << gamePlayers[0] << endl;
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
    cout << "WE HAVE A WINNER\n" << endl;
    cout << gamePlayers[0] << " has taken all the cards and has won the game!" << endl;
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

void deleteLoser(vector<string> &gamePlayers, vector<Deck> &allPlayers, bool &alive, float &players)  {
    vector<string>::iterator playersIn = gamePlayers.begin();
    vector<Deck>::iterator it2 = allPlayers.begin();
    playersIn = gamePlayers.begin();
    it2 = allPlayers.begin();
    int counter = 0;
    while (playersIn != gamePlayers.end()) {
        if (allPlayers[counter].sizeOfDeck() == 0) {
            if (counter == 0) {
                alive = false;
            }
            playersIn = gamePlayers.erase(playersIn);
            counter++;
            players--;
            continue;
        }
        counter++;
        playersIn++;
    }
    counter = 0;
    while(it2 != allPlayers.end()) {
        if(allPlayers[counter].sizeOfDeck() == 0) {
            it2 = allPlayers.erase(it2);
            continue;
        }
        counter++;
        it2++;
    }
}