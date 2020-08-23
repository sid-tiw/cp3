// Author: Siddhartha Tiwari
/*
1
15 100
1 2 1
1 3 1
2 4 1
2 5 1
3 6 1
3 7 1
4 8 1
4 9 1
5 10 1
5 11 1
6 12 1
6 13 1
7 14 1
7 15 1

*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long ll;
typedef pair<int, ll> prl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        ll s, wg, orig_s = 0;
        cin >> n >> s;
        vector<vector<prl>> vec(n);
        vector<ll> num_l(n, 0), weight(n);
        vector<bool> visit(n, false);
        set<pair<ll, int>> spt;
        stack<int> stk;
        for (int i = 1; i < n; i++) {
            cin >> a >> b >> wg;
            vec[a - 1].push_back(mp(b - 1, wg));
            vec[b - 1].push_back(mp(a - 1, wg));
        }
        for (int i = 1; i < n; i++)
            if (vec[i].size() == 1) {
                stk.push(i);
                num_l[i]++;
            }
        stack<int> tt = stk;
        // for (auto it : vec) {
            // for (auto jt : it) cout << jt.first << "|" << jt.second << " ";
            // cout << "\n";
        // }
        // while (!tt.empty()) {
            // cout << tt.top() << " ";
            // tt.pop();
        // }
        // cout << "-----\n";
        while (!stk.empty() && stk.top() != 0) {
            set<int> temp;
            while (!stk.empty()) {
                int ind = stk.top();
                visit[ind] = true;
                for (int j = 0; j < vec[ind].size(); j++) {
                    int t_ind = vec[ind][j].first;
                    if (visit[t_ind]) continue;
                    // cout << t_ind << " ";
                    weight[ind] = vec[ind][j].second;
                    num_l[t_ind] += num_l[ind];
                    temp.insert(t_ind);
                }
                // cout << "\n-----\n";
                stk.pop();
            }
            for (auto it : temp) stk.push(it);
            // for (auto it : temp) cout << it << " ";
            // cout << "\n";
        }
        for (int i = 1; i < n; i++) {
            spt.insert(mp(num_l[i] * (weight[i] - floor(weight[i] / 2.0)), i));
            orig_s += num_l[i] * weight[i];
        }
        // cout << orig_s << "\n";
        // for (int i = 0; i < n; i++) cout << num_l[i] << " ";
        // cout << "\n";
        int steps = 0;
        while (orig_s > s) {
            auto pr = *(--spt.end());
            spt.erase(--spt.end());
            orig_s -= pr.first;
            weight[pr.second] = weight[pr.second] / 2;
            spt.insert(mp(num_l[pr.second] * (weight[pr.second] -
                                              floor(weight[pr.second] / 2.0)),
                          pr.second));
            steps++;
        }
        cout << steps << "\n";
    }
    return 0;
}