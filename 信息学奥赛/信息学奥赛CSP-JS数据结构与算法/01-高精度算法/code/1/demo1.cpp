#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 210;

char s1[N], s2[N];

int main() {

    cin >> s1 >> s2;

    int len = strlen(s1);

    for(int i = 0; i < len; i++){
        int a = s1[i] - '0';
        int b = s2[i] - '0';
        cout << a + b;
    }
	
	return 0;
}
