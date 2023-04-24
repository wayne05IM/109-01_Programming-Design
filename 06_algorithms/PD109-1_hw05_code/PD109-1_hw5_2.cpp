//
//  main.cpp
//  hw5-2

#include <iostream>
#include <cmath>
using namespace std;

const int AXIS_MAXLEN = 1000;


int main() {
    // Input
    int xLimit = 0, yLimit = 0, range = 0;
    cin >> xLimit >> yLimit >> range;
    int map[AXIS_MAXLEN + 1][AXIS_MAXLEN + 1] = {0};
    
    for(int y = 0; y <= yLimit; y++){
        for(int x = 0; x <= xLimit; x++){
            cin >> map[x][y];
        }
    }
    
    // Algo
    int maxCover = 0;
    for(int x = 0; x <= xLimit; x++){
        for(int y = 0; y <= yLimit; y++){
            int cover = 0;
            // Find the range of covarage
            for(int i = x - range; i <= x + range; i++){
                int yRange = range - abs(x - i);
                for(int j = y - yRange; j <= y + yRange; j++){
                    // Check if this point is inside of the map
                    if(i >= 0 && i <= xLimit && j >= 0 && j <= yLimit){
                        cover += map[i][j];
                    }

                }
            }
            if(cover > maxCover){
                maxCover = cover;
            }
            
        }
    }
    
    cout << maxCover;
    
    return 0;
}



