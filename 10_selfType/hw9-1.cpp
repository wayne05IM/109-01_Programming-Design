#include <iostream>
#include <cstring>
using namespace std;

const int STOCK_CARD_NUM_MAX = 20;
const int CARD_NUM = 5;

struct Card
{
    char suit;
    int rank;
    bool isA()
    {
        if(rank == 1)
            return true;
        else
            return false;
    }
    bool isTheSameRank(Card temp)
    {
        if(temp.rank == rank)
            return true;
        else
            return false;
    }
    bool isTheSameSuit(Card temp)
    {
        if(temp.suit == suit)
            return true;
        else
            return false;
    }
    bool init(char cardStr[])
    {
        if((cardStr[0] == 'S'| cardStr[0] == 'D'| cardStr[0] == 'H'| cardStr[0] == 'C')
            and (cardStr[1] == 'A'| cardStr[1] == '2'| cardStr[1] == '3'| cardStr[1] == '4'| cardStr[1] == '5'| cardStr[1] == '6'| cardStr[1] == '7'| cardStr[1] == '8'| cardStr[1] == '9'| cardStr[1] == 'J'| cardStr[1] == 'Q'| cardStr[1] == 'K'))
        {
            //cout << cardStr[0] << " " << cardStr[1] << " " << cardStr[2] << endl;
            suit = cardStr[0];
            if(cardStr[1] == 'A')
                rank = 1;
            else if(cardStr[1] == 'J')
                rank = 11;
            else if(cardStr[1] == 'Q')
                rank = 12;
            else if(cardStr[1] == 'K')
                rank = 13;
            else
                rank = (static_cast<int> (cardStr[1]) - '0');
            return true;
        }
        else if((cardStr[1] == '1') and (cardStr[2] == '0'))
        {
            suit = cardStr[0];
            rank = 10;
            return true;
        }
        else
            return false;
    }
};

void RankSort (Card[]);

int main()
{
    //input
    char stock[STOCK_CARD_NUM_MAX];
    cin.getline(stock, 20);

    //split string
    Card cardPile[CARD_NUM] = {0};
    char* address = strtok(stock, ",");
    int i = 0; 
    while (address != nullptr)
    {
        cardPile[i].init(address);
        i++;
        address = strtok (nullptr, ",");
    }

    //operation
    int score = 0;
    RankSort(cardPile);
    /*for(int i = 0; i < CARD_NUM; i++)
    {
        cout << cardPile[i].suit << " " << cardPile[i].rank << endl;
    }*/
    //1 A
    for(int i = 0; i < CARD_NUM; i++)
    {
        if(cardPile[i].isA() == true)
        {
            score = 1;
            break;
        }
    }
    //一對
    int tempscore = 0;
    for(int i = 0; i < CARD_NUM; i++)
    {
        if(cardPile[i].isTheSameRank(cardPile[i + 1]) == true)
        {
            tempscore += 5;
            //cout << i << tempscore;
            i ++;
        }
        else
        {
            if(cardPile[i].isA() == true)
                tempscore++;
        }
    }
    if(tempscore > score)
        score = tempscore;
    //同花
    bool fulfill = true;
    for(int i = 0; i < CARD_NUM - 1; i++)
    {
        if(cardPile[i].isTheSameSuit(cardPile[i + 1]) == false)
        {
            fulfill = false;
            break;
        }
    }
    if(fulfill == true)
        score = 20;
    //葫蘆
    fulfill = false;
    bool fulfill2 = false;
    int count = 0;
    for(int i = 0; i < CARD_NUM; i++)
    {
        for(int j = i + 1; j < CARD_NUM; j++)
        {
            if(cardPile[i].isTheSameRank(cardPile[j]) == false)
                break;
            else
                count++;
            //cout << i << " " << j << ":" << count << endl;
        }
        if(count == 1)
        {
            fulfill = true;
            i += 1;
            count = 0;
        }
        if(count == 2)
        {
            fulfill2 = true;
            i += 2;
            count = 0;
        }
    }
    if((fulfill == true) and (fulfill2 == true))
        score = 40; 
    //同花順 and 順
    fulfill = true;
    for(int i = 0; i < CARD_NUM - 1; i++)
    {
        if((i == 0) and (cardPile[0].rank == 1))
        {
            if((cardPile[i + 1].rank != 2) and (cardPile[i + 1].rank != 10))
            {
                fulfill = false;
                break;
            }
        }
        else
        {
            if((cardPile[i].rank + 1) != cardPile[i + 1].rank)
            {
                fulfill = false;
                break;
            }
        }
    }
    if(fulfill == true)
    {
        for(int i = 0; i < CARD_NUM - 1; i++)
        {
            if(cardPile[i].isTheSameSuit(cardPile[i + 1]) == false)
            {
                score = 50;
                fulfill = false;
                break;
            }
        }
    }
    if(fulfill == true)
        score = 100;

    cout << score;
    
    return 0;
}

//insertion sort
void RankSort (Card cardPile[])
{ 
    for(int i = 0; i < CARD_NUM; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(cardPile[j].rank < cardPile[j - 1].rank)
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