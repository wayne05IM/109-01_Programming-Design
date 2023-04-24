#include<iostream>
#include<cmath>
using namespace std;

/*PD 109-1 HW4*/



//Prob 1
/** 本題思路:
先用array將數字全讀入。
運行函數看看能否買到所有想買的票。
若不行，窮舉從0到想買的票數的所有組合，
找出可行解中的最佳解。	 
最後輸出當前最佳解 **/


const int CUTOFF_NUM_MAX = 10;	//最多有幾種門檻 
const int TICKET_KIND = 2; 		//票的種類數


// 此組合是否能夠購買 
bool isFeasibleToBuy(const int ticketNum[], const int intervalNum[], int budget, 
const int cutoffs[][CUTOFF_NUM_MAX], const int prices[][CUTOFF_NUM_MAX + 1]){
	int needMoney = 0;	//購買所需的總價 
	
	//對每一種票，算出總價 
	for(int i=0; i < TICKET_KIND; i++){
		int ticketBought = 0;	//此種類已購買的票數
		//對每個區段，分別計算價格 
		for(int j=0; j < intervalNum[i]; j++){
			if(ticketNum[i] >= cutoffs[i][j]){	// case 1 整個區段買完
				needMoney += prices[i][j] * (cutoffs[i][j] - ticketBought);
				ticketBought = cutoffs[i][j];			
			}else{								// case 2 此區段只買部分 
				needMoney += prices[i][j] * (ticketNum[i] - ticketBought);
				ticketBought = ticketNum[i];
				break;				
			}					
		}
		if(ticketBought < ticketNum[i]){	// 需要買到最後一個區段的票 
			needMoney += prices[i][intervalNum[i]] * (ticketNum[i] - ticketBought);		 
		}
	}
	return (needMoney <= budget);	//回傳是否夠錢買票 
} 


// 此組合總共要花多少錢 
int priceOf(const int ticketNum[], const int intervalNum[], 
const int cutoffs[][CUTOFF_NUM_MAX], const int prices[][CUTOFF_NUM_MAX + 1]){
	int needMoney = 0;	//購買所需的總價 
	
	//對每一種票，算出總價 
	for(int i=0; i < TICKET_KIND; i++){
		int ticketBought = 0;	//此種類已購買的票數
		//對每個區段，分別計算價格 
		for(int j=0; j < intervalNum[i]; j++){
			
			if(ticketNum[i] >= cutoffs[i][j]){	// case 1 整個區段買完
				needMoney += prices[i][j] * (cutoffs[i][j] - ticketBought);
				ticketBought = cutoffs[i][j];
			}else{								// case 2 此區段只買部分 
				needMoney += prices[i][j] * (ticketNum[i] - ticketBought);
				ticketBought = ticketNum[i];
				break;				
			}					
		}
		if(ticketBought < ticketNum[i]){	// 需要買到最後一個區段的票 
			needMoney += prices[i][intervalNum[i]] * (ticketNum[i] - ticketBought);		 
		}
	}
	return needMoney;	//回傳總價 
} 


// 組合A是否優先於組合B
bool isBetter(const int ticketNum_A[], const int ticketNum_B[], const int buyingMod){
	if(buyingMod == 1){	// 先買第一種票：選第一種票多的，一樣的話選第二種票多的 
		if(ticketNum_A[0] > ticketNum_B[0] || 
		(ticketNum_A[0] == ticketNum_B[0] && ticketNum_A[1] >= ticketNum_B[1])){
			return true;
		}else{
			return false;
		}
	}else if(buyingMod == 2){	// 先買第二種票：和上面相反 
		if(ticketNum_A[1] > ticketNum_B[1] || 
		(ticketNum_A[1] == ticketNum_B[1] && ticketNum_A[0] >= ticketNum_B[0])){
			return true;
		}else{
			return false;
		}		
	}else{	// 先看總票數，再看票數乘積，最後看第一種票票數 
		int totalTicket[2] = {
			ticketNum_A[0] + ticketNum_A[1], 
			ticketNum_B[0] + ticketNum_B[1]
		};
		int ticketMultiply[2] = {
			ticketNum_A[0] * ticketNum_A[1], 
			ticketNum_B[0] * ticketNum_B[1]
		};	
		if((totalTicket[0] > totalTicket[1]) || 
		(totalTicket[0] == totalTicket[1] && ticketMultiply[0] > ticketMultiply[1]) ||
		(totalTicket[0] == totalTicket[1] && ticketMultiply[0] == ticketMultiply[1] && ticketNum_A[0] > ticketNum_B[0])){	
			return true;
		}else{
			return false;
		}
	} 
} 



