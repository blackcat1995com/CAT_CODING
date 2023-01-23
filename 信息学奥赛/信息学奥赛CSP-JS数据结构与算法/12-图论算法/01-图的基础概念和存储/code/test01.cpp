#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 110;

int n, m;
int g[N][N];

int main() {

	cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        // ∑¿÷π÷ÿ±ﬂ 1 2 3    1 2 9
        g[a][b] = min(g[a][b], c);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            printf("%10d ", g[i][j]);
        cout << endl;
    }
    
	return 0;
}

/*
4 5
1 3 7
2 4 6
1 2 5
4 3 8
1 4 9
*/
