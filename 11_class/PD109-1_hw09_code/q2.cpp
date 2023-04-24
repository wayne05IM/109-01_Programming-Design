#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


class Card
{
private:
    char suit;
    int rank;
    bool init(char []);
public:
    Card();
    Card(char []);
    const char getSuit();
    const int getRank();
    bool isA();
    bool isSmaller(Card);
    void print();
};

class CardStack {
private:
    Card* cards;
    int CntOfCards;
    int SizeOfStack;
public:
    CardStack();
    ~CardStack();
    int getCnt();
    int getTopCardRank();
    void addCard(Card&);
    void print();
};


int main() {
    CardStack stack[4]; // create 1 cardstack for each suit
    
    char* input = new char[160];
    cin >> input;
    input = strtok(input,",");
    while(input != nullptr){
        Card c(input);
        
        //check if the card can be added to  cardstack
        if(c.getSuit() == 'S'){
            if((stack[0].getCnt() == 0 && c.getRank() == 1) ||stack[0].getTopCardRank() + 1 == c.getRank()){
                stack[0].addCard(c);
            }
        }
        else if(c.getSuit() == 'H'){
            if((stack[1].getCnt() == 0 && c.getRank() == 1) || stack[1].getTopCardRank() + 1 == c.getRank()){
                stack[1].addCard(c);
            }
        }
        else if(c.getSuit() == 'D'){
            if((stack[2].getCnt() == 0 && c.getRank() == 1) || stack[2].getTopCardRank() + 1 == c.getRank()){
                stack[2].addCard(c);
            }
        }
        else if(c.getSuit() == 'C'){
            if((stack[3].getCnt() == 0 && c.getRank() == 1) || stack[3].getTopCardRank() + 1 == c.getRank()){
                stack[3].addCard(c);
            }
        }
        input = strtok(nullptr,",");
    }
    
    cout << stack[0].getCnt() << "," << stack[1].getCnt() << "," << stack[2].getCnt() << "," << stack[3].getCnt();
    delete [] input;
    input = nullptr;
    return 0;
    
}

Card::Card(){
    this->rank = -1;
}

Card::Card(char cardStr[]){
    this->init(cardStr);
}


bool Card::init(char cardStr[]){
    if(isalpha(cardStr[0]) && isalnum(cardStr[1])){
        suit = cardStr[0];
        if(isalpha(cardStr[1])){
            switch(cardStr[1]) {
                case 'J':
                    rank = 11;
                    break;
                case 'Q':
                    rank = 12;
                    break;
                case 'K':
                    rank = 13;
                    break;
                case 'A':
                    rank = 1;
                    break;
                default:
                    break;
            }
            
        }
        else if(strlen(cardStr) == 3){
            rank = 10;
        }
        else{
            rank = static_cast<int>(cardStr[1]) - 48;
        }
        return true;
    }
    return false;
}

const char Card::getSuit(){
    return this->suit;
}

const int Card::getRank(){
    return this->rank;
}

bool Card::isA(){
    if(rank == 1){
        return true;
    }
    return false;
}

bool Card::isSmaller(Card anotherCard){
    if(this->rank < anotherCard.rank){
        return true;
    }
    return false;
}

void Card::print(){
    cout << this->suit << this->rank;
}

int CardStack::getCnt(){
    return CntOfCards;
}
int CardStack::getTopCardRank(){
    return cards[CntOfCards - 1].getRank();
}

CardStack::CardStack(){
    SizeOfStack = 4;
    CntOfCards = 0;
    this->cards = new Card [SizeOfStack];
}

CardStack::~CardStack(){
    delete [] cards;
}

void CardStack::addCard(Card& c){
    if(CntOfCards + 1 >= SizeOfStack){ // if the size is not big enough, increase by 2 times
        SizeOfStack *= 2;
        Card* tmp = new Card [SizeOfStack];
        for(int i = 0; i < CntOfCards; i++){
            tmp[i] = this->cards[i];
        }
        delete [] cards;
        cards = tmp;
    }
    
    this->cards[CntOfCards] = c;
    this->CntOfCards += 1;
}

void CardStack::print(){
    for(int i = 0; i < CntOfCards - 1; i++){
        this->cards[i].print();
        cout << ",";
    }
    this->cards[CntOfCards - 1].print();
}
