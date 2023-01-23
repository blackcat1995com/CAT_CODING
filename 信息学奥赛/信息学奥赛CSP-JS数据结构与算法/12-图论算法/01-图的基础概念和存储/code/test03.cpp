#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 110;
typedef pair<int, int> PII; // first:v  second:w

int n, m;
vector<PII> h[N];

int main() {
    
    cin >> n >> m;
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        h[a].push_back({b, c});
    }

    for(int i = 1; i <= n; i++){
        printf("¶¥µã%d£º", i);
        for(auto x: h[i])
            printf("%d %d  |  ", x.first, x.second);
        printf("\n");
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

