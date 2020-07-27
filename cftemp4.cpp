#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool comp(char &ch1, char &ch2) { return ch1 > ch2; }

int main() {
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end(), comp);
    if (a.size() < b.size()) {
        cout << a << "\n";
        return 0;
    }
    string ans = "";
    string curr = a;
    for (int i = 0; i < a.size(); i++) {
        bool flag = false;
        for (int j = 0; j < curr.size(); j++) {
            if (curr[j] <= b[i]) {
                string temp = "";
                for (int k = curr.size() - 1; k >= 0; k--)
                    if (k != j) temp += curr[k];
                if (curr[j] < b[i]) {
                    ans += curr[j];
					reverse(temp.begin(), temp.end());
                    ans += temp;
                    flag = true;
                    break;
                }
                if (temp <= b.substr(i + 1)) {
                    ans += curr[j];
                    curr = temp;
					sort(curr.begin(), curr.end(), comp);
                    break;
                }
            }
        }
        if (flag) break;
    }
    cout << ans << "\n";
    return 0;
}