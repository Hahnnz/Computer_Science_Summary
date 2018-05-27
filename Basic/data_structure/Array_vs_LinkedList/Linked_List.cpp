#include <iostream>

using namespace std;

class Node{
	Node(){
		data = 0;
		next = NULL;
	};
	Node(int i ){
		data = i;
		next = NULL;
	}

	Node *next;
	int data;
};

class List{

	Node *head;

	List(){
		head = NULL;
	};
	List(Node *insertNode){
		head = NULL;
		insert(insertNode);
	};
	void insert(Node *insertNode);
	void del(int delnum);
	void printdata();
};

void List::insert(Node *insertNode){
	if (head == NULL){
		head = insertNode;
	}
	else {
		Node *current = head;
		Node *previous = NULL;
		for (Node *ptr = List::head; ptr!=NULL; ptr->next)
			current = ptr;
		current->next = insertNode;
	}
};

void List::del(int delnum){
	if (head == NULL){
		cout<<"List is Empty"<<endl;
	}
	else {
		Node *current = head;
		Node *previous = NULL;
		for (Node *ptr = List::head; ptr!=NULL; ptr->next){
			previous = current;
			current = ptr;
			if(current->data == delnum){
				if (previous == head && current==head)
					head=current;
				else 
					previous->next = current->next;
				delete current;
				return;
			}
		}
		cout<<delnum<<" cannot find in this list"<<endl;
	}
	return;
};

void printdata(){
	if (head == NULL){
		cout<<"List is Empty"<<endl;
	}
	else{
		for(Node *ptr=head; ptr!=NULL; ptr=ptr->next){
			cout<<ptr->data<<"->"
		} cout<<endl;
	}
};