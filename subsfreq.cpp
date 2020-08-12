#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

ll mod = 1000000007;

ll bin_exp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return (res % mod);
}

void process(vector<ll> count) {
    ll n = count.size() - 1;
    vector<vector<ll>> dp(n + 1);
    for (ll i = 1; i <= n; i++) dp[i].push_back(1);
    vector<ll> combs;
    ll rem = 1;
    for (ll i = 1; i <= n; i++) {
        ll prev = 1, sum = 1;
        for (ll j = 1; j <= count[i]; j++) {
            prev = ((prev * ((count[i] - j + 1) * bin_exp(j, mod - 2)) % mod) %
                    mod);
            sum = (sum + prev) % mod;
            dp[i].push_back(sum);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < dp[i].size(); j++) cout << dp[i][j] << " ";
        cout << "\n";
    }
    set<ll> indices;
    for (int i = 1; i <= n; i++) indices.insert(i);
    for (int i = 0; i <= n; i++) {
        ll curr = rem;
        vector<ll> tlist;
        for (auto it : indices) {
            curr = (curr * dp[it][i]) % mod;
            if (dp[it].size() == (i + 1)) {
                rem = (rem * dp[it][i]) % mod;
                tlist.push_back(it);
            }
        }
        for (auto it : tlist) indices.erase(it);
        combs.push_back(curr);
    }
    vector<ll> total_now(n + 1, 0);
    vector<ll> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) continue;
        ll curr = 0;
        for (int j = 1; j <= count[i]; j++) {
            ll val =
                ((combs[j] - total_now[j]) * bin_exp(dp[i][j], mod - 2)) % mod;
            ll anot = (val * (dp[i][j] - dp[i][j - 1])) % mod;
            total_now[j] = (total_now[j] + anot) % mod;
            curr = (curr + anot) % mod;
        }
        ans[i] = curr;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ans[i] %= mod;
        if (ans[i] < 0) ans[i] += mod;
        sum += ans[i];
        cout << ans[i] << " ";
    }
    if ((bin_exp(2, n) - 1) % mod == sum) cout << "true\n";
    cout << "\n";
}

ll mult(ll a, ll b) {
    ll ans = ((a % mod) * (b % mod)) % mod;
    return ans < 0 ? ans + mod : ans;
}

ll add(ll a, ll b) {
    ll ans = ((a % mod) + (b % mod)) % mod;
    return ans < 0 ? ans + mod : ans;
}

void anoth(vector<ll> count) {
    ll n = count.size() - 1, accum = 1;
    vector<vector<ll>> sum(n + 1);
    for (ll i = 1; i <= n; i++) {
        ll prev = 1, smt = 1;
        sum[i].push_back(1);
        for (ll j = 1; j <= count[i]; j++) {
            prev = mult(mult(prev, bin_exp(j, mod - 2)), count[i] - j + 1);
            smt = add(smt, prev);
            sum[i].push_back(smt);
        }
    }
    vector<ll> combin(n + 1, 1);
    set<ll> indices;
    for (int i = 1; i <= n; i++) indices.insert(i);
    for (int i = 0; i <= n; i++) {
        ll val_curr = accum;
        vector<ll> t_ind;
        t_ind.clear();
        for (auto it = indices.begin(); it != indices.end(); it++) {
            ll temp = *it;
            val_curr = mult(val_curr, sum[temp][i]);
            if (count[temp] == i) {
                t_ind.push_back(temp);
                accum = mult(accum, bin_exp(2, count[temp]));
            }
        }
        for (auto it : t_ind) indices.erase(indices.find(it));
        combin[i] = val_curr;
    }
    // for (int i = 0; i <= n; i++) cout << combin[i] << " ";
    // cout << "\n";

    vector<ll> tempt(n + 1, 0);
    vector<ll> ans;
    for (int i = 1; i <= n; i++) {
        ll tot_w = 0;
        for (int j = 1; j <= count[i]; j++) {
            ll valu = add(combin[j], mod - tempt[j]);
            ll ways = mult(mult(valu, bin_exp(sum[i][j], mod - 2)),
                           sum[i][j] - sum[i][j - 1] + mod);
            tempt[j] = add(tempt[j], ways);
            tot_w = add(tot_w, ways);
        }
        ans.push_back(tot_w);
    }
    for (auto it : ans) cout << it << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        if (n == 1) {
            for (int i = 1; i <= n; i++) {
                if (i == arr[0])
                    cout << i << " ";
                else
                    cout << "0 ";
            }
            continue;
        }
        vector<ll> count(n + 1);
        for (auto it : arr) count[it]++;
        anoth(count);
    }
}