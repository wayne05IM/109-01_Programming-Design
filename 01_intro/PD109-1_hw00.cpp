#include <iostream>
using namespace std;


int main(){

    int fullFare = 0, studentFare = 0, fullPrice = 0, studentPrice = 0, money = 0;
    // Input
    cin >> fullFare >> studentFare >> fullPrice >> studentPrice >> money;      
    int total = fullFare * fullPrice + studentFare * studentPrice;
    
    if (total > money){
        cout << "-1," << total - money;
    }
    else{
        cout << money - total;            
    }       

    return 0;
}
