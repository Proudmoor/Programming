#include <cstdio>
#include <cstdlib>
#include <iostream>
const int MAX = 10000;
//首先写出队列的数据结构
template <typename T>
class Queen{
private:
  int mSize, mCapacity;
  T * mElem;

public:
  Queen(int s = 0, int c = MAX, T v = 0){
    mElem = new T[mCapacity = c];
    for (mSize = 0; mSize < s; mElem[mSize++] = v);
  }
  void insert(int r, const T& e){
    for (int i = mSize; i > r; i--)
      mElem[i] = mElem[i - 1];
    mElem[r] = e;
    mSize++;
  }
  int remove(int lo, int hi){
    while (hi < mSize)
      mElem[lo++] = mElem[hi++];
    mSize = lo;
    return hi - lo;
  }
  int remove(int r){
    return remove(r, r + 1);
  }

  int size(){
    return mSize;
  }
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
  T front(){
    return mElem[0];
  }
  T back(){
    return mElem[mSize - 1];
  }
};

typedef int Vdata;
struct EdgeNode{
  int pointTo;
  EdgeNode *nextEdge;
};
struct VertexNode{
  Vdata data;

  int radio;
  EdgeNode *firstEdge;
};

class GraphList{
private:
  VertexNode GraphNode[MAX];
  int n, e;

public:
  GraphList();
  ~GraphList();
 void  PrintList();

 void BFS();

};

GraphList::GraphList(){

#ifndef _OJ_
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  scanf("%d %d\n", &n, &e);

  for (int i = 0; i < n; i++){
    GraphNode[i].data = i + 1;
    GraphNode[i].radio = 0;
    GraphNode[i].firstEdge = NULL;
  }

  for (int i = 0; i < e; i++){
    int start = 0, end= 0;
    scanf("%d %d\n", &start, &end);
    EdgeNode * e = new EdgeNode();
    EdgeNode* p;
    e->pointTo = end;
    if (GraphNode[start-1].firstEdge == NULL)
      GraphNode[start-1].firstEdge = e;
    else{
      p = GraphNode[start-1].firstEdge;
      while (p->nextEdge)
       p = p->nextEdge;
      p->nextEdge = e;
    }
  }
}

void GraphList::PrintList(){
  std::cout << "      Graph List is:      " << std::endl;
  std::cout << "--------------------------" << std::endl;
  EdgeNode* p;
  for (int i = 0; i < n; i++){
    std::cout << GraphNode[i].data << ": ";
    p = GraphNode[i].firstEdge;
    if (p == NULL) std::cout << " --> " << "NULL";
    while (p !=NULL){
      std::cout << " --> " << GraphNode[p->pointTo-1].data;
      p = p->nextEdge;
    }
    printf("\n");
    std::cout << "-------------------------" << std::endl;
  }
}


int main(int argc, char** argv){
  GraphList *g = new GraphList();
  g->PrintList();

  getchar();
  Queen<int> q;
  if (q.empty()){
    printf("queen is empty.\n");
  }
  
  q.enqueen(10); 
  q.enqueen(14); 
  q.enqueen(16);
  printf("queen's front is %d.\n", q.front());
  printf("queen's back is %d.\n", q.back());
  q.dequeen();
  printf("queen's front after dequeen is %d.\n", q.front());
  return 0;
}