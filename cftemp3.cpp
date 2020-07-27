#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll d, m, val = 1, sum = 0;
        cin >> d >> m;
        ll lval = log2l(d);
        lval++;
        vector<ll> temp(lval + 1), mans(lval + 1);
        for (int i = 0; i <= lval; i++) mans[i] = 0;
        for (int i = 1; i < lval; i++) {
            temp[i] = val;
            sum += val;
            val *= 2;
        }
        temp[lval] = d - sum;
        mans[1] = 1;
        for (int i = 2; i <= lval; i++) {
            for (int j = i; j > 1; j--) {
                mans[j] += (mans[j - 1] * temp[i]);
                mans[j] %= m;
            }
            mans[1] += temp[i];
            mans[1] %= m;
        }
		ll ans = 0;
        for (int i = 1; i <= lval; i++) ans += mans[i];
		ans %= m;
        cout << ans << "\n";
    }
    return 0;
}