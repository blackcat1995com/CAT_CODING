#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 110, M = 1010;

int n, m;
int h[N], to[M], w[M], ne[M], idx = 0;

void add(int a, int b, int c){
    to[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int main() {

    cin >> n >> m;
    
    memset(h, -1, sizeof h);
    
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        add(a, b, c);
    }
    
    for(int i = 1; i <= n; i++){
        printf("¶¥µã%d£º", i);
        for(int j = h[i]; ~j; j = ne[j])
            printf("%d %d  |  ", to[j], w[j]);
        printf("\n");
    }
    
	return 0;
}
