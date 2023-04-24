#include <iostream>
using namespace std;

int calDelayHour(int, int, int, int, int, int, const int*, const int*, int, int);

int* feasiblePeriodToRepair = nullptr;
int cntOfFeasiblePeriod = 0;

int main(){
    int productionRate = 0, yReduceRate  = 0, repairingHour = 0, initialYeildRate = 0, totalHour = 0, minYeildRate = 0, cntOfOrder = 0;
    cin >> productionRate >> yReduceRate >> repairingHour >> initialYeildRate >> totalHour >> minYeildRate >> cntOfOrder;
 
    int* demandOfOrder = new int [cntOfOrder];
    int* dueTimeOfOrder = new int [cntOfOrder];
    for(int i = 0; i < cntOfOrder; i++){
        cin >> demandOfOrder[i];
    }
    for(int i = 0; i < cntOfOrder; i++){
        cin >> dueTimeOfOrder[i];
    }
    
    feasiblePeriodToRepair = new int [totalHour];
    int repairPoint = 0;
    int totalDelayHour = calDelayHour(productionRate, yReduceRate, repairingHour, initialYeildRate, totalHour, minYeildRate, demandOfOrder, dueTimeOfOrder, cntOfOrder, repairPoint);//先計算沒有維修的延遲時數，並將可維修的時段存到 feasiblePeriodToRepair
    
    
    //計算每種維修時段的延遲時數，並選出延遲時數最小的維修時段
    for(int i = 0; i < cntOfFeasiblePeriod; i++){
        int tmpDelayHour = calDelayHour(productionRate, yReduceRate, repairingHour, initialYeildRate, totalHour, minYeildRate, demandOfOrder, dueTimeOfOrder, cntOfOrder, feasiblePeriodToRepair[i]);;
        if(tmpDelayHour < totalDelayHour){
            repairPoint = feasiblePeriodToRepair[i];
            totalDelayHour = tmpDelayHour;
        }
    }
    
    delete [] demandOfOrder;
    demandOfOrder = nullptr;
    delete [] dueTimeOfOrder;
    dueTimeOfOrder = nullptr;
    delete [] feasiblePeriodToRepair;
    feasiblePeriodToRepair = nullptr;

    cout << repairPoint << "," << totalDelayHour;
    return 0;
}


int calDelayHour(int pRate, int yReduceRate, int repairingPeriod, int yRate, int totalPeriod, int minYRate, const int* demand, const int* dueTime, int cntOfOrder, int repairPoint){
    int totalDelayHour = 0;

    int* productionPoint = new int [cntOfOrder + 1];
    for(int i = 0; i < cntOfOrder; i++){
        productionPoint[i] = 0;
    }

    float productionQuantity = 0;
    int productionIndex = 0;
    productionPoint[productionIndex] = 1;

    if(repairPoint == 1){
        productionPoint[productionIndex] = repairPoint + repairingPeriod;
    }
    
    int nonProduceHourLeft = 0;
    
    //每一期，計算生產量，並判斷目前是哪張訂單，將該張訂單開始生產的時段存到 productionPoint
    for(int i = 1; i <= totalPeriod; i++){
        nonProduceHourLeft --;
        if(i == repairPoint){
            yRate = 100 + yReduceRate;
            nonProduceHourLeft = repairingPeriod;
        }

        if(nonProduceHourLeft <= 0){
            if(yRate - yReduceRate >= minYRate){
                yRate -= yReduceRate;
            }
            else{
                yRate = minYRate;
            }
            productionQuantity += pRate/ 100.0 * yRate;
            
            if(productionQuantity >= demand[productionIndex]){
                productionQuantity = 0;
                productionIndex++;
                productionPoint[productionIndex] = i + 1;
                if(dueTime[productionIndex - 1] < productionPoint[productionIndex] - 1){
                    totalDelayHour += productionPoint[productionIndex] - 1 - dueTime[productionIndex - 1];
                }
                if(productionIndex == cntOfOrder){
                    break;
                }
            }
            

        }
        
    }
    
    //如果不維修，將可以維修的時段存到 feasiblePeriodToRepair
    if(repairPoint == 0){
        for(int i = 0; i < cntOfOrder; i++){
            feasiblePeriodToRepair[cntOfFeasiblePeriod] = productionPoint[i];
            cntOfFeasiblePeriod++;
        }
    }
    
    //如果生產時段超過最大可生產時段，則回傳一極大值
    for(int i = 0; i < cntOfOrder; i++){
        if(productionPoint[i] > totalPeriod){
            totalDelayHour = INT_MAX;
        }
    }
    
    delete [] productionPoint;
    productionPoint = nullptr;
    
    return totalDelayHour;
}
