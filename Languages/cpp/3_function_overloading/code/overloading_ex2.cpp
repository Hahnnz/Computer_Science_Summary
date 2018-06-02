#include <iostream>

using namespace std;

int Add2(int n1, int n2){
   return n1+n2;
}

double Add(double n1, double n2){
   return n1+n2;
}

int main(void){
   int in1=2, in2=3;
   cout<<Add2(in1,in2)<<endl;

   float f1=1.1; double f2=3.3;
   cout <<Add(f1, f2)<<endl;
   cout <<Add2(f1, f2)<<endl;
}
