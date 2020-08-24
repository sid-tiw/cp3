#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int MAX_N = 500000;
vector<int> seg(MAX_N);
vector<int> visited(MAX_N, false);

void change(int v) {
    if (visited[v]) {
        visited[v] = false;
        seg[2 * v + 1] = seg[2 * v + 2] = seg[v];
        visited[2 * v + 1] = visited[2 * v + 2] = true;
    }
}

void create_tree(vector<int> &arr, int v, int l, int r) {
    if (l == r) {
        seg[v] = arr[l];
        visited[v] = true;
        return;
    }
    int mid = (l + r) / 2;
    create_tree(arr, 2 * v + 1, l, mid);
    create_tree(arr, 2 * v + 2, mid + 1, r);
    visited[v] = false;
}

void update(int v, int l, int r, int x, int y, int val) {
    if (l == x && y == r) {
        seg[v] = val;
        visited[v] = true;
        return;
    }
    if (x > y) return;
    change(v);
    int mid = (l + r) / 2;
    update(2 * v + 1, l, mid, x, min(y, mid), val);
    update(2 * v + 2, mid + 1, r, max(mid + 1, x), y, val);
}

int ele(int v, int l, int r, int ind) {
    if (l == r || visited[v] == true) return seg[v];
    int mid = (l + r) / 2;
    if (ind <= mid) return ele(2 * v + 1, l, mid, ind);
    return ele(2 * v + 2, mid + 1, r, ind);
}

int main() {
    int max_ele = 100005;
    int n;
    cin >> n;
    vector<int> arr(n), left(n, 0), right(n, 0), tree_l(max_ele, -1), tree_r(max_ele, n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    create_tree(tree_l, 0, 0, max_ele - 1);
    for (int i = 0; i < n; i++) {
        int ind = ele(0, 0, max_ele - 1, arr[i]);
        update(0, 0, max_ele - 1, arr[i] + 1, max_ele - 1, i);
        if (ind == i - 1) continue;
        left[i] = i - ind - 1;
    }
    for (int i = 0; i < MAX_N; i++) visited[i] = false;
    create_tree(tree_r, 0, 0, max_ele - 1);
    for (int i = n - 1; i >= 0; i--) {
        int ind = ele(0, 0, max_ele - 1, arr[i]);
        update(0, 0, max_ele - 1, arr[i] + 1, max_ele - 1, i);
        if (ind == i + 1) continue;
        right[i] = ind - i - 1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ((left[i] + 1) * (right[i] + 1));
        cout << (left[i] + 1) * (right[i] + 1) << " ";
    }
    return 0;
}