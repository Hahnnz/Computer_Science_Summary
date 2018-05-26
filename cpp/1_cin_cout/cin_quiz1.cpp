//10개의 숫자를 입력 받아 총 입력 받은 숫자의 합을 구하는 프로그램을 작성하라.

#include <iostream>

using namespace std;

int main(){
	int input,ret=0;
	for(int i=0;i<10;i++){
		cout<<i+1<<"번째 정수 입력 : ";
		cin>>input;
		ret += input;
	}
	cout<<"합 : "<<ret<<endl;
}