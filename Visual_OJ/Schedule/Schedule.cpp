#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std;
const int MAX = 100000;

char *cycleShift_space(char *string, int n){
    char *temp = new char[n + 1];
    strncpy(temp, string, n);
    size_t len = strlen(string);
    strncpy(string, string + n, len - n-1);
    strncpy(string+n, temp, strlen(temp));
    string[len] = '\0';//注意手动加上终止符号才能保证string是有限的。
    return string;//注意此时手动加上终止符，会使得后面string形式改边。
}

string cycle(string str, int n){
    return str.substr(n, string::npos)+str.substr(0,n);
}
void reserve(char *string, int lo, int hi){
    //交换两个字符的方式
    while (lo<hi){
        swap(string[lo++], string[hi--]);
    }
}
char *cycleShift_three(char *string, int n){
    size_t len = strlen(string);
    int hi = n - 1;
    reserve(string, 0,hi);
    reserve(string, n, len-1);
    reserve(string, 0, len-1 );
    return string;
}

void printShape(int size){
    if (size %2 == 0) size = size - 1;
    string star(size, '*');
    string blank(size / 2, ' ');
    for (int i = 0; i <size; i++){
        int h;
        if (i <size / 2)
            h = i;
        else
            h = size - i-1;

        cout << blank.substr(0, size/2 -h) << star.substr(0, 2 * h + 1) << endl;
    }
    for (int i = -size/2; i <= size/2; i++){
        for (int j = -size / 2; j <= size / 2;j++){
            if (abs(i) + abs(j) == size/2)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
}

bool match(char* P, char *T){
    size_t n = strlen(T), i = 0;
    size_t m = strlen(P), j = 0;
    while (j < m&&i < n){
        if (T[i] == P[j]){
            i++; j++;
        }
        else {
            i = i - (j - 1); j = 0;
        }
    }
    bool matched = ((i-j)>(n-m));
    return !matched;
}
int main(){
    ifstream infile("input.txt");
    streambuf *oldBuffer = cin.rdbuf(infile.rdbuf());
    char  string1[MAX]; char  string2[MAX];
    while (cin >> string1 >> string2){
        cout << string1 << " " << string2 << endl;
        char string3[2 * MAX];
        size_t len = strlen(string1);
        strncpy(string3, string1, len);
        strncpy(string3 + strlen(string1), string1, len);
        string3[2 * len] = '\0';
        cout << "string 3 is " << string3 << endl;
        bool isSub = match(string2, string3);
        if (isSub)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } 
    
    cout << "star shape" << endl;
    printShape(11);
    cin.rdbuf(oldBuffer);
    return 0;

}