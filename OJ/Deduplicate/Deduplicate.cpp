#include <cstdio>
#include <cstdlib>
#include <cstring>

long hashCode(char key[]){
	int i = 0; long s = 0; 

	while(key[i] != '\0'){
		s = s + key[i] * (i << 1);
		i++;
	}
	return s;
}
struct Node{
	int code;
	int count;
	Node *next;
	Node *prev;
	Node(int c = 0){
		code = c;
		count = 0;
		next = NULL;
		prev = NULL;
	}
};

class list{
private:
	Node *head; Node *tail;
	int _size;
	void init(){
		head = new Node(); 
		tail = new Node();
		head -> next = tail; head ->prev = NULL;
		tail -> prev = head; tail ->next = NULL;
		_size = 0;
	}
public:
	list(){
		init();
	}
	void insertA(Node *p, Node *e){
		e -> prev = p -> prev;
		e -> next = p;
		p->prev ->next = e;
		p-> prev = e;
		_size++;
	}
	void insertB(Node *p, Node *e){
		e -> prev = p;
		e -> next = p -> next;
		p->next -> prev = e;
		p -> next = e;

		_size++;
	}
	void addNode(Node *p){
		head ->next->prev = p;
		p -> next = head -> next;
		head -> next = p;
		p -> prev = head;
		_size++;
	}
	Node *getHead(){
		return head -> next;
	}
	Node *getTail(){
		return tail->prev;
	}
	int getSize(){
		return _size;
	}
};

int main (int argc, char** argv){
#ifndef _OJ_
	freopen("input.txt", "r", stdin);
#endif
	char string[40]; 
	int n ,key;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", string);
		key = hashCode(string);
		printf("%d\n", key);
	}

	list *foodlist;
	foodlist->addNode(new Node(10));
	foodlist->addNode(new Node(20));
	Node *p = foodlist->getHead();
	int i = foodlist -> getSize();
	while(p ->next!= NULL){

		printf("Node %d is %d \n", i, p->code);
		i++;
		p = p->next;
	}

}