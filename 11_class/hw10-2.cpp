#include <iostream>
#include <cstring>
using namespace std;

const int STOCK_CARD_NUM_MAX = 52 * 3 - 1;
const int CARD_NUM = 52;
const int SUIT_NUM = 4;
const int RANK_NUM = 13;

// Card
class Card
{
private:
    char suit;
    int rank;
    
public:
    int getS(){return rank;};
    void init(char cardStr[]);
    bool isTheSameRank(Card temp);
    bool isTheSameSuit(Card temp);

    friend int SuitSort(Card a);
};

bool Card::isTheSameRank(Card temp)
{
    if (temp.rank == rank)
        return true;
    else
        return false;
};

bool Card::isTheSameSuit(Card temp)
{
    if (temp.suit == suit)
        return true;
    else
        return false;
};

void Card::init(char cardStr[])
{
    if ((cardStr[0] == 'S' | cardStr[0] == 'D' | cardStr[0] == 'H' | cardStr[0] == 'C') and (cardStr[1] == 'A' | cardStr[1] == '2' | cardStr[1] == '3' | cardStr[1] == '4' | cardStr[1] == '5' | cardStr[1] == '6' | cardStr[1] == '7' | cardStr[1] == '8' | cardStr[1] == '9' | cardStr[1] == 'J' | cardStr[1] == 'Q' | cardStr[1] == 'K'))
    {
        suit = cardStr[0];
        if (cardStr[1] == 'A')
            rank = 1;
        else if (cardStr[1] == 'J')
            rank = 11;
        else if (cardStr[1] == 'Q')
            rank = 12;
        else if (cardStr[1] == 'K')
            rank = 13;
        else
            rank = (static_cast<int>(cardStr[1]) - '0');
    }
    else if ((cardStr[1] == '1') and (cardStr[2] == '0'))
    {
        suit = cardStr[0];
        rank = 10;
    }
};

// cardstack
class CardStack
{
private:
    Card *cards;
    int cardCnt;

public:
    void cardsinit();
    void addCard(Card c);

    friend int Score(CardStack a);
};

void CardStack::cardsinit()
{
    cardCnt = 0;
    cards = new Card[RANK_NUM];
};

void CardStack::addCard(Card c)
{
    cards[cardCnt] = c;
    cardCnt++;
};

int SuitSort(Card);
int Score(CardStack);

int main()
{
    //input
    char stock[STOCK_CARD_NUM_MAX];
    cin.getline(stock, STOCK_CARD_NUM_MAX);

    //split string
    Card cardPile[CARD_NUM];
    char* address = strtok(stock, ",");
    int amount = 0;
    while (address != nullptr)
    {
        cardPile[amount].init(address);
        amount++;
        address = strtok (nullptr, ",");
    }

    //operation
    int count[SUIT_NUM] = {0};
    CardStack deck[SUIT_NUM];
    for(int i = 0 ; i < SUIT_NUM; i++)
        deck[i].cardsinit();
    for(int i = 0 ; i <= amount; i++)
        deck[SuitSort(cardPile[i])].addCard(cardPile[i]);
    for(int i = 0 ; i < SUIT_NUM; i++)
        count[i] = Score(deck[i]);

    for(int i = 0 ; i < SUIT_NUM - 1; i++)
        cout << count[i] << ",";
    cout << count[SUIT_NUM - 1];
    
    return 0;
}

// global functions
int SuitSort(Card a)
{
    if(a.suit == 'S')
        return 0;
    else if(a.suit == 'H')
        return 1;
    else if(a.suit == 'D')
        return 2;
    else
        return 3;
}

int Score(CardStack a)
{
    int count = 0;
    for(int i = 0; i < a.cardCnt; i++)
    {
        int num = 1;
        if(a.cards[i].getS() == num)
        {
            count ++;
            num ++;
            for(int j = i + 1; j < a.cardCnt; j++)
            {
                if(a.cards[j].getS() == num)
                {
                    count ++;
                    num ++;
                }
            }
            break;
        }
    }
    return count;
}