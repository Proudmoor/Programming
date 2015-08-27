
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
 


struct Vertex{
	int  name;
	int status;
	int parent;
	Vertex(int  i = 0): status(0),parent(-1){
			name = i;
		}
};

class GraphMatrix {
private:
	int n; int e;
	Vector<Vertex> V;
	Vector<Vector<int>  > E; 
public:
	GraphMatrix(){
		n = e = 0;
	}
	~GraphMatrix(){
		
	}
	//顶点的操作
	int & vertex(int i){
		return V[i].name;
	}

	int& status(int i){ return V[i].status;}

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
			E[j].insert(0);
		}
		n++;
		E.insert(Vector<int> (n, n, 0));
		return V.insert( Vertex(vertex));
	}
	
	bool exists (int i, int j){
		if ((i >=0) && (i < n) && (j>=0) && (j < n) &&(E[i][j] != 0))
			return true;
		else 
			return false;
	}
	
	int& edge(int i, int j){
		return E[i][j];
	}
	void insert (int w, int i, int j){
		if(exists(i, j)) 
			return ;
		E[i][j] = w;
		e++;
	}


	void DFS(int v, Stack<int>*);
	Stack<int>* dfs(int s);

	void reset() { 
      for ( int i = 0; i < n; i++ ) { 
         status ( i ) = 0;
         parent ( i ) = -1; 
      }
   }
};