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
    int xLimit = 0, yLimit = 0, range = 0, numStations = 0, numRails = 0;  // m, n, s, t
    int map[MAX_BORDER + 1][MAX_BORDER + 1] = {0};              // store map
    int stations[MAX_NUMSTATION][DIM] = {0};                    // store stations
    int rails[MAX_NUMRAILS][DIM] = {0};                         // store rails
    
    // cin
    cin >> xLimit >> yLimit >> range >> numStations >> numRails;
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
    bool isRailCounted[MAX_BORDER + 1][MAX_BORDER + 1] = {0};       // 1 if p_xy has been counted in rails
    bool isStationCounted[MAX_BORDER + 1][MAX_BORDER + 1] = {0};    // 1 if p_xy has beed counted in stations
    int railCover = 0;
    int stationCover = 0;
    
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
            // Count if this point is in the map and has been counted
            if(x >= 0 && x <= xLimit ){
                if(!isRailCounted[x][startY]){
                    railCover += map[x][startY];
                    isRailCounted[x][startY] = 1;
                }
            }
        }
        for(int y = startY; y <= endY; y++){
            // Count if this point is in the map and has been counted
            if(y >= 0 && y <= yLimit ){
                if(!isRailCounted[startX][y]){
                    railCover += map[startX][y];
                    isRailCounted[startX][y] = 1;
                }
            }
        }
    }
    
    // For all stations
    for(int s = 0; s < numStations; s++){
        // Find x,y of station
        int stationX = stations[s][0], stationY = stations[s][1];
        // For all point in the range
        for(int x = stationX - range; x <= stationX + range; x++){
            for(int y = stationY - range; y <= stationY + range; y++){
                // Check if this point is out of boundary
                if(x >= 0 && x <= xLimit && y >= 0 && y <= yLimit){
                    // Check if this point has been counted
                    if(!isStationCounted[x][y]){
                        stationCover += map[x][y];
                        isStationCounted[x][y] = 1;
                    }
                }
            }
        }
    }
    
    cout << stationCover << "," << railCover;
    
    return 0;
}



