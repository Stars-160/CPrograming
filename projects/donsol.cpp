//Donsol in C++...

#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>

//using vectors for everything, minus the deck.
using namespace std;

//room global deque
vector<string> room;
int health;
int shield;
int lowest;

//deck creation
deque<string> deck_builder(){
    deque<string> deck;
    int i;
    int j;
    string suit;
    string val;
    for (i = 1; i <= 4; i++){
        if (i == 1){
            suit = "s";
        } else if (i == 2){
            suit = "c";
        } else if (i == 3){
            suit = "d";
        } else {
            suit = "h";
        }
        for (j = 1; j <= 13; j++) {
            if (j == 1){
                val = "01";
            } else if (j == 2){
                val = "02";
            } else if (j == 3){
                val = "03";
            } else if (j == 4){
                val = "04";
            } else if (j == 5){
                val = "05";
            } else if (j == 6){
                val = "06";
            } else if (j == 7){
                val = "07";
            } else if (j == 8){
                val = "08";
            } else if (j == 9){
                val = "09";
            } else if (j == 10){
                val = "10";
            } else if (j == 11){
                val = "11";
            } else if (j == 12){
                val = "12";
            } else {
                val = "13";
            }
        string add = suit + val;
        deck.push_back(add);
        }
    }
    for (int k = 1; k <= 2; k++) {
        deck.push_back("j21");
    }
    return deck;
}

//card decoder
string card_reader(string card) {
    char sui = card.at(0);
    char val1 = card.at(1);
    char val2 = card.at(2);
    string suit;
    string name;
    string card_out;
    if (sui == 's') {
        suit = "Spades";
    } else if (sui == 'c') {
        suit = "Clubs";
    } else if (sui == 'h') {
        suit = "Hearts";
    } else if (sui == 'd') {
        suit = "Diamonds";
    } else if (sui == 'j') {
        return "Joker";
    } else if (sui == 'e') {
        return "Empty";
    }
    if (val2 == '0'){
        name = "Ten";
    } else if (val2 == '1') {
        if (val1 == '0') {
            name = "Ace";
        } else {
            name = "Jack";
        }
    } else if (val2 == '2') {
        if (val1 == '0') {
            name = "Two";
        } else {
            name = "Queen";
        }
    } else if (val2 == '3') {
        if (val1 == '0') {
            name = "Three";
        } else {
            name = "King";
        }
    } else if (val2 == '4') {
        name = "Four";
    } else if (val2 == '5') {
        name = "Five";
    } else if (val2 == '6') {
        name = "Six";
    } else if (val2 == '7') {
        name = "Seven";
    } else if (val2 == '8') {
        name = "Eight";
    } else if (val2 == '9') {
        name = "Nine";
    }
    card_out = name + " of " + suit;
    return card_out;
}

//Action function?
void action(string card) {
    char sui = card.at(0);
    char val1 = card.at(1);
    char val2 = card.at(2);
    int value = 0;
    int effect;
    if (sui == 's' || sui == 'c') {
        if (val2 == '0') {
            value = -10;
        } else if (val2 == '1') {
            if (val1 == '1'){
                value = -11;
            } else {
                value = -17;
            }
        } else if (val2 == '2') {
            if (val1 == '1'){
                value = -13;
            } else {
                value = -2;
            }
        } else if (val2 == '3') {
            if (val1 == '1'){
                value = -15;
            } else {
                value = -3;
            }
        } else if (val2 == '4') {
            value = -4;
        } else if (val2 == '5') {
            value = -5;
        } else if (val2 == '6') {
            value = -6;
        } else if (val2 == '7') {
            value = -7;
        } else if (val2 == '8') {
            value = -8;
        } else if (val2 == '9') {
            value = -9;
        }
    } else if (sui == 'h' || sui == 'd') {
        if (val2 == '0') {
            value = 10;
        } else if (val2 == '1') {
            if (val1 == '1'){
                value = 11;
            } else {
                value = 11;
            }
        } else if (val2 == '2') {
            if (val1 == '1'){
                value = 11;
            } else {
                value = 2;
            }
        } else if (val2 == '3') {
            if (val1 == '1'){
                value = 11;
            } else {
                value = 3;
            }
        } else if (val2 == '4') {
            value = 4;
        } else if (val2 == '5') {
            value = 5;
        } else if (val2 == '6') {
            value = 6;
        } else if (val2 == '7') {
            value = 7;
        } else if (val2 == '8') {
            value = 8;
        } else if (val2 == '9') {
            value = 9;
        }
    } else if (sui == 'j') {
        value = -21;
    } else if (sui == 'e'){
        value = 0;
    }
    if (sui == 's' || sui == 'c' || sui == 'j'){
        if (shield != 0){
            effect = shield + value;
            if (effect > 0){
                effect = 0;
            }
            if ((-1 * value) >= lowest){
                shield = 0;
                lowest = 0;
            } else {
                lowest = (-1 * value);
            }
        } else {
            effect = value;
        }
        health = health + effect;
    }
    if (sui == 'd') {
        shield = value;
        lowest = 22;
    }
    if (sui == 'h') {
        health = health + value;
        if (health > 21) {
            health = 21;
        }
    }
}

