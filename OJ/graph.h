
#include <iostream>

template <typename T>
class Stack: public Vector<T>{
public:
	void push(T const& e){
		this->insert(this->size(), e);
	}

	T pop(){
		return this->remove(this->size() -1);
	}

	T& top(){
		return (*this)[this->size() - 1];
	}

};

typedef enum { 0, 1, 2} VStatus; 

struct Edge {
	int weight; 
	Edge(int w = 0):weight( w ) {

	}
};

struct Vertex{
	int  name;
	VStatus status;
	int parent;
	Vertex(int  i = 0): status( 0 ),parent(-1){
			name = i;
		}
};

class GraphMatrix {
private:
	int n; int e;
	Vector<Vertex> V;
	Vector<Vector<Edge *>  > E; 
public:
	GraphMatrix(){
		n = e = 0;
	}
	~GraphMatrix(){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(E[i][j])
					delete E[i][j];
			}
	}
	//顶点的操作
	int & vertex(int i){
		return V[i].name;
	}

	VStatus& status(int i){ return V[i].status;}
	int nextNbr(int i, int j){
		while((j>-1) && (!exists(i, --j)));
		return j;
	}
	int& parent(int i){
		return V[i].parent;
	}
	int firstNbr(int i){ return nextNbr(i, n);}
	int insert(int vertex){
		for (int j = 0; j < n; j++){
			E[j].insert(nullptr);
		}
		n++;
		E.insert(Vector<Edge *> (n, n, (Edge*) nullptr));
		return V.insert( Vertex(vertex));
	}
	int  remove(int i){
		for(int j = 0; j < n; j++)
			if (exists(i,j)) {delete E[i][j];}
		E.remove(i); n--;
		int  vBak = vertex(i); V.remove(i);
		for (int j = 0; j < n; j++)
			if (Edge *e = E[j].remove(i)){
				delete e; 
			}
		return vBak;
	}
	
	bool exists (int i, int j){
		if ((i >=0) && (i < n) && (j>=0) && (j < n) &&(E[i][j] != nullptr))
			return true;
		else 
			return false;
	}
	
	int& edge(int i, int j){
		return E[i][j]->weight;
	}
	void insert (int w, int i, int j){
		if(exists(i, j)) 
			return ;
		E[i][j] = new Edge(w);
		e++;
	}

	int remove(int i, int j){
		int eBak = edge(i, j); 
		delete E[i][j]; E[i][j] = nullptr;
		e--;
		return eBak;
	}

	void DFS(int v, Stack<int>*);
	int dfs(int s);

	void reset() { 
      for ( int i = 0; i < n; i++ ) { 
         status ( i ) = 0;
         parent ( i ) = -1; 
      }
   }
};