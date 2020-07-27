#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> min_dp(int m, int n, vector<int> arr, int k) {
    int mid = (m + n) / 2;
    vector<int> orgi(n - m + 1, 0), tcost(n - m + 1, 0);
    if (mid + 1 <= n) {
        vector<int> cost1 = min_dp(mid + 1, n, arr, k);
        for (int i = mid + 1; i <= n; i++) {
            if (arr[i] < arr[mid] || cost1[i - mid - 1] == 1)
                orgi[i - m] = 1;
            if (cost1[i - mid - 1] == 1) 
                tcost[i - m] = 1;
        }
        for (int i = 0; i < k; i++) orgi[i] += cost1[i];
    }
    if (mid - 1 >= m) {
        vector<int> cost2 = min_dp(m, mid - 1, arr, k);
        for (int i = 0; i < mid; i++) {
            if (arr[i] > arr[mid]) {
                orgi[arr[i] - 1]++;
                if (cost2[arr[i] - 1] > 0) {
                    cost2[arr[i] - 1]--;
                    tcost[arr[i] - 1]++;
                }
            }
        }
        for (int i = 0; i < k; i++) orgi[i] += cost2[i];
    }
    tcost[arr[mid] - 1]++;
    int sum1 = 0, sum2 = 0;
    for (auto it : tcost) sum1 += it;
    for (auto it : orgi) sum2 += it;
    if (sum1 < sum2)
        return tcost;
    else
        return orgi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        long double dd;
        int tt;
        cin >> tt >> dd;
        arr.push_back(tt);
    }
    vector<int> temp = min_dp(0, n - 1, arr, m);
    int ans = 0;
    for (auto it : temp) ans += it;
    cout << ans << "\n";
    return 0;
}