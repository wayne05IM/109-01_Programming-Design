#include <iostream>
using namespace std ;
  
void sort(int numOrder , float* orderQuantity , int* orderDeadline , int* originalNum) ;
int chooseOne(int numMachine , float *amount , float *declineRate , int *fixTime , float startRate[] , float *minRate , bool toFix[] , int timeOfMech[] , float quantity , int maxFix , int numFix[]) ;
int main()
{
    //input
    int numMachine=0 , numOrder=0 , maxFix=0 ;
    cin >> numMachine >> numOrder >> maxFix ;
    float *amount = new float [numMachine]() ;
    float *declineRate = new float [numMachine]() ;
    int *fixTime = new int [numMachine]() ;
    float *startRate = new float [numMachine]() ;
    float *minRate = new float [numMachine]() ;
    for(int i=0 ; i<numMachine ; i++)
    {
        cin >> amount[i] >> declineRate[i] >> fixTime[i] >> startRate[i] >> minRate[i];
    }
    float *orderQuantity = new float [numOrder]() ;
    int *orderDeadline = new int [numOrder]() ;
    int *originalNum = new int [numOrder]() ;
    for(int i=0 ; i<numOrder ; i++)
    {
        cin >> orderQuantity[i] >> orderDeadline[i] ;
        originalNum[i]=i+1 ;
    }
 
    //sorting the correct order of the orders
    sort(numOrder , orderQuantity , orderDeadline , originalNum) ;
     
    //finding the optimize situation
        //value saving
    bool* toFix = new bool[1]();
    int* timeOfMech = new int[numMachine]();
 
    int numFix[10000]={0} ;
    int* machineOrder = new int[numMachine]();
    int** result = new int*[numMachine]();
    for(int i = 0; i < numMachine; i++)
        result[i] = new int[10000];
 
        //operations
    for(int i=0 ; i<numOrder ; i++)
    {
        int usingWhich=0 ;
        usingWhich=chooseOne(numMachine , amount , declineRate , fixTime , startRate , minRate , toFix , timeOfMech , orderQuantity[i] , maxFix , numFix) ;
        int x=usingWhich;
        if(toFix[0]==1)
        {
            machineOrder[x]++ ;
            result[x][machineOrder[x]-1]=-1 ;
        }
        machineOrder[x]++ ;
        result[x][machineOrder[x]-1]=originalNum[i] ;
         
        if(toFix[0]==0)
        {
            float sum=0 ;
            while(sum<orderQuantity[i])
            {
                timeOfMech[x]++ ;
                startRate[x]-=declineRate[x] ;
                if(startRate[x]<minRate[x])
                {
                    startRate[x]=minRate[x] ;
                }
                sum+=startRate[x]*amount[x]/100 ;
            }
        }
        if(toFix[0]==1)
        {
            int startFix=timeOfMech[x]+1 ;
            int endFix=timeOfMech[x]+fixTime[x] ;
            for(int i=startFix ; i<=endFix ; i++)
            {
                numFix[i]++ ;
            }
            float sum=0 ;
            startRate[x]=100+declineRate[x] ;
            timeOfMech[x]+=fixTime[x] ;
            while(sum<orderQuantity[i])
            {
                startRate[x]-=declineRate[x] ;
                timeOfMech[x]++ ;
                if(startRate[x]<minRate[x])
                {
                    startRate[x]=minRate[x] ;
                }
                sum+=startRate[x]*amount[x]/100 ;
            }
        }
    }
     
     
     
 
        //output
    for(int i=0 ; i<numMachine ; i++)
    {
        for(int j=0 ; j<machineOrder[i] ; j++)
        {
            if(j==0)
            {
                if(result[i][j]==-1)
                {
                    cout << "M" ;
                }
                else
                {
                    cout <<result[i][j] ;
                }
            }
            else
            {
                if(result[i][j]==-1)
                {
                    cout << "," << "M" ;
                }
                else
                {
                    cout << "," << result[i][j] ;
                }
            }
              
        }
        if(machineOrder[i]==0)
        {
            cout<< 0 ;
        }
        cout << "\n" ;
    }
}
  
