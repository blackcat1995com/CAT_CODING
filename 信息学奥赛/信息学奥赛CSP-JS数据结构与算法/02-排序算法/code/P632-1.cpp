#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a[110];

int main() {
  
  	cin >> n;
  
  	for(int i = 1; i <= n; i++) cin >> a[i];
  
  	/*
  	for(int i = 1; i < n; i++){
    	int k = i;
      	for(int j = i + 1; j <= n; j++)
          	if(a[j] < a[k])
              	k = j;
      	if(k != i) swap(a[i], a[k]);
    }
    */
  	
  	for(int i = 2; i <= n; i++){
    	int t = a[i];
      	int k = 1;
      	while(a[k] <= t && k < i) k++;
      	for(int j = i - 1; j >= k; j--) a[j + 1] = a[j];
      	a[k] = t;
    }
  
  	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	
	return 0;
}

/*
²åÈëÅÅÐò
5 4 3 2 1
5 
4 5    :1
3 4 5  :2
...
...    :n-1
2 3 4 5
1 2 3 4 5

1 3 5 8 9   :7
*/

