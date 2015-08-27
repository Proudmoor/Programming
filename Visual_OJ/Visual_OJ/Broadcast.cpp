//���TSP����
/*Shrek��һ����ɽ����ʵ�Ա��ÿ�츺������ڵ�����n����ׯ�ɷ��ż��������ߵ��ǣ����ڵ�·��խ�����ʧ�ޣ���ׯ��
�ĵ�·��ֻ�ܵ���ͨ����������Щ��ׯ�޷�������һ����ׯ�����������ֻ��ϣ�������ܶ�Ĵ�ׯ�����յ�Ͷ�ݵ��ż���
Shrekϣ��֪�����ѡ��һ����ׯA��Ϊ��㣨���ǽ�����Ͷ���ô�ׯ�������ξ��������ܶ�Ĵ�ׯ��·;�е�ÿ����ׯ����
����һ�Σ����յ����յ��ׯB������������Ź��̡�������񽻸�������ɡ�
����
��һ�а�����������n��m���ֱ��ʾ��ׯ�ĸ����Լ�����ͨ�еĵ�·����Ŀ��
���¹�m�У�ÿ������������v1��v2��ʾһ����·�����������ֱ�Ϊ��·���ӵĴ�ׯ�ţ���·�ķ���Ϊ��v1��v2��n����ׯ���Ϊ[1, n]��
���
���һ�����֣���ʾ�������������·�����Ĵ�ׯ����*/
#include <cstdio>
#include <iostream>
#include <cstdlib>

const int MAXNUM = 1000002;
//ջ���ݽṹ ���տ�������vector ����
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
  GraphList(); //���캯������input.txt"�ļ����빹��ͼ��
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
    vertexNodes[i].village = 1; //���Ǳ߽���� ��С�Ĵ�ׯӦ��Ϊ1��
  }
  int start =0, end = 0;
  //���β���� ����ڽӱ�

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