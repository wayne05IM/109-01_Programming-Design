#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int* sort(int*, const int*, const int*, int);
int calDelayHour(int, int, int, int, int, int, const int*, const int*, int, int, const int*);

int* feasiblePeriodToRepair = nullptr;
int cntOfFeasiblePeriod = 0;
int main(){
    int productionRate = 0, yReduceRate  = 0, repairingHour = 0, initialYeildRate = 0, totalHour = 0, minYeildRate = 0, cntOfOrder = 0;
    cin >> productionRate >> yReduceRate >> repairingHour >> initialYeildRate >> totalHour >> minYeildRate >> cntOfOrder;
 
    int* seqOfOrders = new int [cntOfOrder];
    int* demandOfOrder = new int [cntOfOrder];
    int* dueTimeOfOrder = new int [cntOfOrder];
    for(int i = 0; i < cntOfOrder; i++){
        seqOfOrders[i] = i;
        cin >> demandOfOrder[i];
    }
    for(int i = 0; i < cntOfOrder; i++){
        cin >> dueTimeOfOrder[i];
    }
    seqOfOrders = sort(seqOfOrders, demandOfOrder, dueTimeOfOrder, cntOfOrder);//先依據給訂規則排序訂單，稍後利用 seqOfOrders 判斷訂單的順序
    
    feasiblePeriodToRepair = new int [totalHour];
    int repairPoint = 0;
    int totalDelayHour = calDelayHour(productionRate, yReduceRate, repairingHour, initialYeildRate, totalHour, minYeildRate, demandOfOrder, dueTimeOfOrder, cntOfOrder, repairPoint, seqOfOrders);//先計算沒有維修的延遲時數，並將可維修的時段存到 feasiblePeriodToRepair
    
    //計算每種維修時段的延遲時數，並選出延遲時數最小的維修時段
    for(int i = 0; i < cntOfFeasiblePeriod; i++){
        int tmpDelayHour = calDelayHour(productionRate, yReduceRate, repairingHour, initialYeildRate, totalHour, minYeildRate, demandOfOrder, dueTimeOfOrder, cntOfOrder, feasiblePeriodToRepair[i], seqOfOrders);;
        if(tmpDelayHour < totalDelayHour){
            repairPoint = feasiblePeriodToRepair[i];
            totalDelayHour = tmpDelayHour;
        }
    }
    
    delete [] demandOfOrder;
    demandOfOrder = nullptr;
    delete [] dueTimeOfOrder;
    dueTimeOfOrder = nullptr;
    delete [] seqOfOrders;
    seqOfOrders = nullptr;
    delete [] feasiblePeriodToRepair;
    feasiblePeriodToRepair = nullptr;

    cout << repairPoint << "," << totalDelayHour;
    return 0;
}


int* sort(int* array, const int* demand, const int* dueTime, int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < i; j++){
            int leftidx = array[i];
            int rightidx = array[j];
            if ((dueTime[leftidx] < dueTime[rightidx]) || // if orderIdLeft is due before orderIdRight
                     (dueTime[leftidx] == dueTime[rightidx] && demand[leftidx] < demand[rightidx]) || //or order less than orderIdRight
                     (dueTime[leftidx] == dueTime[rightidx] && demand[leftidx] == demand[rightidx]
                      && leftidx < rightidx)) { // or just simply has a smaller ID
                array[i] = rightidx;
                array[j] = leftidx;
            }
        }
    }
    return array;
}


int calDelayHour(int pRate, int yReduceRate, int repairingPeriod, int yRate, int totalPeriod, int minYRate, const int* demand, const int* dueTime, int cntOfOrder, int repairPoint, const int* orderSeq){
    int totalDelayHour = 0;

    int* productionPoint = new int [cntOfOrder + 1];
    for(int i = 0; i < cntOfOrder; i++){
        productionPoint[i] = -1;
    }
    int* productionFinishedPoint = new int [cntOfOrder + 1];
    for(int i = 0; i < cntOfOrder; i++){
        productionFinishedPoint[i] = totalPeriod + 1;
    }

    float productionQuantity = 0;
    int productionIndex = 0;
    int productionOrderId = orderSeq[productionIndex];
    productionPoint[productionOrderId] = 1;

    if(repairPoint == 1){
        productionPoint[productionOrderId] = repairPoint + repairingPeriod;
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
            productionQuantity += pRate / 100.0 * yRate;
            
            if(productionQuantity >= demand[productionOrderId]){
                productionQuantity = 0;
                productionFinishedPoint[productionOrderId] = i;

                if(dueTime[productionOrderId] < productionFinishedPoint[productionOrderId]){
                    totalDelayHour += productionFinishedPoint[productionOrderId] - dueTime[productionOrderId];
                }
                productionIndex++;
                if(productionIndex == cntOfOrder){
                    break;
                }
                productionOrderId = orderSeq[productionIndex];
                if(i + 1 == repairPoint){
                    productionPoint[productionOrderId] = i + 1 + repairingPeriod;
                }
                else{
                    productionPoint[productionOrderId] = i + 1;
                }
                
            }

        }
        
    }
    //如果不維修，將可以維修的時段存到 feasiblePeriodToRepair
    if(repairPoint == 0){
        for(int i = 0; i < cntOfOrder; i++){
            productionOrderId = orderSeq[i];
            feasiblePeriodToRepair[cntOfFeasiblePeriod] = productionPoint[productionOrderId];
            cntOfFeasiblePeriod++;
        }
    }
    
    //如果生產時段超過最大可生產時段，則回傳一極大值
    for(int i = 0; i < cntOfOrder; i++){
        productionOrderId = orderSeq[i];
        if(productionFinishedPoint[productionOrderId] > totalPeriod){
            totalDelayHour = INT_MAX;
        }
    }
    
    delete [] productionPoint;
    productionPoint = nullptr;
    delete [] productionFinishedPoint;
    productionFinishedPoint = nullptr;

    
    return totalDelayHour;
}
