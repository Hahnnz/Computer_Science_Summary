# Stack and Queue

## Stack
선형 자료구조의 일종으로, **`Last In First Out`** **(LIFO)** 형태의 입출력 형식을 가진다. 즉, 나중에 들어간 원소가 먼저 나온다. 이것은 Stack의 
가장 큰 특징으로, 차곡차곡 쌓이는 구조로 먼저 Stack에 들어간 원소는 맨 바닥에 깔리게 된다. 그렇기 때문에 늦게 들어간 원소들은 그 위에 쌓이게 되고, 호출 시
가장 위에 있는 원소이 호출되는 구조이다.

파이썬에서 Stack 구현은 정말 간단하다.
```python3
My_stack = list() # python에서는 리스트로 스택을 선언한다. list가 이에 필요한 attribute 함수를 가지고 있다.

My_stack.append(value) # My_stack에 value를 스택에 넣는다. push()라고 볼 수 있다.
My_stack.pop(value) # My_stack의 가장 위에 있는 값을 꺼내어 리턴해준다.
My_stack_size = len(My_stack) # My_stack의 크기를 리턴한다.
My_stack_is_empty = True if My_stack_size==0 else False # Stack에 아무것도 없으면 True, 있으면 False를 리턴한다.
```
C++도 라이브러리가 따로 존재하여 include를 해서 언제든지 사용할 수 있다.
```c++
#include <stack>

stack<int> My_stack; // My_stack라는 int 형 자료들을 담을 수 있는 스택을 선언

My_stack.push(1); // push() 괄호 안에 있는 값을 스택에 넣는다.
My_stack.top(); // My_stack의 가장 위에 있는 값을 리턴한다. top는 삭제되지 않는다.
My_stack.pop(); // My_stack의 가장 위에 있는 값을 삭제. 리턴 값은 없다.
My_stack.size(); // My_stack의 크기를 리턴한다.
My_stack.empty(); // 스택에 아무것도 없으면 1(true)을, 스택에 뭐가 있으면 0(false)을 리턴한다.
```
## Queue
선형 자료구조의 일종으로 **`Fist In First Out`** **(FIFO)** 형태의 입출력 형식을 가진다. 즉 먼저 들어간 요소가 먼저 나온다. Stack과는 반대로 먼저
들어간 요소가 맨 앞에서 대기하고 있다가 먼저 나오게 되는 구조이다.


## Examples
### Stack을 이용하여 Queue 구현하기
### Queue을 이용하여 Heap 구현하기
