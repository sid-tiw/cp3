#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

ll combination(ll a, ll b) {
    if (a < b) return 0;
    ll res = 1;
    ll val = max(b, a - b);
    vector<int> count(10, 0), count_t(10, 0);
    for (ll i = a; i > val; i--) {
        ll temp = i;
        for (int j = 0; j < 10; j++) {
            int cnt = 0;
            while (temp % prime[j] == 0) {
                cnt++;
                temp /= prime[j];
            }
            count[j] += cnt;
        }
    }
    for (ll i = 2; i <= (a - val); i++) {
        ll temp = i;
        for (int j = 0; j < 10; j++) {
            int cnt = 0;
            while (temp % prime[j] == 0) {
                cnt++;
                temp /= prime[j];
            }
            count_t[j] += cnt;
        }
    }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < count[i] - count_t[i]; j++) res *= prime[i];
    return res;
}

ll power(ll a, ll b) {
    ll ans = 1;
    for (int i = 0; i < b; i++) ans *= a;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int tt = n - 1;
    ll total = (tt - 2) * 4 * 9 * power(4, n - 4) + 2 * 4 * 3 * power(4, n - 3);
    cout << total << "\n";
    return 0;
}