# Associative Caches

Direct mapped cache의 경우 메모리상의 Block이 자신의 주소에 정해진 Cache Block으로만 갈 수 있다. <br/>
하지만 Associative Caches의 경우, 메모리 상의 한 Block이 cache의 다른 위치에도 복사될 수 있도록 한다.

## Fully associative
* 주어진 memory block을 cache entry 어디에든지 복사를 할 수 있다.
* 하지만 cache의 모든 내용을 한번에 탐색할 수 있어야만 한다. 
* 즉 모든 cache entry에는 Comparator가 붙어있어야 한다.
  * 결과적으로 가격이 비싸진다.

## n-way set associative
Direct mapped cache와 Fully associative의 중간 단계<br/>
이러한 Cache의 경우 entry가 아닌 set 단위로 구성이 되어있다.
* 주어진 memory block를 받으면 하나의 정해진 set으로 가게된다. 하지만 그 셋 안에는 n개의 entry가 존재한다.
* 그래서 memory block를 받으면 주어진 set내의 비어있는 entry로 향하게 된다.
  * 
*
