#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void sieve_eratosthenes(vector<int> &arr, int n);
vector<vector<int>> find_pos(string str, int val);
vector<string> fill_pos(vector<vector<int>> arr, string str);
vector<string> fill_vec(vector<int> arr, string str);

int main() {
    vector<int> primes;
    int number_of_primes = 1000000;
    sieve_eratosthenes(primes, number_of_primes);
    map<int, bool> srch;
    for (auto it : primes) srch[it] = 1;
    int k = 8;
    int max = *(primes.end() - 1);
    for (auto it : primes) {
        for (int i = 1; i <= to_string(it).size(); i++) {
            auto stage1 = find_pos(to_string(it), i);
            for (auto stage2 : stage1) {
                auto stage3 = fill_vec(stage2, to_string(it));
                int count = 0, mn = -1;
                for (auto stage4 : stage3) {
                    if (stage4.at(0) == '0') continue;
                    bool flg = srch[stoi(stage4)];
                    if (flg) {
                        if (mn == -1) mn = stoi(stage4);
                        count++;
                    }
                }
                if (count == 8) {
                    cout << mn << "\n";
                    return 0;
                }
            }
        }
    }
    system("PAUSE");
    return 0;
}

vector<vector<int>> find_pos(string str, int val) {
    if (val > str.size()) return vector<vector<int>>(0, vector<int>(0, 0));
    if (val == 1) {
        vector<vector<int>> ans;
        for (int i = 0; i < str.size(); i++) ans.push_back(vector<int>(1, i));
        return ans;
    }
    vector<vector<int>> ans;
    for (int i = 0; i <= str.size() - val; i++) {
        auto arr = find_pos(str.substr(i + 1), val - 1);
        for (auto it : arr) {
            if (it.size() != (val - 1)) continue;
            vector<int> temp;
            temp.push_back(i);
            for (auto pt : it) temp.push_back(pt + i + 1);
            ans.push_back(temp);
        }
    }
    return ans;
}

vector<string> fill_pos(vector<vector<int>> arr, string str) {
    vector<string> ans;
    for (auto it : arr) {
        vector<string> temp = fill_vec(it, str);
        for (auto it : temp) ans.push_back(it);
    }
    return ans;
}

vector<string> fill_vec(vector<int> arr, string str) {
    vector<string> temp(10, string(str));
    for (auto jt : arr)
        for (int i = 0; i < 10; i++) temp[i][jt] = i + '0';
    return temp;
}

void sieve_eratosthenes(vector<int> &arr, int n) {
    vector<bool> flags(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!flags[i]) continue;
        for (int j = i; i * j <= n; j++) flags[i * j] = false;
    }
    for (int i = 2; i <= n; i++)
        if (flags[i]) arr.push_back(i);
}