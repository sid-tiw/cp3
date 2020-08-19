// Author: Siddhartha Tiwari
// This is a generic implementation for sparse table. Although segment trees are
// a better alternative to sparse tables but sparse tables excel in finding
// minmum/maximum/gcd/or range queries on immutable arrays. So, if nothing is
// working a sparse table might just be right.

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int operation(int a, int b) { return min(a, b); }

auto create_sparse(vector<int> arr) {	// Takes O(nlog(n)) asymptotic time
    int n = arr.size(), m = log2(n);
    vector<vector<int>> sparse_table(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) sparse_table[i][0] = arr[i];
    for (int i = 1; i <= m; i++) {
        int ind = 1 << i;
        for (int j = 0; j + ind <= n; j++) {
            sparse_table[j][i] = operation(sparse_table[j][i - 1],
                                           sparse_table[j + ind / 2][i - 1]);
        }
    }
    return sparse_table;
}

int answer_range_sum(vector<vector<int>> vec, int l,
                     int r) {  // It takes O(log(r - l + 1)) asymptotic time.
    const int m = vec[0].size();
    string str = bitset<20>(r - l + 1).to_string();  // safe for 10^6 array size
    int ind = l, ans = 0;
    reverse(str.begin(), str.end());
    for (int i = 0; i < 20; i++) {
        if (str[i] == '0') continue;
        int x = 1 << i;
        ans += vec[ind][i];
        ind += x;
    }
    return ans;
}

auto calc_log(int n) {
	vector<int> logar(n + 1);
	logar[1] = 0;
	for (int i = 2; i <= n; i++) logar[i] = logar[i / 2] + 1;
	return logar;
}

int answer_range_else(vector<vector<int>> arr, int l, int r, vector<int> logar) {
	int val = logar[r - l + 1];
	return operation(arr[l][val], arr[r - (1 << val) + 1][val]);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    auto sparse_table = create_sparse(arr);
	auto logar = calc_log(n);
    cout << answer_range_else(sparse_table, 0, 4, logar) << "\n";
    cout << answer_range_else(sparse_table, 2, 3, logar) << "\n";
    cout << answer_range_else(sparse_table, 1, 1, logar) << "\n";
    return 0;
}