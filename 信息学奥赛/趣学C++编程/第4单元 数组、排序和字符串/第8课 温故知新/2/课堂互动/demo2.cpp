#include <iostream>
using namespace std;

int main() {

	int i = 1, n, ans = 0;
	cin >> n;
	do{
		ans += i;
		i += 2;
	}while(i <= n);

	cout << ans;
	
	return 0;
}



