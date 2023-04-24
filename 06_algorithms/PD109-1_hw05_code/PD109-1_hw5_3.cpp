//
//  main.cpp
//  hw5_3

#include <iostream>
#include <cmath>
using namespace std;

const int MAX_BORDER = 100;
const int MAX_NUMSTATION = 20;
const int MAX_NUMRAILS = 190;
const int DIM = 2;


int min2Num(const int num1, const int num2);
void serve(const int start[DIM], const int end[DIM], bool counted[][MAX_BORDER + 1]);


int main(int argc, const char * argv[]) {
    
    // Input
    int xLimit = 0, yLimit = 0, numStations = 0, railsLenLimit = 0;  // m, n, s, L
    int map[MAX_BORDER + 1][MAX_BORDER + 1] = {0};              // store map
    int stations[MAX_NUMSTATION][DIM] = {0};                    // store stations
    int rails[MAX_NUMRAILS][DIM] = {0};                         // store rails
    bool isRailHorizon[MAX_NUMRAILS] = {0};                     // store rails info
    int railsLen[MAX_NUMRAILS] = {0};                           // store rails len
    
    
    cin >> xLimit >> yLimit >> numStations >> railsLenLimit;
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
    
    // Store potential rails and rails info.
    int railsID = 0;
    for(int s = 0; s < numStations; s++){
        // If the station can connect this cin station, than there is a potential rail between them.
        for(int i = 0; i < s; i++){
            if(stations[i][0] == stations[s][0]){
                isRailHorizon[railsID] = 0;
                int minY = stations[i][1], startID = i, endID = s;
                if(minY > stations[s][1]){
                    startID = s;
                    endID = i;
                }
                // The stationID stored in rails begin from 0, so we do not +1 here.
                rails[railsID][0] = startID;
                rails[railsID][1] = endID;
                railsLen[railsID] = stations[endID][1] - stations[startID][1];
                railsID ++;
            }
            else if(stations[i][1] == stations[s][1]){
                isRailHorizon[railsID] = 1;
                int minX = stations[i][0], startID = i, endID = s;
                if(minX > stations[s][0]){
                    startID = s;
                    endID = i;
                }
                // The stationID stored in rails begin from 0, so we do not +1 here.
                rails[railsID][0] = startID;
                rails[railsID][1] = endID;
                railsLen[railsID] = stations[endID][0] - stations[startID][0];
                railsID ++;
            }
        }
    }
    int numRails = railsID;
    
    
//    for(int r = 0; r < numRails; r++){
//        cout << "rails:" << r << "|start:" << rails[r][0] << "|end:" << rails[r][1] << "|horizon:" << isRailHorizon[r] << "|len:" << railsLen[r] << endl;
//    }
    
    // Algo
    bool counted[MAX_BORDER + 1][MAX_BORDER + 1] = {0};
    bool built[MAX_NUMRAILS] = {0};
    int totalRailsLen = 0;
    int totalBenefit = 0;
    // At most numRails run. Each run at most build one rail.
    for(int t = 0; t < numRails; t++){
        int maxBenefit = 0, minLen = MAX_BORDER, minSumID = numStations, minMinID = numStations, railsToBuild = -1;
        for(int r = 0; r < numRails; r++){
            // Only consider those rails that haven't been built and whose length will not exceed length Limit.
            if(!built[r] && railsLen[r] + totalRailsLen <= railsLenLimit){
                // Compute benefit
                int benefit = 0, startID = rails[r][0], endID = rails[r][1];
                if(isRailHorizon[r]){
                    int y = stations[startID][1];
                    for(int x = stations[startID][0]; x <= stations[endID][0]; x++){
                        if(!counted[x][y]){
                            benefit += map[x][y];
                        }
                    }
                }
                else{
                    int x = stations[startID][0];
                    for(int y = stations[startID][1]; y <= stations[endID][1]; y++){
                        if(!counted[x][y]){
                            benefit += map[x][y];
                        }
                    }
                }
                // 用交叉相乘比大小
                int adjustBenefit = benefit * minLen, compareBenefit = maxBenefit * railsLen[r];
                int sumID = rails[r][0] + rails[r][1];
                int minID = min2Num(rails[r][0], rails[r][1]);
                
                // If match one of these four conditions, then change the rail to build.
                if((adjustBenefit > compareBenefit) ||
                   (adjustBenefit == compareBenefit && railsLen[r] < minLen) ||
                   (adjustBenefit == compareBenefit && railsLen[r] == minLen && sumID < minSumID) ||
                   (adjustBenefit == compareBenefit && railsLen[r] == minLen && sumID == minSumID && minID < minMinID)){
                    maxBenefit = benefit;
                    minLen = railsLen[r];
                    minSumID = sumID;
                    minMinID = minID;
                    railsToBuild = r;
                }
            }
        }
        // If we find one rail to build,
        if(maxBenefit > 0){
            // then record number of people we just covered and the length we just built.
            totalBenefit += maxBenefit;
            totalRailsLen += railsLen[railsToBuild];
            built[railsToBuild] = true;
            // Serve the people on the rail and record these position in counted to prevent redundant counting.
            int startID = rails[railsToBuild][0], endID = rails[railsToBuild][1];
            int start[DIM] = {stations[startID][0], stations[startID][1]}, end[DIM] = {stations[endID][0], stations[endID][1]};
            serve(start, end, counted);
//            cout << "Round " << t << "|建造鐵路" << railsToBuild << "|benefit:" << maxBenefit << endl;
        }
        else{
            break;
        }
        
    }
    
    cout << totalBenefit << "," << railsLenLimit - totalRailsLen;
    
    return 0;
}

// Given two numbers, find the large one
int min2Num(const int num1, const int num2){
    if(num1 <= num2){
        return num1;
    }
    else{
        return num2;
    }
}

// Record the counted location
void serve(const int start[DIM], const int end[DIM], bool counted[][MAX_BORDER + 1]){
    for(int x = start[0]; x <= end[0]; x++){
        for(int y = start[1]; y <= end[1]; y++){
            counted[x][y] = 1;
        }
    }
}
