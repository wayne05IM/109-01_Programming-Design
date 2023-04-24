#include <iostream>
#include <cstring>
using namespace std;

const int STOCK_CARD_NUM_MAX = 20;
const int INIT_CARD_NUM = 5;
const int CARD_NUM = 10;
const int DECK_NUM = 4;

// Card
class Card
{
private:
    char suit;
    int rank;
    bool isA();
    bool isTheSameRank(Card temp);
    bool isTheSameSuit(Card temp);

public:
    bool init(char cardStr[]);

    friend class Deck;
    friend void RankSort(Card cardPile[]);
};

bool Card::isA()
{
    if (rank == 1)
        return true;
    else
        return false;
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

bool Card::init(char cardStr[])
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
        return true;
    }
    else if ((cardStr[1] == '1') and (cardStr[2] == '0'))
    {
        suit = cardStr[0];
        rank = 10;
        return true;
    }
    else
        return false;
};

// sorting function
void RankSort(Card[]);

// Deck
class Deck
{
private:
    Card *cards;
    int cardCnt;

public:
    void cardsinit();
    void compoundCardsinit();
    void addCard(Card c);
    void clean();
    void deckCompound(Deck a, Deck b);
    int getPoint();
};

void Deck::cardsinit()
{
    cardCnt = 0;
    cards = new Card[INIT_CARD_NUM];
};

void Deck::compoundCardsinit()
{
    cardCnt = 0;
    cards = new Card[CARD_NUM];
};

void Deck::clean()
{
    delete[] cards;
}

void Deck::addCard(Card c)
{
    cards[cardCnt] = c;
    cardCnt++;
};

void Deck::deckCompound(Deck a, Deck b)
{
    for (int i = 0; i < INIT_CARD_NUM; i++)
        cards[i] = a.cards[i];
    for (int i = 5, j = 0; i < CARD_NUM; i++, j++)
        cards[i] = b.cards[j];
};

int Deck::getPoint()
{
    int score = 0;
    RankSort(cards);

    //1 A
    for (int i = 0; i < CARD_NUM; i++)
    {
        if (cards[i].isA() == true)
        {
            score = 1;
            break;
        }
    }
    //一對
    int tempscore = 0;
    for (int i = 0; i < CARD_NUM; i++)
    {
        if (cards[i].isTheSameRank(cards[i + 1]) == true)
        {
            if(tempscore <= 10)
            {
                tempscore += 5;
                i++;
            }
        }
        else
        {
            tempscore++;
        }
    }
    if(tempscore >= 11)
        tempscore = 11;
    else if((tempscore < 11) and (tempscore >= 8))
        tempscore = 8;

    if (tempscore > score)
        score = tempscore;
    //同花
    bool fulfill = true;
    for (int i = 0; i < CARD_NUM; i++)
    {
        int sameCnt = 1;
        for (int j = 0; j < CARD_NUM; j++)
        {
            if (j != i)
            {
                if (cards[i].suit == cards[j].suit)
                    sameCnt++;
            }
        }
        if (sameCnt == 5)
        {
            score = 20;
            break;
        }
    }
    //葫蘆
    fulfill = false;
    bool fulfill2 = false;
    int count = 0, ful1 = 0, ful2 = 0;
    for (int i = 0; i < CARD_NUM; i++)
    {
        for (int j = i + 1; j < CARD_NUM; j++)
        {
            if (cards[i].isTheSameRank(cards[j]) == false)
                break;
            else
                count++;
        }
        if (count == 1)
        {
            fulfill = true;
            i += 1;
            count = 0;
        }
        if (count == 2)
        {
            fulfill2 = true;
            i += 2;
            count = 0;
        }
    }
    if ((fulfill == true) and (fulfill2 == true))
        score = 40;
    //順
    int continueNum = 1;
    for (int i = 0; i < CARD_NUM; i++)
    {
        if (cards[i].rank + 1 == cards[i + 1].rank)
            continueNum++;
        else if (cards[i].rank == cards[i + 1].rank)
            ;
        else
        {
            if (continueNum < 5)
                continueNum = 1;
            else
                score = 50;
        }
    }
    if (continueNum > 5)
        score = 50;
    //同花順
    Card array[DECK_NUM][CARD_NUM];
    int arrayCount[DECK_NUM] = {0};
    for (int i = 0; i < CARD_NUM; i++)
    {
        if (cards[i].suit == 'S')
        {
            array[0][arrayCount[0]] = cards[i];
            arrayCount[0]++;
        }
        else if (cards[i].suit == 'D')
        {
            array[1][arrayCount[1]] = cards[i];
            arrayCount[1]++;
        }
        else if (cards[i].suit == 'H')
        {
            array[2][arrayCount[2]] = cards[i];
            arrayCount[2]++;
        }
        else
        {
            array[3][arrayCount[3]] = cards[i];
            arrayCount[3]++;
        }
    }
    for (int j = 0; j < DECK_NUM; j++)
    {
        int continueNum = 1;
        for (int i = 0; i < CARD_NUM; i++)
        {
            if (array[j][i].rank + 1 == array[j][i + 1].rank)
                continueNum++;
            else if (array[j][i].rank == array[j][i + 1].rank)
                ;
            else
            {
                if (continueNum < 5)
                    continueNum = 1;
                else
                    score = 100;
            }
        }
        if (continueNum > 5)
            score = 100;
    }

    return score;
};

//main function

int main()
{
    Deck cardDeck[DECK_NUM];
    for (int x = 0; x < DECK_NUM; x++)
    {
        //input
        char stock[STOCK_CARD_NUM_MAX];
        cin.getline(stock, 20);

        //split string
        Card c;
        cardDeck[x].cardsinit();
        char *address = strtok(stock, ",");
        while (address != nullptr)
        {
            c.init(address);
            cardDeck[x].addCard(c);
            address = strtok(nullptr, ",");
        }
    }

    // maxscore
    int maxscore = 0;
    for (int i = 0; i < DECK_NUM; i++)
    {
        for (int j = i + 1; j < DECK_NUM; j++)
        {
            Deck compoundDeck;
            compoundDeck.compoundCardsinit();
            compoundDeck.deckCompound(cardDeck[i], cardDeck[j]);

            int score = compoundDeck.getPoint();

            compoundDeck.clean();
            if (score > maxscore)
                maxscore = score;
        }
    }

    cout << maxscore;

    return 0;
}

//insertion sort
void RankSort(Card cardPile[])
{
    for (int i = 0; i < CARD_NUM; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (cardPile[j].rank < cardPile[j - 1].rank)
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
