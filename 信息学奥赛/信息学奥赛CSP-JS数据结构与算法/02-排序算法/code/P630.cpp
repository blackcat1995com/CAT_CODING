/*
n-1轮
1:n-1
2:n-2
...
n-1:1

1 + 2 + 3 + ... + (n-1)
n(n-1)/2
时间复杂度 O(n^2) 稳定的排序
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e4 + 10;

int n;
int a[N];

int res = 0;

int main() {
  
  	cin >> n;
  	for(int i = 1; i <= n; i++) cin >> a[i];
  
  	for(int i = 1; i < n; i++){
      
      	bool flag = false;
    	for(int j = 1; j <= n - i; j++){
        	if(a[j] > a[j + 1]){
            	swap(a[j], a[j + 1]);
              	res++;
       			flag = true;
            }
        }
      
      	if(!flag) break;
    }
  
  	cout << res << endl;
	
	return 0;
}

