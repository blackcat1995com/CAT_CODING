#include <iostream>
using namespace std;

int main() {

	long long n;
	cin >> n;
	int sum = 0, a;
	do{
		a = n % 2;
		sum += a;
		cout << a;
		n /= 2;
	}while(n != 0);

	cout << endl << sum << endl;
	
	return 0;
}

