#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

auto create_sparse(vector<int> arr) {
    int n = arr.size();
    int m = log2(n);
    vector<vector<int>> sparse_table(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) sparse_table[i][0] = arr[i];
    for (int i = 1; i <= m; i++) {
        int ind = 1 << i;
        for (int j = 0; j + ind <= n; j++) {
            sparse_table[j][i] =
                min(sparse_table[j][i - 1], sparse_table[j + ind / 2][i - 1]);
        }
    }
    return sparse_table;
}

auto calc_log(int n) {
    vector<int> logar(n + 1);
    logar[1] = 0;
    for (int i = 2; i <= n; i++) logar[i] = logar[i / 2] + 1;
    return logar;
}

int answer_range(vector<vector<int>> arr, int l, int r, vector<int> logar) {
    int val = logar[r - l + 1];
    return min(arr[l][val], arr[r - (1 << val) + 1][val]);
}

int main() {
    int n;
    cin >> n;
    set<ll> temp;
    map<ll, int> mp;
    vector<pair<ll, ll>> orig(n);
    for (int i = 0; i < n; i++) {
        cin >> orig[i].first >> orig[i].second;
        temp.insert(orig[i].first);
        temp.insert(orig[i].second);
    }
    vector<ll> arr(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
        orig[i].first = lower_bound(arr.begin(), arr.end(), orig[i].first) -
                        arr.begin();
        orig[i].second = lower_bound(arr.begin(), arr.end(), orig[i].second) -
                         arr.begin();
    }
    int sz = 2 * n + 5;
    vector<int> diff_arr(sz, 0);
    for (int i = 0; i < n; i++) {
        diff_arr[orig[i].first]++;
        diff_arr[orig[i].second + 1]--;
    }
    for (int i = 1; i < sz; i++) diff_arr[i] += diff_arr[i - 1];
    auto sparse_table = create_sparse(diff_arr);
    auto logar = calc_log(sz + 1);
    for (int i = 0; i < n; i++) {
        int mn =
            answer_range(sparse_table, orig[i].first, orig[i].second, logar);
        if (mn >= 2) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}