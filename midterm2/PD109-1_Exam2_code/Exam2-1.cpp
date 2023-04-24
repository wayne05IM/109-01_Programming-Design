//
//  main.cpp
//  Exam2-1


#include <iostream>
using namespace std;

int getLenIncrease(const int num, int* arr);
void swap(int& num1, int& num2);

int main(int argc, const char * argv[]) {
    
    // Input
    int num = 0;
    cin >> num;
    int* arr = new int[num];
    for(int i = 0; i < num; i++){
        cin >> arr[i];
    }
    // Algo
    
    int maxLen = getLenIncrease(num, arr);
    int maxI = 0, maxJ = 0;
    // for every pair
    for(int i = 0; i < num; i++){
        for(int j = i+1; j < num; j++){
            
            swap(arr[i], arr[j]);
            int len = getLenIncrease(num, arr);
            if(len > maxLen){
                maxLen = len;
                maxI = i;
                maxJ = j;
            }
            swap(arr[i], arr[j]);
        }
    }
    cout << maxLen;
    delete [] arr;
//    cout << "\n" << arr[maxI] << "," << arr[maxJ];
    
    return 0;
}

void swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int getLenIncrease(const int num, int* arr){
    int maxLen = 1, len = 1;
    for(int i = 0; i < num - 1; i++){
        if(arr[i] < arr[i+1]){
            len++;
        }
        else{
            if(maxLen < len){
                maxLen = len;
            }
            len = 1;
        }
    }
    if(maxLen < len){
        maxLen = len;
    }
    
    return maxLen;
}