//Enemy Check
bool ene_check(vector<string> room) {
    int temp = 0;
    bool out;
    for (string card : room) {
        char suit  = card.at(0);
        if (suit == 's' || suit == 'c' || suit == 'j'){
            temp += 1; 
        }
    }
    if (temp > 0) {
        return 1;
    } else
        return 0;
}

int main(void){
    //deck setup
    deque<string> deck = deck_builder();
    
    //shuffling
    random_device rd;
    mt19937 g(rd());
    for (int shufc = 1; shufc <= 3; shufc++){
        shuffle(deck.begin(), deck.end(), g);
    }
    //Shuffling and card reader work.
    
    //initial game setup
    bool game = 1;
    bool cont = 1;
    int flee = 0;
    bool end = 0;
    string input;
    int place;
    int i;
    int temp;
    room = {"e00", "e00", "e00", "e00"};
    health = 21;    
    shield = 0;
    lowest = 0;
    string shield_disp = "";
    string lowest_disp = "";
    string flee_disp = "";
    while (game == 1) {
        if (cont == 1) {
            if (size(deck) < 4){
                while (size(deck) < 4){
                    deck.push_back("e00");
                }
            }
            i = 0;
            for (i = 0; i <= 3; i++) {
                room.at(i) = deck.at(0);
                deck.pop_front();
            }
            if (flee > 0) {
                flee = flee - 1;
            }
            cont = 0;
        }
        system("clear");
        i = 1;
        for (string card : room){
            cout << i << ": " << card_reader(card) << endl;
            i++;
        }
        bool ene = ene_check(room);
        //stat displays

        //shield
        if (shield == 0){
            shield_disp = "";
        } else {
            shield_disp = to_string(shield);
        }

        //lowest
        if (lowest == 0 || lowest == 22) {
            lowest_disp = "";
        } else {
            lowest_disp = to_string(lowest);
        }

        //Flee
        if (flee == 0) {
            flee_disp = "Ready!";
        } else {
            flee_disp = "Used...";
        }

        cout << "Health: " << health << "/21" << endl;
        cout << "shield: " << shield_disp << endl;
        cout << "Lowest: " << lowest_disp << endl;
        cout << "Flee: " << flee_disp << endl;
        cout << "Action: ";
        cin >> input;

        if (input == "1") {
            place = 0;
        } else if (input == "2") {
            place = 1;
        } else if (input == "3") {
            place = 2;
        } else if (input == "4") {
            place = 3;
        } else {
            place = 4;
        }
        if (place != 4){
            string card = room.at(place);
            action(card);
            room.at(place) = "e00";
        } else {
            if (input == "forcequit") {
                game = 0;
            } else if (input == "cont" || input == "continue") {
                if (ene == 0){
                    cont = 1;
                    for (string card : room) {
                        if (card != "e00") {
                            deck.push_back(card);
                        }
                    }
                }
            } else if (input == "flee") {
                if (flee == 0) {
                    cont = 1;
                    flee = 2;
                }
            } else if (input == "forcecont") {
                cont = 1;
                for (string card : room) {
                    if (card != "e00") {
                        deck.push_back(card);
                    }
                }
            }
        }
        if (health <= 0) {
            game = 0;
        }
        if (size(deck) == 0){
            temp = 0;
            for (string card : room) {
                if (card == "e00"){

                } else {
                    temp = temp + 1;
                }
            }
            if (temp == 0) {
                game = 0;
                end = 1;
            }
        }
    }
    system("clear");
    if (health <= 0) {
        cout << "GAME OVER!\nYou ran out of health" << endl;
    }
    if (end == 1){
        cout << "You defeated the dungeon!\nCongratulations!" << endl;
    } else if (end == 0) {
        if (input != "forcequit" && health >= 0) {
            cout << "This end shouldn't be possible, um... how did you break this?" << endl;
        }
    }
    return 0;
}