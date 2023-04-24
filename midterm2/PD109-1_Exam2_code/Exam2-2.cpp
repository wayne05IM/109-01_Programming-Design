#include <iostream>

using namespace std;

bool isOverlap(int*, int*);

int main(){
    int n = 0;
    cin >> n;
    int** rectangles = new int* [n];

    for(int i = 0; i < n; i++){
        rectangles[i] = new int [8];
        for(int j = 0; j < 8; j++){
            cin >> rectangles[i][j];
        }
    }
    
    int overlap = 0;
    
    //一一確認兩矩形是否重疊
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(isOverlap(rectangles[i], rectangles[j])){
                overlap++;
            }
        }
    }
    cout << overlap;
    
    for(int i = 0; i < n; i++){
        delete [] rectangles[i];
        rectangles[i] = nullptr;
    }
    delete [] rectangles;
    rectangles = nullptr;
}

//判斷兩個舉行是否重疊
bool isOverlap(int* rectangle1, int* rectangle2){
    //若矩形1完全在矩形2左邊、或矩形1完全在矩形2右邊，就沒有重疊
    if(rectangle1[1] <= rectangle2[0] or rectangle1[0] >= rectangle2[1])
        return false;
    //若矩形1完全在矩形2下方、或矩形2完全在矩形1下方，就沒有重疊
    if(rectangle1[5] <= rectangle2[6] or rectangle1[6] >= rectangle2[5])
        return false;
    return true;
}

