// 0.101610
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int MAX_C = 2000000;
vector<vector<int>> arr(51);
map<pair<int, int>, int> dp;

int dp_ans(int num, int cost) {
    if (num >= 51) return 0;
    if (dp[make_pair(num, cost)] != 0) return dp[make_pair(num, cost)] - 1;
    int max_value = dp_ans(num + 1, cost), cs, tc = 0;
    for (int i = 0; i < arr.at(num).size(); i++) {
        tc += arr[num][i];
        if ((cost - tc) < 0) break;
        cs = dp_ans(num + 1, cost - tc);
		cs += (i + 1) * num;
        max_value = max(cs, max_value);
    }
    dp[make_pair(num, cost)] = max_value + 1;
    return max_value;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> value(n);
    for (int i = 0; i < n; i++) cin >> value[i].second;
    for (int i = 0; i < n; i++) cin >> value[i].first;
    
    sort(value.begin(), value.end());

    for (int i = 0; i < n; i++) arr[value[i].second].push_back(value[i].first);

    cout << dp_ans(0, c) << "\n";

    return 0;
}