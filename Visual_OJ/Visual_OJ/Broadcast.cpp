//解决TSP问题
/*Shrek是一个大山里的邮递员，每天负责给所在地区的n个村庄派发信件。但杯具的是，由于道路狭窄，年久失修，村庄间
的道路都只能单向通过，甚至有些村庄无法从任意一个村庄到达。这样我们只能希望尽可能多的村庄可以收到投递的信件。
Shrek希望知道如何选定一个村庄A作为起点（我们将他空投到该村庄），依次经过尽可能多的村庄，路途中的每个村庄都经
过仅一次，最终到达终点村庄B，完成整个送信过程。这个任务交给你来完成。
输入
第一行包括两个整数n，m，分别表示村庄的个数以及可以通行的道路的数目。
以下共m行，每行用两个整数v1和v2表示一条道路，两个整数分别为道路连接的村庄号，道路的方向为从v1至v2，n个村庄编号为[1, n]。
输出
输出一个数字，表示符合条件的最长道路经过的村庄数。*/
#include <cstdio>
#include <iostream>
#include <cstdlib>

const int MAXNUM = 1000002;
//栈数据结构 参照课堂所给vector 代码
template<typename T>
class Stack{
private:
  int mSize;
  T* mElem;
  int mCapacity;

public:
  Stack(int c = MAXNUM, int s = 0, T v = 0){
    mElem = new T[mCapacity = c];
    for ( mSize = 0; mSize < s; mElem[mSize++] = v);
  }

  void insert(int r, const T& e){
    for (int i = mSize; i > r; i--){
      mElem[i] = mElem[i - 1];
    }
    mElem[r] = e;
    mSize++;
  }

  int size() const{
    return mSize;
  }
  
  int remove(int lo, int hi){
    if (lo == hi) return 0;
    while (hi < mSize){
      mElem[lo++] = mElem[hi++];
    }

    mSize = lo;
    return hi - lo;
  }

  T remove(int r){
    T e = mElem[r];
     remove(r, r + 1);
     return e;
  }

  void push(const T& e){
    insert(size(), e);
  }
  T pop(){
    return remove(size() - 1);
  }
  T& top(){
    return mElem[size()-1];
  }

  bool empty()const {
    return !mSize;
  }
};
typedef int  Vdata;
struct EdgeNode{
  int pointTo;
  EdgeNode *nextEdge;
};
struct VertexNode{
  Vdata data;
  int inDegree;
  int village;
  EdgeNode *firstEdge;
};

class GraphList{
public:
  GraphList(); //构造函数将“input.txt"文件输入构成图；
  ~GraphList();
  void TopologicalSort();
  void Print();
private:
  int n, e; //the number of vertice and edges;
  VertexNode vertexNodes[MAXNUM];
};

GraphList::GraphList(){
#ifndef _OJ_
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  scanf("%d %d\n", &n, &e);
  for (int i = 1; i <= n; i++){
    vertexNodes[i].data = i; // here data is a number represent the vertex 1, 2, 3,.....
    vertexNodes[i].inDegree = 0;
    vertexNodes[i].firstEdge = NULL;
    vertexNodes[i].village = 1; //考虑边界情况 最小的村庄应该为1；
  }
  int start =0, end = 0;
  //依次插入边 组成邻接表

  for (int i = 1; i <= e; i++){
    scanf("%d", &start);
    scanf("%d\n", &end);

    EdgeNode *e = new EdgeNode();
    EdgeNode * node = NULL;
    e->pointTo = end;

    if (vertexNodes[start].firstEdge == NULL)
      vertexNodes[start].firstEdge = e;
    else {
      node = vertexNodes[start].firstEdge;
      while (node->nextEdge)
        node = node->nextEdge;
      node->nextEdge = e;
    }

    vertexNodes[end].inDegree++;
  }
  
}


void GraphList::TopologicalSort(){
  int maxVillage = 1;
  Stack<int> S;
  for (int i = 1; i <= n; i++){
    if (vertexNodes[i].inDegree == 0)
      S.push(vertexNodes[i].data);
  }

  EdgeNode *p = NULL;
  if (S.empty()) printf("S is empty.\n");
  while (!S.empty()){
   int dele = S.top();
   S.pop();
   p = vertexNodes[dele].firstEdge;
    while (p != NULL){
      if (--vertexNodes[p->pointTo].inDegree == 0)
        S.push(vertexNodes[p->pointTo].data);
   

      if (vertexNodes[dele].village >= vertexNodes[p->pointTo].village)
        vertexNodes[p->pointTo].village = vertexNodes[dele].village + 1;
      if (vertexNodes[p->pointTo].village > maxVillage)
        maxVillage = vertexNodes[p->pointTo].village;
      p = p->nextEdge;
    }
  }
  printf("%d\n", maxVillage);
}

void GraphList::Print(){
  std::cout << "List Graph" << std::endl;
  EdgeNode *e;
  for (int i = 1; i <= n; i++){
    std::cout << vertexNodes[i].data << ":";
    e = vertexNodes[i].firstEdge;
    if (e == NULL) printf(" --->NULL ");
    while (e != NULL){
      std::cout << " ---> " << vertexNodes[e->pointTo].data;
      e = e->nextEdge;
    }
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
  }

  for (int i = 1; i <= n; i++){
    std::cout << vertexNodes[i].data << "'s inDegree is: " << vertexNodes[i].inDegree << std::endl;
  } 
}
int main(int argc, char** argv){
  GraphList *g = new GraphList();
 g->Print();

  g->TopologicalSort();
  
  return 0;

}