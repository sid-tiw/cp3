#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr, ans, tmp;
        for (ll i = 0; i < 2 * k + 100; i++) {
            ans.push_back(0);
            tmp.push_back(0);
        }
        for (ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            arr.push_back(temp);
        }
        for (ll i = 0; i < (n / 2); i++) {
            ll val1 = min(arr[i], arr[n - i - 1]) + 1;
            ll val2 = max(arr[i], arr[n - i - 1]) + k;
            tmp[arr[i] + arr[n - i - 1]]++;
            ans[2] += 2;
            ans[2 * k + 1] -= 2;
            ans[val1]--;
            ans[val2 + 1]++;
        }
        for (ll i = 3; i <= 2 * k; i++) ans[i] += ans[i - 1];
        for (ll i = 2; i <= 2 * k; i++) ans[i] -= tmp[i];
        ll min_t = ans[2];
        for (int i = 3; i <= 2 * k; i++) min_t = min(min_t, ans[i]);
        cout << min_t;
        cout << "\n";
    }
    return 0;
}