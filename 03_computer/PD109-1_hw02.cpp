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
//	bool prePositive = false;	//�e�@�ӼƬO�_������� 
//	
//	//read the numbers one by one
//	int number = 0;		//��e�Ʀr
//	int index = 1;
//	for(index; index < n+1; index++){
//		cin >> number;
//		if(number<=0 && prePositive==true){	//���q����Ʀb������ 
//			if(index - nowStartIndex > maxLength){//�p�G����e�����A��s 
//				maxLength = index - nowStartIndex;
//				maxStartIndex = nowStartIndex;
//			}
//			prePositive = false;	//�i�J�t�P0���q�� 
//		}
//		if(number>0 && prePositive==false){//�s�@�q����ƶ}�l
//			nowStartIndex = index;	//��e�q�}�l�аO����o
//			prePositive = true;
//		}
//	}
//	
//	//�p��̫�@�q�����
//	if(prePositive==true){
//		if(index - nowStartIndex > maxLength){//��s 
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
//	int nZones = 0;		//�϶��`�� 
//	int demand = 0;		//�`�@�ݭn�h�ֲ�
//	cin >> nZones >> demand;
//	int totalMoney = 0;
//	
//	//���O�p��C�@�Ϭq�������`�� 
//	int ticketsNow = 0;	//�e�q�w��X�h�ֲ�
//	int ticket = 0;		//�o�q������֭p�h�ֲ����� 
//	int price = 0;
//	for(int i=0; i<nZones; i++){
//		cin >> ticket >> price;
//		if(ticket > demand){	//�o�Ӱ϶������S���槹 
//			totalMoney += (demand - ticketsNow) * price;
//			break;
//		}else{					//�϶������槹�F�A�i�U�Ӱ϶� 
//			totalMoney += (ticket - ticketsNow) * price;
//			ticketsNow = ticket;			
//		}
//	}
//	//�̾��D�N�Ax<tn�A���|���ʲ��q�W�X�����϶������p 
//	
//	//��X�`�� 
//	cout << totalMoney;
//	return 0;
//}






////Prob 3
//int main(){
//	int number;
//	cin >> number;
//	
//	// ���O���X�|�Ӧ��
//	int n1 = number / 1000;
//	int n2 = number / 100 % 10;
//	int n3 = number / 10 % 10;
//	int n4 = number % 10;
//	
//	//�p��̤j���i��զX
//	int newNumber = 0;
//	for(int i=0; i<4; i++){
//		//�o���O�ĴX�� 
//		int digit = 1;
//		for(int j=0; j<3-i; j++){
//			digit *= 10;
//		}
//		
//		if(n1>=n2 && n1>=n3 && n1>=n4){
//			newNumber += n1 * digit;
//			n1 = -1;	//�ιL���Ƴ]��-1 
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
//	//��X 
//	cout << newNumber << endl;
//	return 0;
//}






//Prob 4
int main(){
	int number;
	cin >> number;
	
	//�b�X�{6174�e���_����
	bool firstTime = true;
	while(number != 6174){		
		// ���O���X�|�Ӧ��
		int n1 = number / 1000;
		int n2 = number / 100 % 10;
		int n3 = number / 10 % 10;
		int n4 = number% 10;
			
		//�p��̤j���i��զX
		int bigNumber = 0;
		int bn1 = n1;
		int bn2 = n2;
		int bn3 = n3;
		int bn4 = n4;
		for(int i=0; i<4; i++){
			//�o���O�ĴX�� 
			int digit = 1;
			for(int j=0; j<3-i; j++){
				digit *= 10;
			}
			
			if(bn1>=bn2 && bn1>=bn3 && bn1>=bn4){
				bigNumber += bn1 * digit;
				bn1 = -1;	//�ιL���Ƴ]��-1 
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
		
		//�p��̤p���i��զX
		int smallNumber = 0;
		for(int i=0; i<4; i++){
			//�o���O�ĴX�� 
			int digit = 1;
			for(int j=0; j<3-i; j++){
				digit *= 10;
			}
			
			if(n1<=n2 && n1<=n3 && n1<=n4){
				smallNumber += n1 * digit;
				n1 = 10;	//�ιL���Ƴ]��10 
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
		
		//�۴�A�ǳƥγo�������G�}�l�s�@��
		number = bigNumber - smallNumber;
		
		//��X
		if(firstTime){
			cout << number;
			firstTime = false;
		}else{
			cout << ',' << number;
		}
	}

	return 0;
}

