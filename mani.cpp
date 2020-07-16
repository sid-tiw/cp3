#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, count = 0;
        cin >> n;
        long *arr = new long[n], k, cost = 0, prev = 0;
        set<long> tem;
        cin >> k;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] = k - (arr[i] % k);
            if (arr[i] == k) arr[i] = 0;
        }
        sort(arr, arr + n);
        if (arr[0]) tem.insert(arr[0]);
        for (int i = 1; i < n; i++) {
            if (!arr[i]) continue;
            if (arr[i] == arr[i - 1]) {
                count++;
                tem.insert(arr[i] + count * k);
            } else {
                count = 0;
                tem.insert(arr[i]);
            }
        }
        cost = *(--tem.end()) + 1;
        if (cost) ++cost;
        cout << cost << "\n";
    }
    return 0;
}