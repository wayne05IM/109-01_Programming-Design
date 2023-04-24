#include<iostream>
using namespace std;
/* 第一次期中考 考題 */

/* 第一題（30 分）比大小 
本題將給定三個整數 a、b、c (值為0~1000)，
請先由小到大排序，再找出中間的那個數字。
三個數字有可能重複。
*/
int main(){
	//輸入三個整數 
	int a = 0, b = 0, c = 0; 	
	cin >> a >> b >> c;
	
	//找出中間值
	int mid = 0;
	if((a >= b && b >= c) || (c >= b && b >= a)){
		mid = b;
	}else if((b >= a && a >= c) || (c >= a && a >= b)){
		mid = a;
	}else{
		mid = c;
	}
	
	//輸出中間的數 
	cout << mid;	
	return mid;
}










 
