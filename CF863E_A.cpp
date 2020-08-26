#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    set<ll> all;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        all.insert(arr[i].first);
        all.insert(arr[i].second);
    }
    vector<ll> mp(all.begin(), all.end());
	vector<int> mpp(mp.size(), 0);
	for (int i = 1; i < mp.size(); i++) {
		if (mp[i] == mp[i - 1] + 1)
			mpp[i] = mpp[i - 1] + 1;
		else
			mpp[i] = mpp[i - 1] + 2;
	}
    for (int i = 0; i < n; i++) {
        arr[i].first =
            mpp[lower_bound(mp.begin(), mp.end(), arr[i].first) - mp.begin()];
        arr[i].second =
            mpp[lower_bound(mp.begin(), mp.end(), arr[i].second) - mp.begin()];
    }
    int mx = 2 * mp.size();
    vector<int> marr(mx + 1, 0);
    for (int i = 0; i < n; i++) {
        marr[arr[i].first]++;
        marr[arr[i].second + 1]--;
    }
    for (int i = 1; i < mx; i++) marr[i] += marr[i - 1];
    int mm = log2(mx);
    vector<vector<int>> sparse(mm + 1, vector<int>(mx));
    for (int i = 0; i < mx; i++) sparse[0][i] = marr[i];
    for (int i = 1; i <= mm; i++) {
        int ind = 1 << i;
        for (int j = 0; j + ind <= mx; j++)
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + ind / 2]);
    }
    int ans = -1;
    int loga[mx + 1];
    loga[1] = 0;
    for (int i = 2; i <= mx; i++) loga[i] = loga[i / 2] + 1;
    for (int i = 0; i < n; i++) {
        int diff = loga[(arr[i].second - arr[i].first + 1)];
        int tot = 1 << diff;
        int mn = min(sparse[diff][arr[i].first],
                     sparse[diff][arr[i].second - tot + 1]);
		if (mn >= 2) {
			ans = i + 1;
			break;
		}
    }
	cout << ans << "\n";
}