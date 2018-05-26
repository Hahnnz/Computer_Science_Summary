#include <iostream>

using namespace std;

int main()
{
	int val1, val2;
	int result = 0;

	cout<<"두 개의 숫자입력: ";
	cin>>val1>>val2; // 연속적으로 데이터 입력 명령이 가능

	for(int i=val1; i<val2 ; i++) // for문 안에서도 변수 선언이 가능
	     result+=i;
	 
    //std::cout<<"i = "<<i<<std::endl; // for 밖에서 허용안함
	cout<<"result : "<<result<<endl;
}