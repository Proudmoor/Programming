#include <iostream>
#include <cstdio>
#include <cstdlib>

const int MAXNUM = 1000003;

template<typename T>
class Stack{
private:
	int _size;
	int _capacity;
	T * _elem;

public:
	Stack(int c = MAXNUM, int s=0, T v =0){
		_elem = new T[_capacity = c];
		for(_size = 0; _size < s;_size++)
			_elem[_size] = v;
	}
	void insert(int rank, const T& e){
		for(int i = _size; i > rank; i--)
			_elem[i] = _elem[i - 1];
		_elem[rank] = e;
		_size++;
	}
	int size() const{
		return _size;
	}

	int remove(int lo, int hi){
		if(lo == hi) return 0;
		while (hi < _size)
			_elem[lo++] = _elem[hi++];
		_size = lo;
		return hi - lo;
	}
	void remove(int rank){
		remove(rank, rank+1);
	}
	bool empty() const{
		return !_size;
	}
	void push(const T& e){
		insert(size(),e);
	}
	void pop(){
		return remove(size() -1);
	}

	T& top(){
		return (*this)[size() -1];
	}
};