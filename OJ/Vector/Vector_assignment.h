template <typename T> Vector<T>& Vector<T>::operator= (Vector<T> const& V){
	if(_elem) delete[] _elem;
	copyFrom(V._elem, 0, V.size());
	return *this;
}

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi){
	_elem = new T[_capacity = 2 *(hi - lo)];
	_size = 0;
	while(lo < hi)
		_elem[_size++] = A[lo++];
}