#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> prl;

void calc(vector<ll> arr, vector<ll> &dp) {
    if (arr.size() == 0) return;
    auto count = arr;
    sort(count.rbegin(), count.rend());
    ll sum = 0, sum_first = 0, sum_second = 0;
    for (int i = 0; i < count.size(); i++) sum += count[i];
    for (int i = 0; i < count.size(); i++)
        sum_first += ((sum - count[i]) * count[i]);
    sum_first /= 2;
    for (int i = 0; i < count.size(); i++)
        sum_second += ((sum_first - (sum - count[i]) * count[i]) * count[i]);
    sum_second /= 3;
    dp.push_back(sum_second);
    while (count.size() != 0) {
        auto it = count.end() - 1;
        while ((*it) != 0) {
            sum_second -= ((sum_first - (sum - *it) * (*it)) * (*it));
            sum_first -= (sum - (*it)) * (*it);
            (*it)--;
            sum--;
            sum_first += (sum - (*it)) * (*it);
            sum_second += ((sum_first - (sum - *it) * (*it)) * (*it));
            dp.push_back(sum_second);
        }
        if (sum_second == 0) return;
        count.erase(it);
    }
}

ll calc_ans(vector<vector<ll>> dp, vector<vector<ll>> &ans_dp, int n, ll km,
            vector<ll> leng) {
    if (n == dp.size()) return 0;
    if (ans_dp[n][km] != -1) return ans_dp[n][km];
    ll glb_min = LLONG_MAX;
    for (ll i = 0; (i * leng[n] <= km) && i < dp[n].size(); i++) {
        ll temp = dp[n][i] + calc_ans(dp, ans_dp, n + 1, km - i * leng[n], leng);
        if (temp < glb_min) glb_min = temp;
    }
    ans_dp[n][km] = glb_min;
    return glb_min;
}

ll calc_ans_iter(vector<vector<ll>> dp, vector<ll> leng, ll km) {
    vector<vector<ll>> ans_dp(dp.size(), vector<ll>(km + 1, 0));
    for (int i = 0; i <= km; i++) {
        ll k = i / leng[0];
        if (k >= dp[0].size()) break;
        ans_dp[0][i] = dp[0][k];
    }
    for (int i = 1; i < dp.size(); i++) {
        ll len = dp[i].size() - 1;
        for (int j = 0; j <= km; j++) {
            ll num = min(j / leng[i], len);
            ll mn_el = dp[i][0] + ans_dp[i - 1][j], temp;
            for (int k = 1; k <= num; k++) {
                temp = dp[i][k] + ans_dp[i - 1][j - k * leng[i]];
                if (mn_el > temp) mn_el = temp;
            }
            ans_dp[i][j] = mn_el;
        }
    }
    return ans_dp[dp.size() - 1][km];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, c, km;
        cin >> n >> c >> km;
        vector<vector<ll>> main_arr(c);
        map<ll, ll> arr[c];
        vector<ll> leng(c);
        vector<vector<ll>> dp(c), ans_dp(c, vector<ll>(3001, -1));
        for (int i = 0; i < n; i++) {
            ll a, b, col;
            cin >> a >> b >> col;
            if (arr[col - 1][a] == 0) {
                main_arr[col - 1].push_back(1);
                arr[col - 1][a] = main_arr[col - 1].size();
            } else {
                main_arr[col - 1][arr[col - 1][a] - 1]++;
            }
        }
        for (int i = 0; i < c; i++) cin >> leng[i];
        for (int i = 0; i < c; i++) calc(main_arr[i], dp[i]);
        vector<vector<ll>> tdp;
        vector<ll> tlen;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i].size() != 0 && leng[i] != 0) {
                tdp.push_back(dp[i]);
                tlen.push_back(leng[i]);
            }
        }
        cout << calc_ans_iter(tdp, tlen, km) << "\n";
    }
    return 0;
}