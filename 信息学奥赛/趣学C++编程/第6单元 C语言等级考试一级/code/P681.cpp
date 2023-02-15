#include <iostream>
#include <cstdio>
using namespace std;

const int N = 5005;

int n, m;
bool book[N];

int main() {

	cin >> n >> m;
    
    for(int i = 2; i <= m; i++){
        for(int j = 1; j <= n; j++)
            if(j % i == 0)
                book[j] = !book[j];
    }
    
    bool is_first = true;
    for(int i = 1; i <= n; i++){
        if(!book[i]){
            // cout << i << " ";
            
            if(is_first){
                cout << i;
                is_first = false;
            }
            else
                cout << "," << i;
            
        }
    }
	return 0;
}


