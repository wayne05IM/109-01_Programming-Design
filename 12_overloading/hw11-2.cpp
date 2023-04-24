#include <iostream>
#include <cstring>
using namespace std;

const int STOCK_CARD_NUM_MAX = 52 * 5;
const int SUIT_NUM = 4;
const int RANK_NUM = 13;
const int CARD_NUM = 52;

// Card
class Card
{
private:
    char suit;
    int rank;

public:
    void init(char cardStr[]);
    bool isBiggerThan(const Card &c, char suitsort[]);

    friend void RankSort(Card cardPile[], int amount);
    friend class Deck;
};

void Card::init(char cardStr[])
{
    if ((cardStr[0] == 'S' | cardStr[0] == 'D' | cardStr[0] == 'H' | cardStr[0] == 'C') and (cardStr[1] == 'A' | cardStr[1] == '2' | cardStr[1] == '3' | cardStr[1] == '4' | cardStr[1] == '5' | cardStr[1] == '6' | cardStr[1] == '7' | cardStr[1] == '8' | cardStr[1] == '9' | cardStr[1] == 'J' | cardStr[1] == 'Q' | cardStr[1] == 'K'))
    {
        suit = cardStr[0];
        if (cardStr[1] == 'A')
            rank = 14;
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

bool Card::isBiggerThan(const Card &c, char suitsort[])
{
    int thistemp = 0, inputtemp = 0;
    for (int i = 0; i < SUIT_NUM; i++)
    {
        if (suit == suitsort[i])
            thistemp = i;
        else if (c.suit == suitsort[i])
            inputtemp = i;
    }
    if (thistemp < inputtemp)
        return true;
    else
        return false;
};

// cardstack
class Deck
{
private:
    Card *cards;
    int cardCnt;

public:
    void cardsinit();
    void addCard(Card c);
    void sortCardsDesc(char suitsort[]);
    void print();
};

void Deck::cardsinit()
{
    cardCnt = 0;
    cards = new Card[CARD_NUM];
};

void Deck::addCard(Card c)
{
    cards[cardCnt] = c;
    cardCnt++;
};

void Deck::sortCardsDesc(char suitsort[])
{
    for (int i = 0; i < cardCnt - 1; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (cards[j].isBiggerThan(cards[j - 1], suitsort) == true)
            {
                Card temp = cards[j];
                cards[j] = cards[j - 1];
                cards[j - 1] = temp;
            }
            else
                break;
        }
    }
    RankSort(cards, cardCnt - 1);
};

void Deck::print()
{
    for (int i = 0; i < cardCnt - 2; i++)
    {
        cout << cards[i].suit;
        if (cards[i].rank == 14)
            cout << 'A';
        else if (cards[i].rank == 11)
            cout << 'J';
        else if (cards[i].rank == 12)
            cout << 'Q';
        else if (cards[i].rank == 13)
            cout << 'K';
        else
            cout << cards[i].rank;
        cout << ",";
    }
    cout << cards[cardCnt - 2].suit;
    if (cards[cardCnt - 2].rank == 14)
        cout << 'A';
    else if (cards[cardCnt - 2].rank == 11)
        cout << 'J';
    else if (cards[cardCnt - 2].rank == 12)
        cout << 'Q';
    else if (cards[cardCnt - 2].rank == 13)
        cout << 'K';
    else
        cout << cards[cardCnt - 2].rank;
}

void RankSort(Card cardPile[], int amount);

int main()
{
    //input
    char stock[STOCK_CARD_NUM_MAX];
    cin.getline(stock, STOCK_CARD_NUM_MAX);

    //split string
    Card cardPile[CARD_NUM];
    char *address = strtok(stock, ",");
    int amount = 0;
    while (address != nullptr)
    {
        cardPile[amount].init(address);
        amount++;
        address = strtok(nullptr, ",");
    }

    char suitsort[SUIT_NUM];
    cin.getline(suitsort, SUIT_NUM + 5);

    //operation
    Deck deck;
    deck.cardsinit();
    for (int i = 0; i <= amount; i++)
        deck.addCard(cardPile[i]);

    deck.sortCardsDesc(suitsort);
    deck.print();

    return 0;
}

//insertion sort
void RankSort(Card cardPile[], int amount)
{
    for (int i = 0; i < amount; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (cardPile[j].rank > cardPile[j - 1].rank)
            {
                Card temp = cardPile[j];
                cardPile[j] = cardPile[j - 1];
                cardPile[j - 1] = temp;
            }
            else
                break;
        }
    }
}