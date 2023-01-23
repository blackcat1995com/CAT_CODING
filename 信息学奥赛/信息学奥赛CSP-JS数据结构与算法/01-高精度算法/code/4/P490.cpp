#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

string s1;
vector<int> A;
int b;

vector<int> mul(vector<int>& A, int b) {
	vector<int> C;

	int k = 0;
	for (int i = 0; i < A.size() || k; i++) {
		int t;
		if (i < A.size()) t = A[i] * b + k;
		else t = k;

		k = t / 10;
		C.push_back(t % 10);
	}

	while (!C.back() && C.size() > 1) C.pop_back();

	return C;
}

int main() {

	cin >> s1 >> b;
	for (int i = s1.size() - 1; i >= 0; i--) A.push_back(s1[i] - '0');

	vector<int> C = mul(A, b);

	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

	return 0;
}

