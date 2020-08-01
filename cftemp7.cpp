#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

ll mod = 1000000007LL;

int dp[1001][2][3001];

ll num_of_ways(int a, int t, int l, vector<pr> arr) {
    if (a != -1 && dp[a][t][l] != -1) return dp[a][t][l];
    ll nums = 0, temp;
    t = !t;
    for (int i = 0; i < arr.size(); i++) {
        if (i == a) continue;
        if (t) temp = arr[a].second;
        if (!t) temp = arr[a].first;
        if (temp == arr[i].first) {
            if (l == arr[i].first)
                nums++;
            else if (!(l < arr[i].first))
                nums += num_of_ways(i, 0, l - arr[i].first, arr);
        } else if (temp == arr[i].second) {
            if (l == arr[i].second)
                nums++;
            else if (!(l < arr[i].second))
                nums += num_of_ways(i, 1, l - arr[i].second, arr);
        }
        nums %= mod;
    }
    dp[a][!t][l] = nums;
    return nums;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 3001; j++) {
            dp[i][0][j] = -1;
            dp[i][1][j] = -1;
        }
	// for (int i = 1; i <= l; i++) {
	// 	ll sum = 0;
	// 	for (int j = 0; j < n; j++) {
	// 		dp[j][0][i] = 
	// 	}
	// }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans %= mod;
        if (l == arr[i].first)
            ans++;
        else if (!(l < arr[i].first))
            ans += num_of_ways(i, 0, l - arr[i].first, arr);
        if (arr[i].first == arr[i].second) continue;
        if (l == arr[i].second)
            ans++;
        else if (!(l < arr[i].second))
            ans += num_of_ways(i, 1, l - arr[i].second, arr);
    }
    cout << ans << "\n";
    return 0;
}