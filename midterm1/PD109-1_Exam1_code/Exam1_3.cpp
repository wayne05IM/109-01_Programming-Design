//
//  main.cpp
//  Exam
//

#include <iostream>
using namespace std;

const int MAX_BORDER = 100;
const int MAX_NUMSTATION = 20;
const int MAX_NUMRAILS = 100;
const int DIM = 2;


int main(int argc, const char * argv[]) {
    
    // Input
    int xLimit = 0, yLimit = 0, numStations = 0, numRails = 0;  // m, n, s, t
    int map[MAX_BORDER + 1][MAX_BORDER + 1] = {0};              // store map
    int stations[MAX_NUMSTATION][DIM] = {0};                    // store stations
    int rails[MAX_NUMRAILS][DIM] = {0};                         // store rails
    
    // cin
    cin >> xLimit >> yLimit >> numStations >> numRails;
    // cin map
    for(int x = 0; x <= xLimit; x++){
        for(int y = 0; y <= yLimit; y++){
            cin >> map[x][y];
        }
    }
    // cin stations
    for(int s = 0; s < numStations; s++){
        cin >> stations[s][0] >> stations[s][1];
    }
    // cin rails
    for(int t = 0; t < numRails; t++){
        cin >> rails[t][0] >> rails[t][1];
    }
    
    // Algorithm
    bool isCounted[MAX_BORDER + 1][MAX_BORDER + 1] = {0};       // 1 if p_xy has been counted
    int numCover = 0;
    
    // For all rails
    for(int t = 0; t < numRails; t++){
        // Find start and end station ID
        int startID = rails[t][0] - 1, endID = rails[t][1] - 1;
        // Find x,y of start and end station
        int startX = stations[startID][0], startY = stations[startID][1];
        int endX = stations[endID][0], endY = stations[endID][1];
        
        // if start > end then swap
        if(startX > endX){
            int temp = startX;
            startX = endX;
            endX = temp;
        }
        
        if(startY > endY){
            int temp = startY;
            startY = endY;
            endY = temp;
        }
        
        // For citizens on the horizontal line
        for(int x = startX; x <= endX; x++){
            // Count if this address is in the map and haven't been counted
            if(x >= 0 && x <= xLimit ){
                if(!isCounted[x][startY]){
                    numCover += map[x][startY];
                    isCounted[x][startY] = 1;
                }
            }
        }
        for(int y = startY; y <= endY; y++){
            // Count if this address is in the map and haven't been counted
            if(y >= 0 && y <= yLimit ){
                if(!isCounted[startX][y]){
                    numCover += map[startX][y];
                    isCounted[startX][y] = 1;
                }
            }
        }
    }
    
    cout << numCover;
    
    return 0;
}




