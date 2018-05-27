# 노드 클래스 생성
class Node:
    def __init__(self, data):
        self.data = data # 데이터 저장
        self.next = None # 다음 노드 주소 저장
        
class create:
    def __init__(self):
        head_node = Node("Head")
        
        self.head = head_node
        self.tail = head_node
        
        self.current = None
        self.previous = None
        
        self.node_num = 0
    
    # 노드 추가.
    # 데이터를 입력하면 연결리스트 맨 뒤에 노드를 추가
    def append(self, data):
        new_node = Node(data) # 노드 생성
        self.tail.next = new_node # 현재 맨 뒤 노드에 새로 생성한 노드 주소값 입력
        self.tail = new_node # 그리고 현재 맨 끝 노드를 이번에 생성한 노드로 대치
        
        self.node_num +=1 # 노드 수 추가
    
    # 노드 삭제. 
    # 현재 노드를 삭제하고 이전 노드는 삭제 노드의 다음노드로 연결되도록 설정
    def delete(self, data):
        # 현재 노드가 마지막 노드이면 마지막 노드 삭제
        if self.current is self.tail:
            self.tail = self.previous
        
        # 현재 노드 다음 노드 주소값을 이전 노드 다음노드주소 값에 입력
        self.previous.next = self.current.next 
        self.current = self.previous # 삭제노드 이전 노드를 현재 노드로 설정
        
        self.node_num -=1 # 노드수 감소
    
    # 다음 노드 이동
    # 현재 노드의 다음 노드가 존재하지 않으면 멈춤. 아니라면 현재 노드를 이전 노드로 옮겨주고
    # 현재 노드를 설정해준 이전 노드의 다음 노드를 호출하여 저장
    def next(self):
        if self.current.next==None:
            return None
        self.previous = self.current
        self.current = self.current.next
        
        return self.current.data
        
    # 현재 상태를 맨 앞 노드로 복귀시켜줌
    def first(self):
        if self.node_num == 0 : return 0
        
        self.previous = self.head
        self.current = self.head.next
        
    # 현재 연결 리스트 안에 들어있는 아이템 값들 출력
    def print_data(self):
        data_list = list() # 출력할 아이템 값들 저장
        self.first() # 노드를 현재 상태로 되돌려 놓음
        
        # 전체 노드를 지나가면서 데이터 값들을 문자열로 형변환하여 저장
        for _ in range(self.node_num):
            data_list.append(str(self.current.data))
            self.next()
        
        # 끝으로 가있는 현재상태를 다시 처음으로 초기화
        self.first()
        
        return "->".join(data_list)
    
    def search(self, data):
        self.first()
        
        for i in range(self.node_num):
            if data==self.current.data:
                return i, data
            else :
                self.next()
        
    # 연결 리스트 출력
    def length(self):
        return self.node_num
    