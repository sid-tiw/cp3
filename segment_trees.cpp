// Author: Siddhartha Tiwari
// Segment tree for sum queries

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int MAX_N = 100;
vector<int> seg_tree(4 * MAX_N);

void create_tree(int v, int l, int r, vector<int> &arr) {
    if (l == r) {
        seg_tree[v] = arr[l];
        return;
    }
    int md = (l + r) / 2;
    create_tree(2 * v + 1, l, md, arr);
    create_tree(2 * v + 2, md + 1, r, arr);
    seg_tree[v] = seg_tree[2 * v + 1] + seg_tree[2 * v + 2];
}

int sum_queries(int v, int l, int r, int x, int y) {
    if (x == l && y == r) return seg_tree[v];
    if (y < l || x > r) return 0;
    int mid = (l + r) / 2;
    return sum_queries(2 * v + 1, l, mid, x, min(mid, y)) +
           sum_queries(2 * v + 2, mid + 1, r, max(x, mid + 1), y);
}

void update(int v, int val, int l, int r, int ind) {
    if (l == r) {
        seg_tree[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= ind)
        update(2 * v + 1, val, l, mid, ind);
    else
        update(2 * v + 2, val, mid + 1, r, ind);
    seg_tree[v] = seg_tree[2 * v + 1] + seg_tree[2 * v + 2];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    create_tree(0, 0, n - 1, arr);
	cout << sum_queries(0, 0, n - 1, 5, 6) << "\n";
	update(0, 8, 0, n - 1, 5);
	cout << sum_queries(0, 0, n - 1, 5, 6) << "\n";
	for (int i = 0; i < 4 * n; i++) cout << seg_tree[i] << " ";
	cout << "\n";
    return 0;
}