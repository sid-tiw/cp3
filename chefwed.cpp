#include <bits/stdc++.h>

using namespace std;

int find_min_el(vector<int> arr, int k, int cs, vector<int> &dp) {
    if (k >= arr.size()) return 0;
    if (dp[k] != -1) return dp[k];
    int cost = INT_MAX, aux = 0;
    map<int, int> som;
    for (int i = k; i < arr.size(); i++) {
        som[arr[i]]++;
        if (som[arr[i]] == 2)
            aux += 2;
        else if (som[arr[i]] > 2)
            aux++;
        int temp = cs + find_min_el(arr, i + 1, cs, dp) + aux;
        if (temp < cost) cost = temp;
    }
    dp[k] = cost;
    return cost;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		vector<int> dp(n, -1);
		cout << find_min_el(arr, 0, k, dp) << "\n";
	}
}