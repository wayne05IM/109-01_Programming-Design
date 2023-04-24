//
//  main.cpp
//  quiz_2
//
//  Created by 黃楷翔 on 2020/10/11.
//  Copyright © 2020年 黃楷翔. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n = 0, m = 0;
    cin >> n >> m;
    int* arr_n = new int [n];
    int* arr_m = new int [m];
    
    for(int i = 0; i < n; i++){
        cin >> arr_n[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr_m[i];
    }
    
    //algo
    if(n < m){
        int min = INT_MAX;
        for(int i = 0; i < n; i++){
            if(arr_n[i] < min){
                min = arr_n[i];
            }
        }
        cout << min;
    }
    else if(n > m){
        int min = INT_MAX;
        for(int i = 0; i < m; i++){
            if(arr_m[i] < min){
                min = arr_m[i];
            }
        }
        cout << min;
    }
    else{
        int sumProduct = 0;
        for(int i = 0; i < n; i++){
            sumProduct += arr_n[i] * arr_m[i];
        }
        cout << sumProduct;
    }
    
    return 0;
}
