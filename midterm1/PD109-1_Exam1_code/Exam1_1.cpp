#include<iostream>
using namespace std;
/* �Ĥ@�������� ���D */

/* �Ĥ@�D�]30 ���^��j�p 
���D�N���w�T�Ӿ�� a�Bb�Bc (�Ȭ�0~1000)�A
�Х��Ѥp��j�ƧǡA�A��X���������ӼƦr�C
�T�ӼƦr���i�୫�ơC
*/
int main(){
	//��J�T�Ӿ�� 
	int a = 0, b = 0, c = 0; 	
	cin >> a >> b >> c;
	
	//��X������
	int mid = 0;
	if((a >= b && b >= c) || (c >= b && b >= a)){
		mid = b;
	}else if((b >= a && a >= c) || (c >= a && a >= b)){
		mid = a;
	}else{
		mid = c;
	}
	
	//��X�������� 
	cout << mid;	
	return mid;
}










 
