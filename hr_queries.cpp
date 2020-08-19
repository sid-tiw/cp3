#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void insert(deque<int> &qu, int ele) {
    while (!qu.empty() && qu.back() < ele) qu.pop_back();
    qu.push_back(ele);
}

void remove(deque<int> &qu, int ele) {
    if (qu.front() == ele) qu.pop_front();
}

int main() {
	ios_base::sync_with_stdio(false);
    int n, q, d;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    while (q--) {
        cin >> d;
        deque<int> qu;
        for (int i = 0; i < d; i++) insert(qu, arr[i]);
        int mn = qu.front();
        for (int i = 0; i < (n - d); i++) {
            remove(qu, arr[i]);
			insert(qu, arr[i + d]);
            mn = min(mn, qu.front());
        }
		cout << mn << "\n";
    }
    return 0;
}