//fuctions
void sort(int numOrder , float* orderQuantity , int* orderDeadline , int* originalNum)
{
    if(numOrder!=1)
    {
        sort(numOrder-1 , orderQuantity , orderDeadline , originalNum) ;
    }
    for(int i=numOrder-1 ; i>0 ; i--)
    {
        if(orderDeadline[i]<orderDeadline[i-1])
        {
            int tempT=orderDeadline[i] ;
            orderDeadline[i]=orderDeadline[i-1] ;
            orderDeadline[i-1]=tempT ;
            float tempO=orderQuantity[i] ;
            orderQuantity[i]=orderQuantity[i-1] ;
            orderQuantity[i-1]=tempO ;
            int tempN=originalNum[i] ;
            originalNum[i]=originalNum[i-1] ;
            originalNum[i-1]=tempN ;
        }
        else if(orderDeadline[i]==orderDeadline[i-1])
        {
            if(orderQuantity[i]<orderQuantity[i-1])
            {
                float tempO=orderQuantity[i] ;
                orderQuantity[i]=orderQuantity[i-1] ;
                orderQuantity[i-1]=tempO ;
                int tempN=originalNum[i] ;
                originalNum[i]=originalNum[i-1] ;
                originalNum[i-1]=tempN ;
            }
        }
        else
        {
            break ;
        }
    }
}
  
int chooseOne(int numMachine , float *amount , float *declineRate , int *fixTime , float startRate[] , float *minRate , bool toFix[] , int timeOfMech[] , float quantity , int maxFix , int numFix[])
{
    int minTime=9999999 ;
    int whichOne=numMachine+1 ;
    float compareRate=9999999 ;
    int bestFixTime = 999999;
    bool fix = 0;
    toFix[0] = 0;
    for(int i=0 ; i<numMachine ; i++)
    {
        //no fix
        float sum=0 ;
        int time=timeOfMech[i] ;
        float present=startRate[i] ;
        while(sum<quantity)
        {
            time++ ;
            present-=declineRate[i] ;
            if(present<minRate[i])
            {
                present=minRate[i] ;
            }
                sum+=present*amount[i]/100 ;
        }
 
        int temp1=time ;
        if(temp1<minTime)
        {
            whichOne=i ;
            minTime=time ;
            toFix[0]=0 ;
            fix = toFix;
            compareRate=startRate[i] ;
        }
        if(temp1==minTime)
        {
            if(fix == 1)
            {
                whichOne=i ;
                minTime=time ;
                toFix[0]=0 ;
                fix = toFix;
                compareRate=startRate[i] ;
            }
            else{
                if(startRate[i]<compareRate)
                {
                    whichOne=i ;
                    minTime=time ;
                    toFix[0]=0 ;
                    fix = toFix;
                    compareRate=startRate[i] ;
                }
            }
        }
        int startFix=timeOfMech[i]+1 ;
        int endFix=timeOfMech[i]+fixTime[i] ;
 
        // check if fix > maxfix
        bool test=0 ;
        for(int j=startFix ; j<=endFix ; j++)
        {
            if(numFix[j]==maxFix )
            {
                test=1 ;
                break ;
            }
        }
 
        // fix
        if(test==0)
        {
            sum=0 ;
            time=timeOfMech[i]+fixTime[i] ;
            present=100+declineRate[i] ;
            bool compareTime=0 ;
            while(sum<quantity)
            {
                if(time>temp1)
                {
                    compareTime=1 ;
                    break ;
                }
                time++ ;
                present-=declineRate[i] ;
                if(present<minRate[i])
                {
                    present=minRate[i] ;
                }
                    sum+=present*amount[i]/100 ;
            }
            if(compareTime==1)
            {
                continue ;
            }
 
            int temp2=time ;
            if(temp2<minTime)
            {
                whichOne=i ;
                minTime=time ;
                toFix[0]=1 ;
                fix = toFix;
                compareRate=startRate[i] ;
                bestFixTime = fixTime[i];
            }
            if(temp2==minTime)
            {
                if(fix == 0){
                    continue;
                }
                if(fixTime[i] < bestFixTime){
                    whichOne=i ;
                    minTime=time ;
                    toFix[0]=1 ;
                    fix = toFix;
                    compareRate=startRate[i] ;
                    bestFixTime = fixTime[i];
                }
                else{
                    if(startRate[i]<compareRate)
                    {
                        whichOne=i ;
                        minTime=time ;
                        toFix[0]=1 ;
                        fix = toFix;
                        compareRate=startRate[i] ;
                    }
                }
            }
        }
    }
    return whichOne ;
}
