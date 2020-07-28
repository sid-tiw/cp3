#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int min_dp(vector<int> arr, int m) {  // Not working
    int n = arr.size();
    vector<bool> temp;
    temp.push_back(false);
    for (int i = n - 2; i >= 0; i--) {
        int ti = i, count = 0;
        for (int j = i - 1; j >= 0 && arr[i] == arr[j]; j--) count++;
        ti -= count;
        int if_not_moved = 0, if_moved = count + 1;
        int t_size = temp.size();
        for (int j = 0; j < t_size; j++) {
            if (arr[j + i + 1] < arr[i] || temp[t_size - j - 1]) if_not_moved++;
            if (temp[t_size - j - 1]) if_moved++;
        }
        if (if_moved < if_not_moved)
            for (int j = 0; j <= count; j++) temp.push_back(true);
        if (if_moved >= if_not_moved) {
            for (int j = 0; j <= count; j++) temp.push_back(false);
            for (int j = 0; j < temp.size(); j++)
                if (arr[j + i] < arr[i]) temp[j] = true;
        }
        i = ti;
    }
    int count = 0;
    for (auto it : temp)
        if (it) count++;
    return count;
}

int alternative(vector<int> arr, int m) {   // working function
    vector<int> temp;
    temp.push_back(1);
    for (int i = 1; i < arr.size(); i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j]) continue;
            mx = max(temp[j], mx);
        }
        mx++;
        temp.push_back(mx);
    }
    int max_ans = temp[0];
    for (auto it : temp) max_ans = max(max_ans, it);
    return arr.size() - max_ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        long double dd;
        int tt;
        cin >> tt >> dd;
        arr.push_back(tt);
    }
    cout << alternative(arr, m) << "\n";
    return 0;
}