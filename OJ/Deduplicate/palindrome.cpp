#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isPal(string input){
	int  length = input.size();
	if(length == 0 || length == 1)
		return true;
	if(input[0] != input[length -1])
		return false;
	return isPal(input.substr(1,length -2));
}
int PalNum(string str){
	int len = str.length();
	vector<vector<int> > dp(len, vector<int>(len));

	cout <<dp[0][4]<<endl;
	for(int j = 0; j < len; j++){
		dp[j][j] = 1;
		for(int i = j-1; i>=0; i--){
			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			if(str[i] == str[j])
				dp[i][j] += 1 + dp[i+1][j-1];
		}
	}
	return dp[0][len-1];
}
int main(){
	string s1 = "level";
	string s2 = "abaaa";
	cout << s1.substr(1,3)<<endl;
	if(isPal(s1))
		cout << "s1 is palindrome"<<endl;
	else
		cout << "s1 is not"<<endl;
	if(isPal(s2))
		cout << "s2 is palindrome" <<endl;
	else 
		cout << "s2 is not"<<endl;
	string s3 = "abaa";
	cout <<"Number of pal in s3 is: "<<PalNum(s3)<<endl;
	return 0;
}