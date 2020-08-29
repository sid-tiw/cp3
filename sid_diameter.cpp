#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}
	int root = 0;
	vector<bool> visited(n, false);
	return 0;
}