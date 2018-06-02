#include <iostream>

using namespace std;

void MyFunc(int a){  
   cout << a << " : MyFunc(int a) called " << endl;  
} 

void MyFunc(char  a){  
   cout << a << " : MyFunc(char a) called " << endl;  
}

void MyFunc(double  a){  
   cout << a << " : MyFunc(char a) called " << endl;  
}

int main(void){
   MyFunc(3.14);
   MyFunc(85); 
   MyFunc('A');
}
