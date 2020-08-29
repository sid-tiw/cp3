#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void sieve(vector<int> &arr, int n) {
    vector<bool> sta(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!sta[i]) continue;
        for (int j = 2; i * j <= n; j++) sta[i * j] = false;
    }
    for (int i = 2; i <= n; i++)
        if (sta[i]) arr.push_back(i);
}

void calc(vector<pair<int, int>> &arr, int n, vector<int> &ans) {
    if (arr.size() == 0) {
        ans.push_back(1);
        return;
    }
    if (n == arr.size() - 1) {
        ans.push_back(1);
        for (int i = 1; i <= arr[n].first; i++)
            ans.push_back(ans[i - 1] * arr[n].second);
        return;
    }
    calc(arr, n + 1, ans);
    int p = ans.size();
    int val = 1;
    for (int i = 1; i <= arr[n].first; i++) {
        val *= arr[n].second;
        for (int j = 0; j < p; j++) ans.push_back(val * ans[j]);
    }
}

int main() {
    int n = 100000;
    vector<int> arr;
    sieve(arr, n);
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "infinity\n";
        return 0;
    }
    ll num = a - b, ans = 0;
    vector<pair<int, int>> pfac;
    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        while (num % arr[i] == 0) {
            num /= arr[i];
            count++;
        }
        if (count != 0) pfac.push_back(make_pair(count, arr[i]));
    }
    if (num != 1) pfac.push_back(make_pair(1, num));
    vector<int> it;
    calc(pfac, 0, it);
    for (auto i : it)
        if (i > b) ans++;
    cout << ans << "\n";
    return 0;
}