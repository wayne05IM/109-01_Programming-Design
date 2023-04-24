#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int CntCards = 5;
const int CntPlayers = 4;


class Card
{
private:
    char suit;
    int rank;
    bool init(char []);
public:
    Card();
    Card(char []);
    char getSuit();
    int getRank();
    bool isA();
    bool isSmaller(Card);
};

class Deck {
private:
    Card* cards;
    int cardCnt;
    bool hasStraight();
    bool hasFlush();
    bool hasFullHouse();
    
public:
    Deck();
    Deck(int);
    ~Deck();
    void addCard(const Card&);
    void addCard(Deck&);
    Card getCard(int);
    int getCardCnt();
    void sort();
    int getPoint();
    void print();
};

// Global Function
int countingScore(Deck&);


//Main Function
int main() {
    Deck* decks = new Deck[CntPlayers];
    
    char* input = new char[15];
    int score = 0;
    for(int i = 0; i < CntPlayers; i++){
        cin >> input;
        input = strtok(input,",");

        for(int j = 0; j < CntCards; j++){ //add a card into deck
            Card c(input);
            decks[i].addCard(c);
            input = strtok(nullptr,",");
        }
        decks[i].sort(); //sort deck for convenience
        
        for(int j = 0; j < i; j++){ //combine 2 deck
            Deck combineDeck(CntCards * 2);
            combineDeck.addCard(decks[i]);
            combineDeck.addCard(decks[j]);
            combineDeck.sort(); //sort deck for convenience
            int tmpScore = countingScore(combineDeck); //counting max possible score
            if(tmpScore > score){
                score = tmpScore;
            }
        }
        delete [] input;
        input = new char [15];
       
    }

    cout << score;
    delete [] input;
    input = nullptr;
    delete [] decks;
    decks = nullptr;
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

char Card::getSuit(){
    return  this->suit;
}

int Card::getRank(){
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

Deck::Deck(){
    this->cards = new Card [CntCards];
    this->cardCnt = 0;
}

Deck::Deck(int cardCnt){
    this->cards = new Card [cardCnt];
    this->cardCnt = 0;
}

Deck::~Deck(){
    if(cards != nullptr){
        delete [] cards;
    }
    this->cardCnt = 0;
}

void Deck::addCard(const Card& c){
    this->cards[cardCnt] = c;
    this->cardCnt++;
}

void Deck::addCard(Deck& d){
    for(int i = 0; i < d.getCardCnt(); i++){
        this->cards[cardCnt] = d.getCard(i);
        this->cardCnt++;
    }
}

Card Deck::getCard(int index){
    return this->cards[index];
}

int Deck::getCardCnt(){
    return this->cardCnt;
}

void Deck::sort(){
    for(int i = 0; i < cardCnt; i++){
        Card card = cards[i];
        int j = i - 1;
        while (card.isSmaller(cards[j]) && j >= 0) {
            cards[j + 1] = cards[j];
            j--;
        }
        cards[j + 1] = card;
    }
}

bool Deck::hasStraight(){
    bool isStraight = true;
    for(int i = 0; i < cardCnt - 1; i++){
        if(cards[i].getRank() + 1 != cards[i+1].getRank()){
            isStraight = false;
        }
    }
    if(cards[0].getRank() == 1 && cards[1].getRank() == 10 && cards[2].getRank() == 11 && cards[3].getRank() == 12 && cards[4].getRank() == 13){
        isStraight = true;
    }
    return isStraight;
}
bool Deck::hasFlush(){
    bool isFlush = true;
    for(int i = 0; i < cardCnt - 1; i++){
        if(cards[i].getSuit() != cards[i+1].getSuit()){
            isFlush = false;
        }
    }
    return isFlush;
}
bool Deck::hasFullHouse(){
    if((cards[0].getRank() == cards[1].getRank() && cards[1].getRank() == cards[2].getRank() && cards[3].getRank() == cards[4].getRank()) ||
       (cards[0].getRank() == cards[1].getRank() && cards[2].getRank() == cards[3].getRank() && cards[3].getRank() == cards[4].getRank())){
        return true;
    }
    
    return false;
}

int Deck::getPoint(){
    int score = 0;
    bool isStraight = hasStraight(), isFlush = hasFlush();
    if(isStraight && isFlush){
        score = 100;
    }
    else if(isStraight){
        score = 50;
    }
    else if(hasFullHouse()){
        score = 40;
    }
    else if(isFlush){
        score = 20;
    }
    else{
        int index = 0;
        while(index < cardCnt - 1){
            if(cards[index].getRank() == cards[index+1].getRank()){
                score += 5;
                index ++;
            }
            else if(cards[index].isA()){
                score += 1;
            }
            index ++;
        }
        if(index < cardCnt && cards[index].isA()){
            score += 1;
        }
    }
    return score;
}

void Deck::print(){
    for(int i = 0; i < cardCnt; i++){
        cout << this->cards[i].getSuit() << " " << this->cards[i].getRank() << endl;
    }
}


int countingScore(Deck& d){ //try out all possible combinations and return the highest score
    int score = 0;
    int n = CntCards * 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(i == j){
                continue;
            }
            for(int k = 0; k < j; k++){
                if(j == k){
                    continue;
                }
                for(int m = 0; m < k; m++){
                    if(m == k){
                        continue;
                    }
                    for(int l = 0; l < m; l++){
                        if(l == m){
                            continue;
                        }
                        Deck tmpDeck;
                        tmpDeck.addCard(d.getCard(i));
                        tmpDeck.addCard(d.getCard(j));
                        tmpDeck.addCard(d.getCard(k));
                        tmpDeck.addCard(d.getCard(l));
                        tmpDeck.addCard(d.getCard(m));
                        tmpDeck.sort();
                        int tmpScore = tmpDeck.getPoint();
                        if(tmpScore > score){
                            score = tmpScore;
                        }
                    }
                }
            }
        }
    }
    return score;
}
