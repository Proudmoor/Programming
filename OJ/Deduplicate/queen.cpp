#include <iostream>
#include <cstdlib>
#include <cstdio>

template <typename T>
class Queen{
private:
	int mSize; 
	T * mElem; int mCapacity;

public:
	Queen(int s = 0, int c = 100001,T v =0){
	    mElem = new T[mCapacity = c];
		for(mSize = 0; mSize < s; mElem[mSize++] = v);
	}
	void insert(int r, const T& e){
		for (int i = mSize; i > r; i --)
			mElem[i] = mElem[i - 1];
		mElem[r] = e;
		mSize++;
	}

	int remove(int r){
		return remove(r, r+1);
	}
	int remove(int lo, int hi){
		if(hi == lo) return 0;
		while(hi < mSize){
			mElem[lo++] = mElem[hi++];
		}
		mSize = lo;
		return hi - lo;
	}
	int size() const {return mSize;};
	bool empty(){
		return !mSize;
	}
	void enqueen(const T& e){
		insert(size(), e);
	}
	T dequeen(){
		T bak = mElem[0];
		remove(0);
		return bak;
	}
	T back(){
		return mElem[mSize -1];
	}
	T front(){
		return mElem[0];
	}
};

typedef int Vdata;
struct EdgeNode{
	Vdata pointTo;
	EdgeNode* nextEdge;
};

struct VertexNode{
	Vdata data;
	int radio;
	EdgeNode *firstNode;
};
const int MAX = 10001;
class GraphList{
private:
	VertexNode Graph[MAX];
	int n, e;
public:
	GraphList();
	~GraphList();
	void PrintList();
	bool bfs(int);
	int BFS();
};

bool GraphList::bfs(int v){
	Queen<int> queen;
	bool result = true;
	int next;
	Graph[v].radio = 1;
	queen.enqueen(v);
	while(!queen.empty()){
		v = queen.dequeen();
		printf("%d-->",v+1);
		// EdgeNode *p = Graph[v].firstNode;
		// while(p != NULL){
		// 	next = p->pointTo - 1;

		// 	if(Graph[next].radio == 0){
		// 		Graph[next].radio = - Graph[v].radio;
		// 		queen.enqueen(next);printf("%d", next);
		// 	} else if(Graph[next].radio == Graph[v].radio){
		// 		result = false;
		// 	}
		// 	p = p -> nextEdge;
		// }
		for(EdgeNode *p = Graph[v].firstNode; p!=NULL; p = p->nextEdge){
			next = p -> pointTo -1;
			if(Graph[next].radio == 0){
				Graph[next].radio = -Graph[v].radio;
				queen.enqueen(next);
			} else if(Graph[next].radio == Graph[v].radio){
				result = false; 
			}
		}
	}
	printf("\n\n");
	return result;
}
int GraphList::BFS(){
	int res = 1;
	for(int i = 0; i < n; i++){
		if(Graph[i].radio == 0){
			bool r = bfs(i);
			if(!r){
				res = -1;
				break;
			}
		}
	}
	return res;
}
GraphList::GraphList(){
	scanf("%d %d\n", &n, &e);
	for(int i = 0; i < n; i++){
		Graph[i].data = i+1;
		Graph[i].radio = 0;
		Graph[i].firstNode = NULL;
	}

	int start, end;
	for(int i = 0; i < e; i++){
		scanf("%d %d\n", &start, &end);
		EdgeNode *node = new EdgeNode();
		EdgeNode *p;
		node->pointTo = end;

		if(Graph[start -1].firstNode == NULL)
			Graph[start -1].firstNode = node;
		else {
			p = Graph[start -1].firstNode;
			while(p->nextEdge){
				p = p->nextEdge;
			}
			p->nextEdge = node;
		}

		EdgeNode *node2 = new EdgeNode();
		node2->pointTo = start;
		if(Graph[end -1].firstNode == NULL)
			Graph[end -1].firstNode = node2;
		else{
			p = Graph[end -1].firstNode;
			while(p->nextEdge){
				p = p->nextEdge;
			}
			p -> nextEdge = node2;
		}
	}
}

void GraphList::PrintList(){

	printf("-------GraphList is---------\n");
	for(int i = 0; i < n; i++){
		printf("%d :", Graph[i].data);
		EdgeNode *p = Graph[i].firstNode;
		
		while(p){
			printf(" --> %d",p->pointTo);
			p=p->nextEdge;
		}
		printf(" --> N\n");
	}
}
int main(int argc,char **argv){
#ifndef _OJ_
	freopen("data.txt", "r", stdin);
#endif
	GraphList *g = new GraphList();
	g->PrintList();
	printf("%d\n", g->BFS());
}