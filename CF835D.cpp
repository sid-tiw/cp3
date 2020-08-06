#include <bits/stdc++.h>
 
using namespace std;
int prime = 198491317;
 
int main() {
    string str;
    cin >> str;
    int constants[str.size()];
    constants[0] = 29;
    for (int i = 1; i < str.size(); i++) {
        long long temp = (constants[i - 1] * constants[0] * 1LL) % prime;
        constants[i] = temp;
    }
    pair<int, int> hashes[str.size()][str.size()];
    for (int i = 0; i < str.size(); i++) {
        int prev_hash = 0;
        for (int j = i; j < str.size(); j++) {
            long long temp = constants[j - i] * (long long)str[j] * 1LL + prev_hash;
            temp %= prime;
            prev_hash = temp;
            hashes[i][j].first = prev_hash;
        }
    }
    for (int i = str.size() - 1; i >= 0; i--) {
        int prev_hash = 0;
        for (int j = i; j >= 0; j--) {
            long long temp = constants[i - j] * str[j] * 1LL + prev_hash;
            temp %= prime;
            prev_hash = temp;
            hashes[j][i].second = prev_hash;
        }
    }
    short dp[str.size()][str.size()];
    int som[str.size() + 1];
    for (int i = 0; i <= str.size(); i++) som[i] = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            dp[i][j] = 0;
            if (i == j) {
                dp[i][j] = 1;
                som[1]++;
                continue;
            }
            int len = j - i + 1;
            len /= 2;
            if (hashes[i][i + len - 1].first == hashes[j - len + 1][j].second)
                dp[i][j] = 1;
            if (hashes[i][i + len - 1].first == hashes[j - len + 1][j].first)
                dp[i][j] = dp[i][j] > dp[i][i + len - 1] + 1 ? dp[i][j] : dp[i][i + len - 1] + 1;
            som[dp[i][j]]++;
        }
    }
    for (int i = 1; i <= str.size(); i++)
        for (int j = i - 1; j >= 1; j--) som[j] += som[i];
    for (int i = 1; i <= str.size(); i++) cout << som[i] << " ";
    cout << "\n";
    return 0;
}