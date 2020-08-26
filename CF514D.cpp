#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n, m, k, p;
    cin >> n >> m >> k;
    p = log2(n);
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    vector<vector<vector<ll>>> sparse(
        m,
        vector<vector<ll>>(
            p + 1,
            vector<ll>(n, 0)));  // can use segment trees but it will yield a
                                 // O(m * n * log(n)^2) as compared to O(m * n
                                 // * log(n)) by using sparse table.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) sparse[i][0][j] = arr[j][i];
        for (int j = 1; j <= p; j++) {
            int ind = 1 << j;
            for (int k = 0; k + ind <= n; k++)
                sparse[i][j][k] =
                    max(sparse[i][j - 1][k], sparse[i][j - 1][k + ind / 2]);
        }
    }
    vector<int> lgc(n + 1);
    lgc[1] = 0;
    for (int i = 2; i <= n; i++) lgc[i] = lgc[i / 2] + 1;
    int l = 1, r = 0;
    for (int i = 0; i < n; i++) {
        int start = i, end = n - 1, val = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int lc = lgc[mid - i + 1];
            int tot = 1 << lc, ind = mid - tot + 1;
            int sum = 0;
            for (int j = 0; j < m; j++)
                sum += max(sparse[j][lc][i], sparse[j][lc][ind]);
            if (sum <= k) {
                val = mid;
                start = mid + 1;
                // cout << i << " " << val << " " << sum << "\n";
            } else
                end = mid - 1;
        }
        if (val == -1) continue;
        if ((val - i) > (r - l)) l = i, r = val;
    }
	// cout << l << " " << r << "\n";
    if (l > r) {
		for (int i = 0; i < m; i++) cout << "0 ";
		return 0;
	}
    int xx = lgc[r - l + 1], tt = 1 << xx;
    for (int i = 0; i < m; i++)
        cout << max(sparse[i][xx][l], sparse[i][xx][r - tt + 1]) << " ";
    return 0;
}