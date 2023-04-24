# include <iostream>
# include <cstring>
using namespace std;

// Struct Card, rank is stored as integer
struct Card
{
	char suit;
	int rank;
	bool init(char cardstr[]);
	bool isA();
};

// Initialize the Card, while transform the rank of input char as integer
// This function is useless in this problem, due to the input is not char while shuffling
bool Card :: init(char cardstr[])
{
	suit = cardstr[0];
	
	if(static_cast<int>(strlen(cardstr)) == 3)
	{
		rank = 10;
	}
	else
	{
		if(cardstr[1] == 'A')
		{
			rank = 1;
		}
		if(cardstr[1] == '2')
		{
			rank = 2;
		}
		if(cardstr[1] == '3')
		{
			rank = 3;
		}
		if(cardstr[1] == '4')
		{
			rank = 4;
		}
		if(cardstr[1] == '5')
		{
			rank = 5;
		}
		if(cardstr[1] == '6')
		{
			rank = 6;
		}
		if(cardstr[1] == '7')
		{
			rank = 7;
		}
		if(cardstr[1] == '8')
		{
			rank = 8;
		}
		if(cardstr[1] == '9')
		{
			rank = 9;
		}
		if(cardstr[1] == 'J')
		{
			rank = 11;
		}
		if(cardstr[1] == 'Q')
		{
			rank = 12;
		}
		if(cardstr[1] == 'K')
		{
			rank = 13;
		}
	}
	return true;
}

// Check is the card contains A. Only use in the getpoint function
bool Card :: isA()
{
	if(rank == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Struct Deck, contain many member functions
struct Deck
{
	Card* cards;
	int cardCnt;
	void init();
	void addCard(Card c);
	void redo();
	int getpoint();
	bool flush();
	bool straight();
	bool fullhouse();
	int pairCnt();
	int ACnt();
};

// Initailizer
void Deck :: init()
{
	cards = new Card[5];
	cardCnt = 0;
}

// Add the card into deck
void Deck :: addCard(Card c)
{
	if(cardCnt != 5)
	{
		cards[cardCnt] = c;
		cardCnt++;
	}	
}

// Bubble sort the deck in the order of number
void Deck :: redo()
{
	bool change = false;
	while(true)
	{
		change = false;
		for(int i = 0 ; i < cardCnt - 1 ; i++)
		{
			if(cards[i].rank > cards[i+1].rank)
			{
				swap(cards[i].rank,cards[i+1].rank);
				swap(cards[i].suit,cards[i+1].suit);
				change = true;
			}
		}
		if(!change)
		{
			break;
		}
	}
}

// Check is the deck contain flush
bool Deck :: flush()
{
	if(cards[0].suit == cards[1].suit and cards[1].suit == cards[2].suit and cards[2].suit == cards[3].suit and cards[3].suit == cards[4].suit)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

// Check is the deck contain straight
bool Deck :: straight()
{
	redo();
	if(cards[0].rank >= 11)
	{
		return false;
	}
	else
	{
		for(int i = 0 ; i < cardCnt - 1 ; i++)
		{
			if(cards[i].rank + 1 != cards[i+1].rank and (cards[0].rank != 1 or cards[0].rank != 10))
			{
				return false;
			}
		}
	}
	return true;
}

// Check is the deck contain full house
bool Deck :: fullhouse()
{
	redo();
	if((cards[0].rank == cards[1].rank and cards[1].rank == cards[2].rank and cards[2].rank != cards[3].rank and cards[3].rank == cards[4].rank) or (cards[0].rank == cards[1].rank and cards[1].rank != cards[2].rank and cards[2].rank == cards[3].rank and cards[3].rank == cards[4].rank))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Check is the deck contain one pair or two pair, four of a kind count as two pair
int Deck :: pairCnt()
{
	redo();
	if(cards[0].rank == cards[1].rank)
	{
		if(cards[2].rank == cards[3].rank or cards[3].rank == cards[4].rank)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if(cards[1].rank == cards[2].rank)
		{
			if(cards[3].rank == cards[4].rank)
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			if(cards[2].rank == cards[3].rank or cards[3].rank == cards[4].rank)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

// Check is the deck contain how many A
int Deck :: ACnt()
{
	redo();
	int count = 0;
	for(int i = 0 ; i < cardCnt ; i++)
	{
		if(cards[i].isA())
		{
			count++;
		}
	}
	return count;
}

// Count the point of deck
int Deck :: getpoint()
{
	if(cardCnt != 5)
	{
		return 0;
	}
	
	// Sort the deck
	redo();
	
	if(flush() and straight())
	{
		return 100;
	}
	else if(straight())
	{
		return 50;
	}
	else if(fullhouse())
	{
		return 40;
	}
	else if(flush())
	{
		return 20;
	}
	else if(pairCnt() >= 1)
	{
		if(ACnt()%2 == 1)
		{
			// The score of A only count, if there are only exactly one A or three A
			return 5*pairCnt()+1;
		}
		else
		{
			// If there are no A, two A or four A, do not count the score of A, due to it is count as pair in the first place
			return 5*pairCnt();
		}	
	}
	else
	{
		return ACnt();
	}
}

// The randomizer, provided by instructor
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

int main() 
{			
	int s = 0, a = 0, b = 0, c = 0, r = 0, best_score = -1, best_player = -1;
	
	cin >> s >> a >> b >> c;	
	Randomizer r1 = {a, b, c, s};
	
	Card* all_cards = new Card[52];
	
	// Install all card right into Card, do not use the initializer
	for(int i = 0 ; i < 13 ; i++)
	{
		all_cards[i].suit = 'S';
		all_cards[i].rank = i+1;
	}
	for(int i = 0 ; i < 13 ; i++)
	{
		all_cards[13+i].suit = 'H';
		all_cards[13+i].rank = i+1;
	}
	for(int i = 0 ; i < 13 ; i++)
	{
		all_cards[26+i].suit = 'D';
		all_cards[26+i].rank = i+1;
	}
	for(int i = 0 ; i < 13 ; i++)
	{
		all_cards[39+i].suit = 'C';
		all_cards[39+i].rank = i+1;
	}
	
	// Shuffle the card according to the rule
	for(int i = 0 ; i < 20 ; i++)
	{
		r = r1.rand() % 52;
		swap(all_cards[i], all_cards[r]);
	}
	
	// Deal the card according to the rule
	for(int i = 0 ; i < 4 ; i++)
	{
		Card hand;
		Deck player;
		player.init();
		for(int j = 0 ; j < 5 ; j++)
		{
			hand.suit = all_cards[j*4+i].suit;
			hand.rank = all_cards[j*4+i].rank;
			player.addCard(hand);
		}
		if(best_score < player.getpoint())
		{
			best_score = player.getpoint();
			best_player = i+1;
		}
	}
	
	cout << best_player << "," << best_score;
	
	return 0;
} 
