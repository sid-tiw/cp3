#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int q, k, mx = 100001;
    cin >> q;
    string dp[mx];
    dp[1] = "1";
    for (int i = 2; i < mx; i++) {
        string str = dp[i - 1];
        int n = str.size(), k, change = 0;
        for (k = n - 1; k >= 0; k--) {
            int num = 1 << k;
            if (num % 2 == 0) {
                if (str[k] <= '8') {
                    str[k]++;
                    break;
                }
                str[k] = '0';
                continue;
            }
            if ((change && str[k] <= '8') || (!change && str[k] <= '7')) {
                if (change)
                    str[k]++;
                else
                    str[k] += 2;
                break;
            } else {
                if ((num * (str[k] - '0')) % 2 != 0) change++;
                str[k] = '0';
            }
        }
        change %= 2;
        if (k == -1)
            str = "1" + str;
        else if (change) {
            for (k = n - 1; k >= 0; k--) {
                int num = 1 + (k * k + k) / 2;
                if (num & 1) continue;
                str[k] = '1';
                break;
            }
        }
        dp[i] = str;
    }
    while (q--) {
        cin >> k;
        cout << "1 " << dp[k] << "\n";
    }
    return 0;
}