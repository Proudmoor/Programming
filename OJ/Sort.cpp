#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int num ,k;
	cin >> num >> k;
	int temp;
	vector<int> array;
	while(cin >> temp){
		array.push_back(temp);
	}

	sort(array.begin(), array.end());

	cout << array[k-1]<<endl;
	return 0;
}