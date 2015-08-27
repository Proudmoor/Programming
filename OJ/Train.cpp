#include <cstdio>
#include <cstdlib>

const int MAXSIZE = 1600001;
//栈的构造中注意将top的值设置为-1，因为数组的第一个下标为0；
template <typename T> class seqStack {
public:
	seqStack():top(-1), maxsize(MAXSIZE){
		Array = new T[maxsize];
		if (Array == NULL){
			printf("no memory to create stack\n");
		}
	}

	seqStack(int size):top(-1),maxsize(size){
		Array = new T[maxsize];
		if(Array == NULL){
			printf("no memory to create stack\n");
		}
	}

	seqStack(T data[], int size):top(-1), maxsize(size){
		Array = new T[maxsize];
		if(Array == NULL){
			printf("no memory to create stack\n");
		}
		for(int i=0; i < maxsize; i++){
			Array[i] = data[i];
		}
		top +=maxsize;
	}

	~seqStack(){
		delete [] Array;
	}
	void push(T const &e){
		if (full()){
			printf("the stack is full\n");
		}
		top ++;
		Array[top] = e;
	}

	T pop(){
		if(empty()){
			printf("the stack is empty.\n");
		}
		T data = Array[top];
		top--;
		return data;
	}

	T &getTop(){
		if(empty()){
			printf("stack is empty.\n");
		}
		return Array[top];
	}

	int empty() const {
		return top == -1;
	}

	int full() const {
		return top == maxsize -1;
	}

	void clear(){
		top = -1;
	}

private:
	int top;
	T* Array;
	int maxsize;
};


bool fesiable(int n, int m, int b[]){
	bool result = true;
	seqStack<int> stackS(m+1);
	int checkA = 0;
	for(int i = 0; i < n; i++){
		int cur = b[i];
		while(stackS.empty() || checkA < cur){
			checkA++;
			stackS.push(checkA);
			if(stackS.full()){
				result = false;
				break;
			}
		}
		if(stackS.getTop()==cur)
			stackS.pop();
	}
	if (result && stackS.empty()){
		result = true;
	}
	else {
		result = false;
	}
	return result;
}
void move(int n, int m, int b[]){
	seqStack<int> stackS(m);
	int checkA = 0;
	for(int i = 0; i < n; i++){
		int cur = b[i];
		while(stackS.empty() || checkA < cur){
			checkA++;
			stackS.push(checkA);
			printf("push\n");
		}
		if(stackS.getTop()==cur){
			stackS.pop();
			printf("pop\n");
		}
	}
}
int main(void){
	int m,n;
	scanf("%d %d",&n, &m);
	int *b = new int[n];

	for(int i=0; i < n; i++){
		scanf("%d",&b[i]);
	}
	
	if(fesiable(n,m,b)){
		move(n,m,b);
	} else {
		printf("No\n");
	}
	delete [] b;
	return 0;
}