
#include "stack.h"
#include "Graph/graphmatrix.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>
 
template <typename Tv, typename Te>
Stack<Tv>* Graph<Tv, Te>::tSort(int s){
	reset();  int v = s; int clock = 0;
	Stack<Tv>* S = new Stack<Tv>;
	do{
		if(status(v) == UNDISCOVERED){
			if(!TSort(v,clock, S)){
				while(! S -> empty())
					S->pop(); 
					break;
			}
		}
	}while(s !=(v = (++v%n)));
	return S;
}

template <typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v,int& clock ,Stack<Tv> *S){
	dTime(v) = ++clock;
	status( v ) = DISCOVERED;
	for (int u = firstNbr(v); u > -1;u = nextNbr(v,u)){
		switch (status(u)){
			case UNDISCOVERED:
				parent(u) = v; type(v, u) = TREE;
				if(!TSort(u, clock, S))
					return false;
				break;
			case DISCOVERED:
				type(v,u) = BACKWARD;
				return false;
			default:
				type(v, u) = (dTime(v) < dTime(u))? FORWARD : CROSS;
				break;
		}
	}

	status(v) = VISITED; S->push(vertex(v));
	return true;
}

void importGraph(GraphMatrix<char,int> & g){
	int n = 0;
	scanf("%d\n",&n);
	for (int i = 0; i < n; i++){
		char vertex; 
		scanf("%c ", &vertex);
		g.insert(vertex);
	}
	
	for(int i =0; i < n; i++){
		for(int j = 0; j< n; j++){
			int edge; 
			scanf("%d", &edge);
			if(edge <= 0) continue;
			g.insert(edge, edge, i, j);
			
		}
		scanf("\n");
	}

	 printf("import finish\n");
}

int main(int argc, char** argv){
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w",stdout);
#endif
	GraphMatrix<char, int> g;

	importGraph(g);

	printf("Number of Vertice: %d\n", g.n);
	for(int i = 0; i < g.n; i++){
		printf("%c ", g.vertex(i));
		if(i == g.n-1) printf("\n");
	}

	for(int i =0; i < g.n; i++){
		for(int j = 0; j< g.n; j++){
			//printf("%d ", g.edge(i,j));
			if(g.exists(i,j)){
				printf("There is an edge from %c to %c\n", g.vertex(i),g.vertex(j));
			} else {
				printf("dont have an edge\n");
			}
		}
		printf("\n");
	}

	if(g.exists(0,4))
		printf("A C has an edge\n");
	else 
		printf("A C dont have an edge\n");
	Stack<char>* ts0 = g.tSort(0);
	Stack<char>* ts1 = g.tSort(1);
	Stack<char>* ts2 = g.tSort(2);
	Stack<char>* ts3 = g.tSort(3);



	if(ts0->empty()){
		printf("ts is empty\n");
		
	}
	printf("\n");
	while(!ts0->empty()){
		printf("%c",ts0->pop());
		
	}
	printf("\n");
	while(!ts1->empty()){
		printf("%c",ts1->pop());
	}
	printf("\n");
	while(!ts2->empty()){
		printf("%c",ts2->pop());
	}
	printf("\n");
	while(!ts3->empty()){
		printf("%c",ts3->pop());
	}

	EType soo = 1;
	printf("%s", soo);

	return 0;
}