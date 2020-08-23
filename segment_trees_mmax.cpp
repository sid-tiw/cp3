// Author: Siddhartha Tiwari
// This segment tree implementation works for any associative operation.

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int MAX_S = 100;
int ex_ele = INT_MAX;  // The extreme element for whatever the type of the query
vector<int> seg_tree(MAX_S);

int operate(int a, int b) {
	// return a > b ? a : b;
	return a < b ? a : b;
	// return a + b;
	// return __gcd(a, b);

}

void create_tree(vector<int> &arr, int v, int l, int r) {
    if (l == r) {
        seg_tree[v] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    create_tree(arr, 2 * v + 1, l, mid);
    create_tree(arr, 2 * v + 2, mid + 1, r);
    seg_tree[v] = operate(seg_tree[2 * v + 1], seg_tree[2 * v + 2]);
}

int queries(int v, int l, int r, int x, int y) {
    if (x == l && r == y) return seg_tree[v];
    if (r < x || l > y) return ex_ele;
    int mid = (l + r) / 2;
    return operate(queries(2 * v + 1, l, mid, x, min(mid, y)),
                   queries(2 * v + 2, mid + 1, r, max(mid + 1, x), y));
}

void update(int v, int l, int r, int val, int ind) {
    if (l == r) {
        seg_tree[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (ind <= mid)
        update(2 * v + 1, l, mid, val, ind);
    else
        update(2 * v + 2, mid + 1, r, val, ind);
    seg_tree[v] = operate(seg_tree[2 * v + 1], seg_tree[2 * v + 2]);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    create_tree(arr, 0, 0, n - 1);
    cout << queries(0, 0, n - 1, 5, 6) << "\n";
    update(0, 0, n - 1, 8, 5);
    cout << queries(0, 0, n - 1, 5, 6) << "\n";
	cout << queries(0, 0, n - 1, 0, 9) << "\n";
    return 0;
}