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
int main(void){
   A_com::func();
   B_com::func();
}
