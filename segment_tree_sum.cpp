// Author: Siddhartha Tiwari
// IIIT Vadodara
// The implementation of the segment tree for sums

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void build_seg_tree(vector<int> &seg_tree, pair<int, int> pr, int ind,
                    vector<int> pref_sum) {
    if (pr.first > pr.second) return;
    seg_tree[ind] = pref_sum[pr.second];
    if (pr.first != 0) seg_tree[ind] -= pref_sum[pr.first - 1];
    int mid = (pr.first + pr.second) / 2;
    if (pr.first == pr.second) return;
    build_seg_tree(seg_tree, make_pair(pr.first, mid), 2 * ind + 1, pref_sum);
    build_seg_tree(seg_tree, make_pair(mid + 1, pr.second), 2 * ind + 2,
                   pref_sum);
}

void update(vector<int> &seg_tree, int val, int ind, pair<int, int> pr,
            int c_ind) {
    if (pr.first > pr.second) return;
    int mid = (pr.first + pr.second) / 2;
    seg_tree[c_ind] += val;
    auto npr = make_pair(pr.first, pr.second);
    if (pr.first == pr.second) return;
    if (ind <= mid)
        update(seg_tree, val, ind, make_pair(pr.first, mid), 2 * c_ind + 1);
    else
        update(seg_tree, val, ind, make_pair(mid + 1, pr.second),
               2 * c_ind + 2);
}

int sum_to_l(vector<int> &seg_tree, int L, int ind, pair<int, int> pr) {
    if (L < 0) return 0;
    int mid = (pr.first + pr.second) / 2;
    if (pr.second == L) return seg_tree[ind];
    if (mid >= L)
        return sum_to_l(seg_tree, L, 2 * ind + 1, make_pair(pr.first, mid));
    if (mid < L)
        return sum_to_l(seg_tree, mid, 2 * ind + 1, make_pair(pr.first, mid)) + sum_to_l(seg_tree, L, 2 * ind + 2,
                                        make_pair(mid + 1, pr.second));
}

int main() {
    ifstream fin("in.txt");
    int n, q;
    fin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) fin >> arr[i];
    vector<int> seg_tree(4 * n);
    vector<int> pref_sum(n, 0);
    pref_sum[0] = arr[0];
    for (int i = 1; i < n; i++) pref_sum[i] = pref_sum[i - 1] + arr[i];
    build_seg_tree(seg_tree, make_pair(0, n - 1), 0, pref_sum);
    cout << "\n";
    while (q--) {
        int qno, val, ind, l, r;
        fin >> qno;
        if (qno) {
            fin >> val >> ind;
            update(seg_tree, val - arr[ind], ind, make_pair(0, n - 1), 0);
            arr[ind] = val;
        } else {
            fin >> l >> r;
            cout << sum_to_l(seg_tree, r, 0, make_pair(0, n - 1)) -
                        sum_to_l(seg_tree, l - 1, 0, make_pair(0, n - 1))
                 << "\n";
        }
    }
    return 0;
}