#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

string s1, s2;
vector<int> A, B, C;

vector<int> mul(vector<int>& A, vector<int>& B) {
	vector<int> C(A.size() + B.size() + 10);

	for (int i = 0; i < B.size(); i++)
		for (int j = 0; j < A.size(); j++)
			C[i + j] += B[i] * A[j];

	int t = 0;
	for (int i = 0; i < C.size(); i++) {
		t += C[i];
		C[i] = t % 10;
		t /= 10;
	}

	while (!C.back() && C.size() > 1) C.pop_back();

	return C;
}

int main() {

	cin >> s1 >> s2;

	for (int i = s1.size() - 1; i >= 0; i--) A.push_back(s1[i] - '0');
	for (int i = s2.size() - 1; i >= 0; i--) B.push_back(s2[i] - '0');

	C = mul(A, B);

	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

	return 0;
}

