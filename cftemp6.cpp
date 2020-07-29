#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

long max_price(int x, int m, int n, vii arr, vii &dp) {
    if (n == 0) return 0;
    if (x == m) return arr[3][x] * min(arr[0][x] / arr[1][x], n / arr[2][x]);
    if (dp[n][x] != -1) return dp[n][x];
    long max_cost = -1;
    int mx_ind = n / arr[2][x];
    if (arr[1][x] != 0) mx_ind = min(arr[0][x] / arr[1][x], mx_ind);
    for (int i = 0; i <= mx_ind; i++)
        max_cost =
            max(max_cost, i * arr[3][x] +
                              max_price(x + 1, m, n - i * arr[2][x], arr, dp));
    dp[n][x] = max_cost;
    return max_cost;
}

int main() {
	ios_base::sync_with_stdio(false);
    int i_info[4];
    cin >> i_info[0] >> i_info[1] >> i_info[2] >> i_info[3];
    vii info(4, vi(i_info[1] + 1));
    info[0][0] = 0;
    info[1][0] = 0;
    info[2][0] = i_info[2];
    info[3][0] = i_info[3];
    for (int i = 1; i <= i_info[1]; i++)
        for (int j = 0; j < 4; j++) cin >> info[j][i];
    vii dp(i_info[0] + 1, vi(i_info[1], -1));
    cout << max_price(0, i_info[1], i_info[0], info, dp) << "\n";
    return 0;
}