#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, k, sum = 0;
	cin >> n >> k;
	priority_queue<int> mxheap;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		mxheap.push(temp);
	}
	while(k--) {
		int val = mxheap.top();
		mxheap.pop();
		val = floor(val / 2);
		mxheap.push(val);
	}
	for (int i = 0; i < n; i++) {
		int val = mxheap.top();
		mxheap.pop();
		sum += val;
	}
	cout << sum << "\n";
	return 0;
}