int main(){
	/* 宣告變數 */
	int intervalNumber[TICKET_KIND] = {0};	//每種票區間總數
	int ticketNumber[TICKET_KIND] = {0};	//每種票需要多少
	int totalBudget = 0;					//總預算 
	int buyingMod = 0;						//購買模式
	int intervalCutoff[TICKET_KIND][CUTOFF_NUM_MAX] = {0};	 //區段門檻 
	int intervalPrice[TICKET_KIND][CUTOFF_NUM_MAX + 1] = {0};//區段價格 
	
	
	/* 讀取數值 */ 
	for(int i=0; i < TICKET_KIND; i++){
		cin >> intervalNumber[i];		//讀取區段數 
	}
	for(int i=0; i < TICKET_KIND; i++){
		cin >> ticketNumber[i];			//讀取欲購買票數 
	} 
	cin >> totalBudget >> buyingMod;	//讀取預算與購買模式	
	
	for(int i=0; i < TICKET_KIND; i++){	//讀取票數門檻價格
		for(int j=0; j < intervalNumber[i]; j++){
			cin >> intervalCutoff[i][j] >> intervalPrice[i][j];
		} 
		cin >> intervalPrice[i][intervalNumber[i]];	//讀取最後一段的票價 
	}



	/* 若可以買齊，直接結束 */ 
	if(isFeasibleToBuy(ticketNumber, intervalNumber, totalBudget, intervalCutoff, intervalPrice)){
		for(int i=0; i < TICKET_KIND; i++){
			cout << ticketNumber[i] << ",";
		}
		cout << priceOf(ticketNumber, intervalNumber, intervalCutoff, intervalPrice);
		return 1;
	}



	/* 窮舉所有可能的票數組合 */
	int bestTicketNow[TICKET_KIND] = {0};	//當前最佳解
	for(int i = 0; i <= ticketNumber[0]; i++){		// i: 第一種票的數量 
		for(int j = 0; j <= ticketNumber[1]; j++){	// j: 第二種票的數量 
			int ticketTry[TICKET_KIND] = {i, j};
			// 如果此嘗試可行，且比當前最佳解更好，就更新 
			if(isFeasibleToBuy(ticketTry, intervalNumber, totalBudget, intervalCutoff, intervalPrice)
			&& isBetter(ticketTry, bestTicketNow, buyingMod)){
				bestTicketNow[0] = ticketTry[0];
				bestTicketNow[1] = ticketTry[1];
			}
		}
	}



	/* 輸出總價 */
	for(int i=0; i < TICKET_KIND; i++){
		cout << bestTicketNow[i] << ',';
	}
	cout << priceOf(bestTicketNow, intervalNumber, intervalCutoff, intervalPrice);

	return 0;
}






//// Problem 2  Moving average
//float MAPE(int windowSize , int periodCut , const int sales[]){
//	float MAPE = 0;
//	// 算第i期的MA
//	for(int i = windowSize; i < periodCut; i++){
//		float x = float(sales[i]);	// x = 第i期實際值
//		 
//		// 回溯j期，求第i期的預測值(f)
//		float f = 0;
//		for(int j=1; j <= windowSize; j++){
//			f += sales[i-j];
//		} 
//		f /= windowSize;
//		
//		// 本期MAE = (實際值-估計值) / 實際值
//		float MAE = abs(x - f) / x;
//		
//		// 加入MAPE 
//		MAPE += MAE;
//	}
//	MAPE /= float(periodCut - windowSize);	//替MAPE取平均 
//	return MAPE;
//}
//
//int main(){
//	/* 輸入 */ 
//	int period = 0;	//總歷史資料期數 
//	cin >> period; 
//	int data[period] = {0};
//	for(int i=0; i<period; i++){
//		cin >> data[i];
//	}
//	
//	/* 試算每種預測期數的MAPE */
//	int maxMAPE = 9999;	//依據題目限制算出MAPE最大為9999 
//	int bestMAPE = maxMAPE + 1;	// 當前最佳MAPE(%取整)
//	// bestMAPE 預設為題意中可能的最大值+1，即|10000 - 1| / 1 + 1 
//	int bestWindow = -1;
//	for(int n=2; n<=6; n++){	// n = window size
//		int newMAPE = int(MAPE(n, period, data) * 100.0);
//		// 若取得更小的MAPE，就更新 
//		cout << newMAPE<<endl;
//		if(newMAPE < bestMAPE){
//			bestWindow = n;
//			bestMAPE = newMAPE;
//		}
//	}
//	
//	cout << bestWindow << "," << bestMAPE;
//	
//	return 0;
//}






