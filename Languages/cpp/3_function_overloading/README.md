# 함수 (Function)
함수란 독립적인 기능을 가진 작은 프로그램으로 볼 수 있다. 함수의 종류를 크게 세가지로 나누어 보면 다음과 같다.
* Main<br/>
  main 함수는 프로그램을 시작할 때 가장 먼저 실행된다. OS가 이 함수를 호출한다.
* 표준함수<br/>
  이미 정의가 되어 있는 함수들을 칭한다.
* 사용자 정의 함수<br/>
  프로그래머가 필요에 의해 만드는 함수를 뜻한다.
  
# 함수 오버로딩 (Function Overloading)
함수 오버로딩이란, 서로 다른 여러 개의 함수가 하나의 이름을 공유(연결)하는 것이다. 
함수 오버로딩은 서로 다른 데이터형을 대상으로 하지만 기본적으로는 같은 작업을 하는 함수들에만 사용하는 것이 좋다

* **함수의 오버로딩이 가능한 이유**

  함수의 이름을 동일하게 만들고, 전달하는 인자의 개수에 따라서 어떠한 함수를 호출할 지 구분한다. C언어에서는 함수 호출시 함수의 이름을 기준으로 호출 대상을 찾지만,
  C++에서는 함수의 이름, 매개변수의 개수, 자료형의 기준으로 함수를 호출한다. 

  **함수의 이름이 같더라도 매개변수의 자료형, 개수가 다르면 다른 함수로 취급한다.**

* **함수의 오버로딩 조건**
   * 매개 변수의 개수 혹은 타입이 일치하지 않는다.
   * 매개 변수의 자료형 순서가 달라야 한다.
   * 반환형은 함수 호출방식과는 무관하므로 해당되지 않는다.

함수를 호출하면서 인자를 넘겨줄때와 매개변수 타입이 틀릴때는 컴파일러가 자동 형변환 해서 실행한다.
###### 매개변수 자료형에 따른 함수 오버로딩 예시
```cpp
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
```
>**출력**<br/>3.14 : MyFunc(char a) called<br/>85 : MyFunc(int a) called<br/>A : MyFunc(char a) called

###### 입력되는 매개변수의 형과 함수에서 사용되는 매개변수가 다를 때
```cpp
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
```
>**출력**<br/>5<br/>4.4<br/>4


