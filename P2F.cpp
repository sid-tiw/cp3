#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ans_bin(vector<ll> arr, ll mn, ll mx, int k) {
    if (mn > mx) return LLONG_MAX;
    ll mid = (mn + mx) / 2;
    int l = 0, r = 0;
    for (int i = 0; i < arr.size(); i++) {
        if ((!(l % 2) && arr[i] <= mid) || (l % 2)) l++;
        if (((r % 2) && arr[i] <= mid) || !(r % 2)) r++;
    }
    if (l >= k || r >= k) return min(mid, ans_bin(arr, mn, mid - 1, k));
    return ans_bin(arr, mid + 1, mx, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll mn = *(min_element(arr.begin(), arr.end())),
       mx = *(max_element(arr.begin(), arr.end()));
    cout << ans_bin(arr, mn, mx, k) << "\n";
    return 0;
}