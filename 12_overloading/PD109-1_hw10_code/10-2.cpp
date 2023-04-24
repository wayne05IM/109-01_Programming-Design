//
//  main.cpp
//  hw10_2

#include <iostream>
#include <cstring>
using namespace std;

const int CARDLEN = 4;      // Length of one card in the input
const int RANKTYPE = 13;    // Number of type of rank
const int SUITTYPE = 4;     // Number of type of suit
const int LEN_INPUT = CARDLEN * RANKTYPE * SUITTYPE + 1;    // Max length of the input string

class Card{
private:
    char suit;
    int rank;
    static char suitOrder[SUITTYPE + 1];    // Store the order of suit
public:
    Card();                                 // Defult constructor
    Card(const char& s, const int& r);      // Constructor called when the input contain a char and an int
    Card(const char cardStr[]);             // Constructor called when the input is a string
    Card(const Card& c);                    // Copy constructor
    char getSuit() const;
    int getRank() const;
    void print() const;
    void operator=(const Card& c);
    bool operator>(const Card& c) const;
    static void setSuitOrder(const char order[SUITTYPE + 1]);
    friend ostream& operator<<(ostream& out, const Card& c);
};

class Deck{
private:
    Card* cards;
    int cardCnt;
public:
    Deck();
    ~Deck();
    void addCard(const Card& c);
    void print() const;
    void sortCardsDesc();
    friend ostream& operator<<(ostream& out, const Deck& deck);
};

int main(int argc, const char * argv[]) {
    // Input
    char input[LEN_INPUT];
    char order[SUITTYPE + 1];
    char delim[] = ",";
    Deck deck;
    cin >> input >> order;
    
    // Split the input string and store cards into the deck
    char* start = strtok(input, delim);
    char oneCard[CARDLEN];
    while(start != nullptr){
        strcpy(oneCard, start);
        Card card(oneCard);
        deck.addCard(card);
        start = strtok(nullptr, delim);
    }
    
    // Set the order of suit
    Card::setSuitOrder(order);
    
    // Sort the deck
//    cout << deck << endl;
    deck.sortCardsDesc();
    cout << deck;
    
    return 0;
}


//=================================================================================================================
//========================================================Function=================================================
//=================================================================================================================

// Init the static variable
char Card::suitOrder[SUITTYPE + 1] = "SHDC";

Card::Card(){
    this->suit = '0';
    this->rank = 0;
}

Card::Card(const char& s, const int& r){
    this->suit = s;
    this->rank = r;
}

Card::Card(const char cardStr[]){
    int len = static_cast<int>(strlen(cardStr));
    // Check the length of cardStr
    if(len == 2 or len == 3){
        this->suit = cardStr[0];
        if(len == 2){
            if(cardStr[1] == 'A'){
                this->rank = 14;
            }
            else if(cardStr[1] == 'J'){
                this->rank = 11;
            }
            else if(cardStr[1] == 'Q'){
                this->rank = 12;
            }
            else if(cardStr[1] == 'K'){
                this->rank = 13;
            }
            else{
                this->rank = static_cast<int>(cardStr[1]) - static_cast<int>('1') + 1;
            }
        }
        else{
            this->rank = 10;
        }
    }
    else{
        this->suit = '0';
        this->rank = 0;
    }
}

Card::Card(const Card& c){
    this->suit = c.suit;
    this->rank = c.rank;
}

char Card::getSuit() const{
    return this->suit;
}

int Card::getRank() const{
    return this->rank;
}

void Card::print() const{
    cout << this->suit;
    if(this->rank == 14){
        cout << 'A';
    }
    else if(this->rank == 13){
        cout << 'K';
    }
    else if(this->rank == 12){
        cout << 'Q';
    }
    else if(this->rank == 11){
        cout << 'J';
    }
    else{
        cout << this->rank;
    }
}

void Card::operator=(const Card& c){
    this->suit = c.suit;
    this->rank = c.rank;
}

bool Card::operator>(const Card& c) const{
    // First compare ranks
    if(this->rank > c.rank){
        return true;
    }
    // If ranks are same, compare suits
    else if(this->rank == c.rank){
        int thisSuitID = -1, cSuitID = -1;
        // Find whose suit is bigger
        for(int i = 0; i < SUITTYPE; i++){
            if(this->suit == Card::suitOrder[i]){
                thisSuitID = i;
            }
            if(c.suit == Card::suitOrder[i]){
                cSuitID = i;
            }
        }
        // The smaller suitID means the suit is bigger
        return thisSuitID < cSuitID;
    }
    else{
        return false;
    }
}

void Card::setSuitOrder(const char order[SUITTYPE + 1]){
    for(int i = 0; i < SUITTYPE; i++){
        Card::suitOrder[i] = order[i];
    }
}

Deck::Deck(){
    this->cardCnt = 0;
}

Deck::~Deck(){
    delete [] this->cards;
    this->cards = nullptr;
}

void Deck::print() const{
    for(int i = 0; i < this->cardCnt - 1; i++){
        this->cards[i].print();
        cout << ",";
    }
    this->cards[cardCnt - 1].print();
}

void Deck::addCard(const Card& c){
    // If cardCnt is 0, then new a space to store a copy of this card c
    if(this->cardCnt == 0){
        this->cards = new Card[1];
        this->cards[0] = c;
    }
    // Otherwise, copy the origin cards to a longer card array, and put the card c into the new card array
    else{
        Card* temp = new Card[this->cardCnt + 1];
        for(int i = 0; i < this->cardCnt; i++){
            temp[i] = this->cards[i];
        }
        temp[this->cardCnt] = c;
        delete [] this->cards;
        this->cards = temp;
    }
    this->cardCnt++;
}

void Deck::sortCardsDesc(){
    // Implement insertion sort
    for(int i = 1; i < this->cardCnt; i++){
        Card temp = this->cards[i];
        int targetID = i - 1;
        while(temp > this->cards[targetID] && targetID >= 0){
            this->cards[targetID + 1] = this->cards[targetID];
            targetID --;
        }
        this->cards[targetID + 1] = temp;
    }
}

ostream& operator<<(ostream& out, const Card& c){
    out << c.suit;
    if(c.rank == 14){
        out << 'A';
    }
    else if(c.rank == 13){
        out << 'K';
    }
    else if(c.rank == 12){
        out << 'Q';
    }
    else if(c.rank == 11){
        out << 'J';
    }
    else{
        out << c.rank;
    }
    return out;
}

ostream& operator<<(ostream& out, const Deck& deck){
    for(int i = 0; i < deck.cardCnt - 1; i++){
        out << deck.cards[i];
        out << ",";
    }
    out << deck.cards[deck.cardCnt - 1];
    return out;
}

