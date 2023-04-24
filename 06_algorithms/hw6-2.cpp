#include <iostream>
#include <cmath>
using namespace std;

const int MAX_RANGE = 1001;

int coveredPop(const int pop[][MAX_RANGE], const int x, const int y, const int r, const int xLimit, const int yLimit);

int main()
{
    int xLimit = 0, yLimit = 0, range = 0;
    cin >> xLimit >> yLimit >> range;

    int popArray[MAX_RANGE][MAX_RANGE] = {0};
    for (int j = 0; j <= yLimit; j++)
        for(int i = 0; i <= xLimit; i++)
            cin >> popArray[i][j];

    int maximumPopulation = 0;
    for (int j = 0; j <= yLimit; j++)
    {
        for(int i = 0; i <= xLimit; i++)
        {
            int covered = coveredPop(popArray, i, j, range, xLimit, yLimit);
            if(maximumPopulation < covered)
                maximumPopulation = covered;
        }
    }

    cout << maximumPopulation;

    return 0;
}

int coveredPop(const int pop[][MAX_RANGE], const int x, const int y, const int r, const int xLimit, const int yLimit)
{
    int covered = 0;
	for (int j = y - r; j <= y + r; j++)
    {
		for (int i = x - (r - abs(j - y)); i <= x + (r - abs(j - y)); i++)
        {
            if((0 <= i) and (i <= xLimit) and (0 <= j) and (j <= yLimit))
			    covered += pop[i][j];
        }
    }
	return covered;
}