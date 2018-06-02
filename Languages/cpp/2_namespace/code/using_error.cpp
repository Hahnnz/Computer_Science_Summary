#include <iostream>
namespace A_com{
	void func(void){
		std::cout<<"A_com에서 정의한 함수"<<std::endl;
	}
}
namespace B_com{
     void func(void){
		std::cout<<"B_com에서 정의한 함수"<<std::endl;
     }
}

using namespace A_com;
using namespace B_com;

int main(void){
   func();
}
