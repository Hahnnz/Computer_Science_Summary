//이름과 전화번호를 입력 받아 배열에 저장하고 출력하는 프로그램을 작성하라

#include <iostream>

using namespace std;

int main(){

	char name[20];
	char phone[20];
	
	cout<<"이름 입력 : ";
	cin>>name;
	cout<<name<<"님의 전화번호 입력 : ";
	cin>>phone;
	cout<<"이름 : "<<name<<endl;
	cout<<"전화번호 : "<<phone<<endl;
}