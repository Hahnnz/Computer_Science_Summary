#include <iostream>

namespace A_range{
	int score = 100;
	int Func(int s){
		return s/5;
	}
} 

namespace B_range{
	int score = 200;
	int Func(int s){
		return s/10;
	}
} 

int main(void){
	int score = 300;  
	std::cout << "main score : " ;
	std::cout << score << std::endl;
	std::cout << "A_range score : "; 
	std::cout << A_range::score << std::endl;
	std::cout << "B_range score : "; 
	std::cout << B_range::score << std::endl;

	std::cout << A_range::Func(score)<<std::endl;
	std::cout << B_range::Func(score)<<std::endl;
	std::cout << A_range::Func(A_range::score)<<std::endl;
}
