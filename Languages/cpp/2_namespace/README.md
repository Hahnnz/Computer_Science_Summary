# Namescope
이름 공간이라는 개념은 대형 프로젝트 내에서 이름 충돌을 막기위한 도구로, 일반적으로 규모가 작은 프로젝트 내에서는 거의 사용되지 않는다.

여러 개의 회사에 프로젝트를 나눠주고 완성본을 받았을 때 둘을 합칠려고 봤더니 같은 이름으로 정의된 함수와 변수들이 더러 존재한다.
이럴때 같은 함수와 변수의 지정된 공간의 이름을 따로 지정해주면 쉽게 사용 및 수정이 가능하다.

다시 정리하자면, C++에서는 함수나 변수의 이름이 중복되는 것을 막아주고, 코드의 가독성을 높이기 위해 namespace라는 문법을 제공한다.

namespace안의 데이터들은 `::` 연산자 앞에 `namespace`이름을 적고 `::` 뒤에 데이터를 적음으로써 불러올 수 있다.

또한, `using namespace (namespace명);` 형태로 선언하게 되면, `(namespace명)::` 의 형태를 생략할 수 있다.

###### 이름 공간의 충돌 해결 예시 (1)
```cpp
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
```
>**출력**<br/>A_com에서 정의한 함수<br/>B_com에서 정의한 함수

###### 이름 공간의 충돌 해결 예시 (2)
```cpp
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
```
>**출력**<br/>main score : 300<br/>A_range score : 100<br/>B_range score : 200<br/>60<br/>30<br/>20

# `using`을 이용한 전역적 명시시
`using namespace ...`를 사용하여 namespcae를 명시해주면 `::`를 사용하지 않고도 해당 namespace 안에 있는 변수들이나 혹은 함수들을 `namespace::`를 붙이지 
않고도 사용을 할 수 있다. 하지만 이러한 선언은 이름의 충돌을 막기위한 이름 공간의 선언을 의미없게 만든다.

예를들어 위의 코드 예시에서 `A_range`와 `B_range`를 모두 `using`을 사용하였다면 함수의 이름이 겹쳐 컴파일러는 어떠한 함수를 사용해야하는지 모르겠다는 에러를 띄울 것이다.
```cpp
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
```
>./using_error.cpp:17:4: error: call to 'func' is ambiguous<br/>
&ensp;&ensp;&ensp;func();<br/>
&ensp;&ensp;&ensp;^~~~<br/>
./using_error.cpp:3:7: note: candidate function<br/>
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;void func(void){<br/>
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;^<br/>
./using_error.cpp:8:11: note: candidate function<br/>
&ensp;&ensp;&ensp;&ensp;&ensp;void func(void){<br/>
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;^<br/>
1 error generated.<br/>

그래서 `using`을 이용한 전역적 명시시 사용하는 것은 좋지만 이러한 문제를 잘 생각하고 사용해야만 한다.

# namespace에 대한 별칭 부여

이렇게 namespace를 사용하다보면 namespace안에 또 다른 namespace가 존재하게 될 것이고 이러할 경우 쓰고 싶은 변수 혹은 함수를 불러오기 위해 수많은
namespace를 참고해와야만 할것이다. 아래 코드 예시를 보면 AAA라는 namespace안에 BBB라는 namespace가 존재하고, 또 BBB안에 CCC라는 namespace가 존재한다.

이러한 경우, CCC의 n을 호출해오기 위해서는 무려 3번의 호출이 필요하다. `AAA::BBB::CCC::n`을 입력해야만 해당 변수의 호출이 가능하다.

그래서 이렇게 기다란 호출 방식을 방지하기 위해서 특별한 호출 칭호를 붙여 더욱 효율적인 사용이 가능하다. 예를 들어, `namespace All=AAA::BBB::CCC;`라고 명시해주면
CCC의 n을 불러오기 위해서 기다란 `AAA::BBB::CCC::n`을 `All::n`으로 짧게 명시해서 사용이 가능하다. 그래서 좀 더 의미적인 뜻을 부여하거나 긴 호출 코드를 짧게 만들어
주는데 사용할 수 있다.



###### namespace에 대한 별칭 부여 예시
```cpp
#include <iostream>
using namespace std;
namespace AAA{
        int n=1;
        namespace BBB{
                int n=2;
                namespace CCC{
                        int n=3;
                }
        }
}

int main(void){
        cout<<"AAA : "<<AAA::n<<endl;
        cout<<"BBB : "<<AAA::BBB::n<<endl;
        cout<<"CCC : "<<AAA::BBB::CCC::n<<endl;

        namespace All=AAA::BBB::CCC;
        namespace All2=AAA::BBB;

        cout<<"All  : "<<All::n<<endl;
        cout<<"All2 : "<<All2::n<<endl;
}
```
>**출력**<br/>AAA : 1<br/>BBB : 2<br/>CCC : 3<br/>All  : 3<br/>All2 : 2
