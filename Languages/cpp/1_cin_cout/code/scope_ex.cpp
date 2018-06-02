#include <iostream>

int a = 50;

int main(){
	int a = 50;
	::a+=10;
	printf("%d\n",::a);
}