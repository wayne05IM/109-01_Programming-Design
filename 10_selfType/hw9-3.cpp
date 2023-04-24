#include <iostream>
#include <cstring>
using namespace std;

const int CARD_NUM = 5;
const int DECK_NUM = 4;
const int TOTAL_CARD = 20;

struct Randomizer
{
    int a;
    int b;
    int c;
    int cur;
    int rand();
};
int Randomizer::rand()
{
    cur = (a * cur + b) % c;
    return cur;
}

struct Card
{
    char suit;
    int rank;
    bool isA()
    {
        if (rank == 1)
            return true;
        else
            return false;
    }
    bool isTheSameRank(Card temp)
    {
        if (temp.rank == rank)
            return true;
        else
            return false;
    }
    bool isTheSameSuit(Card temp)
    {
        if (temp.suit == suit)
            return true;
        else
            return false;
    }
    bool init(char cardStr[])
    {
        if ((cardStr[0] == 'S' | cardStr[0] == 'D' | cardStr[0] == 'H' | cardStr[0] == 'C') and (cardStr[1] == 'A' | cardStr[1] == '2' | cardStr[1] == '3' | cardStr[1] == '4' | cardStr[1] == '5' | cardStr[1] == '6' | cardStr[1] == '7' | cardStr[1] == '8' | cardStr[1] == '9' | cardStr[1] == 'J' | cardStr[1] == 'Q' | cardStr[1] == 'K'))
        {
            //cout << cardStr[0] << " " << cardStr[1] << " " << cardStr[2] << endl;
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
    }
};

void RankSort(Card[]);

struct Deck
{
    Card* cards;
    int cardCnt;
    void cardsinit()
    {
        cards = new Card[CARD_NUM];
        cardCnt = 0;
    }
    void addCard(Card c)
    {
        cards[cardCnt] = c;
    }
    int getPoint()
    {
        int score = 0;
        RankSort(cards);
        /*for(int i = 0; i < CARD_NUM; i++)
        {
            cout << cardPile[i].suit << " " << cardPile[i].rank << endl;
        }*/

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
                tempscore += 5;
                //cout << i << tempscore;
                i++;
            }
            else
            {
                if (cards[i].isA() == true)
                    tempscore++;
            }
        }
        if (tempscore > score)
            score = tempscore;
        //同花
        bool fulfill = true;
        for (int i = 0; i < CARD_NUM - 1; i++)
        {
            if (cards[i].isTheSameSuit(cards[i + 1]) == false)
            {
                fulfill = false;
                break;
            }
        }
        if (fulfill == true)
            score = 20;
        //葫蘆
        fulfill = false;
        bool fulfill2 = false;
        int count = 0;
        for (int i = 0; i < CARD_NUM; i++)
        {
            for (int j = i + 1; j < CARD_NUM; j++)
            {
                if (cards[i].isTheSameRank(cards[j]) == false)
                    break;
                else
                    count++;
                //cout << i << " " << j << ":" << count << endl;
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
        //同花順 and 順
        fulfill = true;
        for (int i = 0; i < CARD_NUM - 1; i++)
        {
            if ((i == 0) and (cards[0].rank == 1))
            {
                if ((cards[i + 1].rank != 2) and (cards[i + 1].rank != 10))
                {
                    fulfill = false;
                    break;
                }
            }
            else
            {
                if ((cards[i].rank + 1) != cards[i + 1].rank)
                {
                    fulfill = false;
                    break;
                }
            }
        }
        if (fulfill == true)
        {
            for (int i = 0; i < CARD_NUM - 1; i++)
            {
                if (cards[i].isTheSameSuit(cards[i + 1]) == false)
                {
                    score = 50;
                    fulfill = false;
                    break;
                }
            }
        }
        if (fulfill == true)
            score = 100;

        return score;
    }
};

int main()
{
    //input
    int a = 0, b = 0, c = 0, s = 0;
    cin >> s >> a >> b >> c;
    Randomizer r1 = {a, b, c, s};

    Card cards[52] = {};
    int i = 0;
    for(int k = 0; k < 4; k++)
    {
        char tempSuit;
        if(k == 0)
            tempSuit = 'S';
        if(k == 1)
            tempSuit = 'H';
        if(k == 2)
            tempSuit = 'D';
        if(k == 3)
            tempSuit = 'C';
        for(int j = 1; j <= 13; j++)
        {
            cards[i].suit = tempSuit;
            cards[i].rank = j;
            i++;
        }
    }


    for(int i = 0; i < TOTAL_CARD; i++)
    {
        int r = 0;
        r = r1.rand() % 52;

        Card temp = cards[i];
        cards[i] = cards[r];
        cards[r] = temp;
    }
      
    Deck cardDeck[DECK_NUM];
    for(int i = 0; i < DECK_NUM; i++)
    {
        cardDeck[i].cardsinit();
    }
    
    for(int j = 0; j < TOTAL_CARD; j++)
    {
        cardDeck[j % 4].addCard(cards[j]);
        cardDeck[j % 4].cardCnt += 1;
    }
    

    //max score  
    int maxscore = 0, player = 0;
    for(int i = 0; i < DECK_NUM; i++)
    {
        int score = cardDeck[i].getPoint();
        if(score > maxscore)
        {
            maxscore = score;
            player = i + 1;
        }
    }
    
    cout << player << "," << maxscore;

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