//// Problem 3 Airport Location
//int LOCATION_NUM = 0;
//
//// revenue(): 給定一組解，求其淨利(利潤總合-建造成本) 
//int revenue(const bool solution[], const int cost[], int* const profit[]){
//	int answer = 0;	//將要輸出的總利潤
//	
//	//算成本
//	for(int i = 0; i < LOCATION_NUM; i++){	
//		answer -= cost[i] * solution[i];		
//	}
//	
//	//算利潤（先前算過的不重算）
//	for(int i = 0; i < LOCATION_NUM - 1; i++){	 
//		for(int j = i + 1; j < LOCATION_NUM; j++){
//			answer += profit[i][j - i - 1] * solution[i] * solution[j]; 
//		}		
//	}
//	
//	return answer;
//}
//
//int main(){
//	/* 輸入 */
//	cin >> LOCATION_NUM;
//	int cost[LOCATION_NUM] = {0};			//建造成本  
//	for(int i = 0; i < LOCATION_NUM; i++){
//		cin >> cost[i];
//	}
//	//處理只有一個機場的特例 
//	if(LOCATION_NUM == 1){
//		cout << "0;0";
//		return 0;
//	}
//	
//	int* benifit[LOCATION_NUM - 1] = {0};	//航線利潤
//	for(int i = 0; i < LOCATION_NUM - 1; i++){
//		benifit[i] = new int[LOCATION_NUM - i - 1] {0};
//		for(int j = i + 1; j < LOCATION_NUM; j++){
//			cin >> benifit[i][j - i - 1];	//讓array變成倒三角，節省儲存空間 
//		}
//	}
//	
//	
//	
//	/* 重複刪除機場，直到無法增進利潤 */
//	bool build[LOCATION_NUM] = {0};		//當前答案
//	bool newAnswer[LOCATION_NUM] = {0};	//嘗試中的新一組解
//	for(int i = 0; i < LOCATION_NUM; i++){	//預設全部蓋滿
//		build[i] = 1;
//		newAnswer[i] = 1;
//	}
//	int revenueNow = revenue(build, cost, benifit);
//	bool change = true;	//前一輪有沒有增進效益
//	 
//	//前一輪有增進利潤，就繼續執行： 
//	while(change){
//		change = false;		//重置有無進步的旗標 
//		int remove = -1;	//這輪要移除的機場的index 
//		//對於每個答案中可以置換的項 
//		for(int i = 0; i < LOCATION_NUM; i++){
//			//已經沒機場就略過它
//			if(!build[i]){ 
//				continue;
//			}
//			
//			//有機場，則試著拆掉它
//			newAnswer[i] = false;			 
//			int newRevenue = revenue(newAnswer, cost, benifit);
//			if(newRevenue > revenueNow){ //若拆後利潤上升，則更新	 
//				remove = i;	//更新要拆的機場index 
//				revenueNow = newRevenue;
//				change = true;				
//			}
////			cout<<"here "<<i<<", old="<<revenueNow<<", new="<<newRevenue<<endl;
//			newAnswer[i] = true;	//拆後復原，才能嘗試拆另一個 
//		} 
//		if(change){	//有改善的話，拆掉能改善最大的那個機場 
//			build[remove] = false;
//			newAnswer[remove] = false;
////			cout<<"real remove "<<remove<<", revenue="<<revenueNow<<endl; 
//		}		
//	} 
//	
//	/* 輸出 */
//	cout << build[0];
//	for(int i = 1; i < LOCATION_NUM; i++){
//		cout << "," << build[i];
//	}
//	cout << ";" << revenueNow;
//	return 0;
//}








