#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXNUM 1000005

template<typename Comparable>
class Stack
{
private:
    int _size;
    Comparable *_elem;
    int _capacity;
public:
    Stack(int c = 1000005, int s = 0, Comparable v = 0)
    {
        _elem = new Comparable[_capacity = c];
        for(_size = 0; _size < s; _elem[_size++] = v);
    }
    
    void insert(int r, const Comparable  &e)
    {
        for (int i = _size; i > r; i--)
            _elem[i] = _elem[i - 1];
        _elem[r] = e;
        _size++;
    }
    int size() const
    {return _size;}
    
    int remove( int lo, int hi )
    {
        //返回删除元素的数目，区间为[lo, hi)
        if (lo == hi) return 0;
        while (hi < _size)
            _elem[lo++] = _elem[hi++];
        _size = lo;
        return hi - lo;
    }
    
    void  remove(int r)
    {
        remove(r, r+1);
    }
    
    bool isempty() const {return !_size;}
    void push ( Comparable const& e ) { insert ( size(), e ); }
    void pop() { return remove ( size() - 1 ); }
    Comparable top() { return _elem[size() - 1];}
};

typedef int vertexData;
int maxRoad=1;

typedef struct edge
{
    int direction;
    edge *nextEdge;
}edge;

typedef struct vertexNode
{
    vertexData data;
    int indegree;
    int numOfValages;
    edge *firstEdge;
}vertexNode;

typedef struct adjMatrix
{
    vertexNode vertexNodes[MAXNUM];
    int vertexNum, edgeNum;

}adjMatrix;

void createGraph(adjMatrix *g)
{
    int start, end;
    scanf("%d", &g->vertexNum);
    scanf("%d", &g->edgeNum);
    for (int i = 1; i <= g->vertexNum; i++)
    {
        g->vertexNodes[i].data = i;
        g->vertexNodes[i].numOfValages = 1;
        g->vertexNodes[i].indegree = 0;
        g->vertexNodes[i].firstEdge = NULL;
    }
    
    for (int i = 1; i <= g->edgeNum; i++)
    {
        scanf("%d", &start);
        scanf("%d", &end);
        edge *q = new edge;
        q->direction = end;
        q->nextEdge = g->vertexNodes[start].firstEdge; //这条语句将q插入到顶点列表的开始
        g->vertexNodes[start].firstEdge = q;
        g->vertexNodes[end].indegree++;
    }
}

void topSort(adjMatrix *g)
{
    Stack<int> S;
    edge *p = NULL;
    
    for (int  i = 1; i <= g->vertexNum; i++)
    {
        if (g->vertexNodes[i].indegree == 0)
            S.push(g->vertexNodes[i].data);
    }

    while (!S.isempty())
    {
        int count = S.top();
        S.pop();
        p = g->vertexNodes[count].firstEdge;
        
        while (p != NULL)
        {
            if (--g->vertexNodes[p->direction].indegree == 0)
                S.push(p->direction);
            
            if (g->vertexNodes[count].numOfValages >= g->vertexNodes[p->direction].numOfValages)
                g->vertexNodes[p->direction].numOfValages = g->vertexNodes[count].numOfValages+1;
           
            if (maxRoad <= g->vertexNodes[p->direction].numOfValages)
                maxRoad = g->vertexNodes[p->direction].numOfValages;
            
            p = p->nextEdge;
        }
    }
}


int main(int argc, const char * argv[])
{
    #ifndef _OJ_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w",stdout);
#endif
    adjMatrix *g = new adjMatrix;
    createGraph(g);
    topSort(g);
    
    printf("%d", maxRoad);
}