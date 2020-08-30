#include <algorithm>
#include <chrono>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

int max_i = 1000001;
vector<int> nof(max_i + 1);

int MAX_N = 1200015, max_x = 300005;
vector<pair<ll, set<int>>> seg(MAX_N);
vector<int> marr(max_x);

void construct(int v, int l, int r) {
    if (l == r) {
        set<int> temp;
        if (marr[l] != 1 && marr[l] != 2) temp.insert(l);
        seg[v] = make_pair(marr[l], temp);
        return;
    }
    int m = (l + r) / 2;
    construct(2 * v + 1, l, m);
    construct(2 * v + 2, m + 1, r);
    for (int i = l; i <= r; i++)
        if (marr[i] != 1 && marr[i] != 2) seg[v].second.insert(i);
    seg[v].first = seg[2 * v + 1].first + seg[2 * v + 2].first;
}

vector<int> update(int v, int l, int r, int x, int y) {
    vector<int> to_r;
    if (x > y) return to_r;
    if (seg[v].second.size() == 0) return to_r;
    if (x == l && y == r && x == y) {
        seg[v].first = nof[seg[v].first];
        if (seg[v].first == 2) {
            to_r.push_back(l);
            seg[v].second = set<int>();
        }
        return to_r;
    }
    int m = (l + r) / 2;
    to_r = update(2 * v + 1, l, m, x, min(m, y));
    auto it = update(2 * v + 2, m + 1, r, max(x, m + 1), y);
    seg[v].first = seg[2 * v + 1].first + seg[2 * v + 2].first;
    to_r.insert(to_r.end(), it.begin(), it.end());
    for (auto i : to_r) seg[v].second.erase(i);
    return to_r;
}

ll query_sum(int v, int l, int r, int x, int y) {
    if (x > y) return 0;
    if (l == x && r == y) return seg[v].first;
    int m = (l + r) / 2;
    return query_sum(2 * v + 1, l, m, x, min(y, m)) +
           query_sum(2 * v + 2, m + 1, r, max(m + 1, x), y);
}

void lowest_prime(vector<int> &arr, int n) {
    arr = vector<int>(n + 1, -1);
    for (int i = 2; i * i <= n; i++) {
        if (arr[i] != -1) continue;
        for (int j = 2; j * i <= n; j++)
            if (arr[i * j] == -1) arr[i * j] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> low;
    lowest_prime(low, max_i);
    nof[1] = 1;
    for (int i = 2; i <= max_i; i++) {
        if (low[i] == -1)
            nof[i] = 2;
        else {
            int c = 0, t = i;
            while (t % low[i] == 0) {
                c++;
                t /= low[i];
            }
            nof[i] = nof[t] * (c + 1);
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> marr[i];
    construct(0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1)
            update(0, 0, n - 1, l - 1, r - 1);
        else
            cout << query_sum(0, 0, n - 1, l - 1, r - 1) << "\n";
    }
    return 0;
}