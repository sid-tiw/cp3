#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int MAX_N = 600000;
vector<vector<int>> seg(MAX_N);

void create_tree(string &str, int v, int l, int r) {
    seg[v] = *(new vector<int>(26, 0));
    if (l == r) {
        seg[v][str[l] - 'a']++;
        return;
    }
    int md = (l + r) / 2;
    create_tree(str, 2 * v + 1, l, md);
    create_tree(str, 2 * v + 2, md + 1, r);
    for (int i = 0; i < 26; i++)
        seg[v][i] = seg[2 * v + 1][i] + seg[2 * v + 2][i];
}

void update(int v, int l, int r, int ind, char val, char old) {
    if (l == r) {
        seg[v][old - 'a']--;
        seg[v][val - 'a']++;
        return;
    }
    int mid = (l + r) / 2;
    if (ind <= mid)
        update(2 * v + 1, l, mid, ind, val, old);
    else
        update(2 * v + 2, mid + 1, r, ind, val, old);
    for (int i = 0; i < 26; i++)
        seg[v][i] = seg[2 * v + 1][i] + seg[2 * v + 2][i];
}

vector<int> get_val(int v, int l, int r, int x, int y) {
    if (x > y) return vector<int>(26, 0);
    if (x == l && y == r) return seg[v];
    int mid = (l + r) / 2;
    auto it1 = get_val(2 * v + 1, l, mid, x, min(y, mid));
    auto it2 = get_val(2 * v + 2, mid + 1, r, max(x, mid + 1), y);
    for (int i = 0; i < 26; i++) it1[i] += it2[i];
    return it1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    string str;
    cin >> str;
    create_tree(str, 0, 0, str.size() - 1);
    int q;
    cin >> q;
    while (q--) {
        int cd, pos, l, r, count = 0;
        char ch;
        cin >> cd;
        if (cd == 1) {
            cin >> pos >> ch;
            update(0, 0, str.size() - 1, pos - 1, ch, str[pos - 1]);
            str[pos - 1] = ch;
        } else {
            cin >> l >> r;
            auto it = get_val(0, 0, str.size() - 1, l - 1, r - 1);
            for (int i = 0; i < 26; i++)
                if (it[i] > 0) count++;
            cout << count << "\n";
        }
    }
    return 0;
}