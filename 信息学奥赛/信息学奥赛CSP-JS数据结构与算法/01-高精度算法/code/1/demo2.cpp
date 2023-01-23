#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 210;

char s1[N], s2[N];
int a[N], b[N], c[N];

int main() {

    cin >> s1 >> s2;

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = max(len1, len2);

    for(int i = 0; i < len1; i++) a[i] = s1[len1 - 1 - i] - '0';
    for(int i = 0; i < len2; i++) b[i] = s2[len2 - 1 - i] - '0';

    for(int i = 0; i < len; i++) c[i] = a[i] + b[i];

    for(int i = len - 1; i >= 0; i--) cout << c[i];
	
	return 0;
}
