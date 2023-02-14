#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

int n;
vector<PII> q;

int main() {

    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        q.push_back({x, y});
    }

    sort(q.begin(), q.end(), [&](const PII& a, const PII& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    for(auto x : q)
        cout << x.first << " " << x.second << endl;
	
	return 0;
}

