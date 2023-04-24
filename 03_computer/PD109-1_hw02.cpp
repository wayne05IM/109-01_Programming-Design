#include<iostream>
using namespace std;

////Prob 1 
//int main(){
//	int n;
//	cin>>n;
//	
//	int maxLength = 0;
//	int maxStartIndex = 0;
//	int nowStartIndex = 1;
//	bool prePositive = false;	//前一個數是否為正整數 
//	
//	//read the numbers one by one
//	int number = 0;		//當前數字
//	int index = 1;
//	for(index; index < n+1; index++){
//		cin >> number;
//		if(number<=0 && prePositive==true){	//本段正整數在此結束 
//			if(index - nowStartIndex > maxLength){//如果比先前的長，更新 
//				maxLength = index - nowStartIndex;
//				maxStartIndex = nowStartIndex;
//			}
//			prePositive = false;	//進入負與0的段落 
//		}
//		if(number>0 && prePositive==false){//新一段正整數開始
//			nowStartIndex = index;	//當前段開始標記移到這
//			prePositive = true;
//		}
//	}
//	
//	//計算最後一段正整數
//	if(prePositive==true){
//		if(index - nowStartIndex > maxLength){//更新 
//			maxLength = index - nowStartIndex;
//			maxStartIndex = nowStartIndex;
//		} 
//	}	 
//	
//	//print answer
//	if(maxLength==0){
//		cout<<maxLength;
//	}else{
//		cout<<maxLength<<','<<maxStartIndex;
//	}	
//	return 0;
//}






////Prob 2
//int main(){
//	int nZones = 0;		//區間總數 
//	int demand = 0;		//總共需要多少票
//	cin >> nZones >> demand;
//	int totalMoney = 0;
//	
//	//分別計算每一區段的票價總價 
//	int ticketsNow = 0;	//前段已售出多少票
//	int ticket = 0;		//這段價格賣到累計多少票為止 
//	int price = 0;
//	for(int i=0; i<nZones; i++){
//		cin >> ticket >> price;
//		if(ticket > demand){	//這個區間的票沒有賣完 
//			totalMoney += (demand - ticketsNow) * price;
//			break;
//		}else{					//區間的票賣完了，進下個區間 
//			totalMoney += (ticket - ticketsNow) * price;
//			ticketsNow = ticket;			
//		}
//	}
//	//依據題意，x<tn，不會有購票量超出票價區間的情況 
//	
//	//輸出總價 
//	cout << totalMoney;
//	return 0;
//}






////Prob 3
//int main(){
//	int number;
//	cin >> number;
//	
//	// 分別取出四個位數
//	int n1 = number / 1000;
//	int n2 = number / 100 % 10;
//	int n3 = number / 10 % 10;
//	int n4 = number % 10;
//	
//	//計算最大的可能組合
//	int newNumber = 0;
//	for(int i=0; i<4; i++){
//		//這次是第幾位 
//		int digit = 1;
//		for(int j=0; j<3-i; j++){
//			digit *= 10;
//		}
//		
//		if(n1>=n2 && n1>=n3 && n1>=n4){
//			newNumber += n1 * digit;
//			n1 = -1;	//用過的數設成-1 
//		}else if(n2>=n1 && n2>=n3 && n2>=n4){
//			newNumber += n2 * digit;
//			n2 = -1;
//		}else if(n3>=n1 && n3>=n2 && n3>=n4){
//			newNumber += n3 * digit;
//			n3 = -1;
//		}else{
//			newNumber += n4 * digit;
//			n4 = -1;
//		}	
//	}
//	
//	//輸出 
//	cout << newNumber << endl;
//	return 0;
//}






//Prob 4
int main(){
	int number;
	cin >> number;
	
	//在出現6174前不斷重複
	bool firstTime = true;
	while(number != 6174){		
		// 分別取出四個位數
		int n1 = number / 1000;
		int n2 = number / 100 % 10;
		int n3 = number / 10 % 10;
		int n4 = number% 10;
			
		//計算最大的可能組合
		int bigNumber = 0;
		int bn1 = n1;
		int bn2 = n2;
		int bn3 = n3;
		int bn4 = n4;
		for(int i=0; i<4; i++){
			//這次是第幾位 
			int digit = 1;
			for(int j=0; j<3-i; j++){
				digit *= 10;
			}
			
			if(bn1>=bn2 && bn1>=bn3 && bn1>=bn4){
				bigNumber += bn1 * digit;
				bn1 = -1;	//用過的數設成-1 
			}else if(bn2>=bn1 && bn2>=bn3 && bn2>=bn4){
				bigNumber += bn2 * digit;
				bn2 = -1;
			}else if(bn3>=bn1 && bn3>=bn2 && bn3>=bn4){
				bigNumber += bn3 * digit;
				bn3 = -1;
			}else{
				bigNumber += bn4 * digit;
				bn4 = -1;
			}	
		}
		
		//計算最小的可能組合
		int smallNumber = 0;
		for(int i=0; i<4; i++){
			//這次是第幾位 
			int digit = 1;
			for(int j=0; j<3-i; j++){
				digit *= 10;
			}
			
			if(n1<=n2 && n1<=n3 && n1<=n4){
				smallNumber += n1 * digit;
				n1 = 10;	//用過的數設成10 
			}else if(n2<=n1 && n2<=n3 && n2<=n4){
				smallNumber += n2 * digit;
				n2 = 10;
			}else if(n3<=n1 && n3<=n2 && n3<=n4){
				smallNumber += n3 * digit;
				n3 = 10;
			}else{
				smallNumber += n4 * digit;
				n4 = 10;
			}	
		}
		
		//相減，準備用這輪的結果開始新一輪
		number = bigNumber - smallNumber;
		
		//輸出
		if(firstTime){
			cout << number;
			firstTime = false;
		}else{
			cout << ',' << number;
		}
	}

	return 0;
}

