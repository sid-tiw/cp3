#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int m = log2(n);
    vector<vector<ll>> gcd(m + 1, vector<ll>(n));
    for (int i = 0; i < n; i++) gcd[0][i] = arr[i];
    for (int i = 1; i <= m; i++) {
        int ad = 1 << i;
        for (int j = 0; j + ad <= n; j++)
            gcd[i][j] = __gcd(gcd[i - 1][j], gcd[i - 1][j + ad / 2]);
    }
	// for (int i = 0; i < 3; i++) {
	// 	for (int j = 0; j < 3; j++) cout << gcd[j][i] << " ";
	// 	cout << "\n";
	// }
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	// for (int i = 1; i <= n; i++) cout << lg[i] << " ";
	// cout << "\n";
    int q;
    cin >> q;
    map<int, ll> cnt;
    for (int i = 0; i < n; i++) {
        int val = i;
        ll tem = arr[i];
        while (val < n) {
            int tt2 = val;
            int tt1 = lg[val - i + 1];
            tem = __gcd(gcd[tt1][i], gcd[tt1][val - (1 << tt1) + 1]);
            int start = val, end = n - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                int tt = lg[mid - i + 1];
                ll gc = __gcd(gcd[tt][i], gcd[tt][mid - (1 << tt) + 1]);
                if (gc == tem) {
                    val = mid;
                    start = mid + 1;
                } else
                    end = mid - 1;
            }
			// cout << tem << " " << val << " " << val - tt2 + 1 << "\n";
            cnt[tem] += (val - tt2 + 1);
            val++;
        }
		// cout << "\n";
    }
    while (q--) {
        ll vl;
        cin >> vl;
        cout << cnt[vl] << "\n";
    }
    return 0;
}