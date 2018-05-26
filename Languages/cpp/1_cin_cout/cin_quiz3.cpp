//구구단 프로그램을 만들고 사용자에게 숫자를 입력 받아 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성하라.

#include <iostream>

using namespace std;

int main(void){
	int su;
	cout<<"단 입력 : ";
	cin>>su;

	for(int i=1;i<=9;i++){
		cout<< su <<" x "<< i <<" = "<< su*i <<endl;
	}
}