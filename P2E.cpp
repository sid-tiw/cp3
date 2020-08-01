#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

string to_str(int a, int b) {
    string str = "";
    for (int i = 0; i < a; i++) str += '9';
    if (b != 0) str = to_string(b) + str;
    return str;
}

string process(int x) {
    if (!x) return "";
    if (x <= 8) return to_string(x);
    return to_str((x - 8) / 9, (x - 8) % 9) + "8";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> poss;
        bool fl = false;
        vector<ll> mainan;
        for (int i = 0; i <= 9; i++) {
            int sum = 0, flag = 0;
            for (int j = 0; j <= k; j++) {
                if ((j + i) > 9) flag++;
                sum += ((j + i) % 10) + ((j + i) / 10);
            }
            int v1 = n - sum;
            if (v1 < 0) continue;
            string ans = "-1";
            if (flag && (v1 % (k + 1) == 0)) {
                v1 /= (k + 1);
                ans = process(v1);
            } else if (flag && v1 > 9) {
                v1 -= 9;
                int x = 0, y = 0;
                while (y * 9 <= v1) {
                    x = 0;
                    while (y * 9 + x * (k + 1) <= v1) {
                        if (y * 9 + x * (k + 1) == v1) {
                            ans = process(x) + to_str(y, 0) + "9";
                        }
                        break;
                        x++;
                    }
                    if (ans != "-1") break;
                    y++;
                }
            } else if ((v1 % (k + 1) == 0)) {
                v1 /= (k + 1);
                ans = to_str(v1 / 9, v1 % 9);
            }
            if (ans == "-1") continue;
            ans += to_string(i);
            string::size_type sz = 0;
            mainan.push_back(stoll(ans, &sz));
        }
        if (!mainan.size()) {
            cout << "-1\n";
            continue;
        }
        sort(mainan.begin(), mainan.end());
        cout << mainan[0] << "\n";
    }
    return 0;
}