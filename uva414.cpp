#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;
    while (n != 0) {
        cin.ignore(1);
        char str[n][30];
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++) cin.getline(str[i], 100);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 25; j++)
                if (str[i][j] == 'X') count[i]++;
        sort(count.begin(), count.end());
        int ans = 0;
        for (int i = 0; i < n - 1; i++) ans += (count[n - 1] - count[i]);
        cout << ans << "\n";
        cin >> n;
    }
}