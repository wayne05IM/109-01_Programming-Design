#include<iostream>
using namespace std;

int inputGraphInfo(int** neighbors[], int* degrees[]);
void printGraph(int** neighbors[], int* degrees[], int nodeCnt);
void releaseMemory(int** neighbors[], int* nodeCnt);
bool isNeighbor(int** neighbors[], int* degrees[], int i, int j);

int main()
{
    int** neighbors = 0;
    int* degrees = {0};
    int nodeCnt= inputGraphInfo(neighbors, degrees);
    printGraph(neighbors, degrees, nodeCnt);
    releaseMemory(neighbors, nodeCnt);

    return 0;
}

int inputGraphInfo(int** neighbors[], int* degrees)
{
    int nodeCnt= 0;
    cin >> nodeCnt;

    neighbors = new int*[nodeCnt];

    for(int i= 0; i< nodeCnt; i++)
    {
        // cout<< "Node " << i
        //     << "\'s degree is: ";
        cin>> degrees[i];
        neighbors[i] = new int[degrees[i]];
        // cout<< "Node " << i
        //      << "\'s neighbors: ";
        for(int j = 0; j < degrees[i]; j++)
        cin >> neighbors[i][j];
    }  
    return nodeCnt;
}

/*void printGraph(int* neighbors[], const int degrees[], int nodeCnt)
{
    for(int i= 0; i< nodeCnt; i++)
    {
        // cout<< "Node " << i<< ": ";
        for(int j = 0; j < degrees[i]; j++)
            cout<< neighbors[i][j] << " ";
        cout<< "\n";
    }
}*/

void printGraph(int** neighbors[], int* degrees, int nodeCnt)
{
    for(int i= 0; i< nodeCnt; i++)
    {
        for(int j = 0; j < nodeCnt; j++)
        {
            bool isNei = isNeighbor(neighbors, degrees, i, j);
            if(isNei == true)
                cout << 1;
            else
                cout << 0;
            cout << " ";
        }
        cout<< "\n";
    }
}

bool isNeighbor(int* neighbors[], const int degrees[], int i, int j)
{
    for(int k = 0; k < degrees[i]; k++)
    {
        if(neighbors[i][k] == j)
            return true;
    }
    return false;
}

void releaseMemory(int* neighbors[], int nodeCnt)
{
    for(int i= 0; i< nodeCnt; i++)
        delete [] neighbors[i];
}
