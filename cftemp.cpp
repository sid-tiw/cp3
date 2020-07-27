/*
    5
    7 4 9 19 3
*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// #define MYCOMP 1
#ifdef MYCOMP
class pscr {
   public:
    pscr() { cerr << "\n"; }
    template <class T,
              typename enable_if<is_fundamental<T>::value, T>::type* = nullptr>
    pscr operator<<(T var) {
        cerr << var;
        return *this;
    }
    template <class T, typename enable_if<!is_fundamental<T>::value &&
                                              !is_pointer<T>::value,
                                          T>::type* = nullptr>
    pscr operator<<(T& var) {
        int i = 0;
        for (auto it : var) {
            *this << it;
            if (i != var.size() - 1) string(", ");
            i++;
        }
        return *this;
    }
    template <class T,
              typename enable_if<is_pointer<T>::value, T>::type* = nullptr>
    pscr operator<<(T var) {
        cerr << "Can't print an array. Try something different.\n";
        return *this;
    }
    template <class T1, class T2>
    pscr operator<<(pair<T1, T2> var) {
        *this << "(" << var.first << ", " << var.second << ")";
        return *this;
    }
    pscr operator<<(const char str[]) {
        string tstr(str);
        cerr << tstr;
        return *this;
    }
    pscr operator<<(string var) {
        cerr << var;
        return *this;
    }
    template <size_t T>
    pscr operator<<(bitset<T> val) {
        cerr << val;
    }
};
#endif
#define debug(...) "[[" << #__VA_ARGS__ << ": " << __VA_ARGS__ << "]]\t\t"

typedef long long ll;
typedef bitset<20> btst;

int main() {
    int n;
    scanf("%d", &n);
    vector<btst> arr(n);
    for (int i = 0; i < n; i++) {
        ll temp;
        scanf("%lld", &temp);
        arr[i] = temp;
    }
    for (int i = 19; i >= 0; i--) {
        sort(arr.begin(), arr.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.to_ullong() < rhs.to_ullong();
        });
        vector<int> mn, mx;
        for (int j = 0; j < n; j++) {
            if (arr[j][i]) mn.push_back(j);
            if (!arr[j][i]) mx.push_back(j);
        }
        if (mn.size() && mx.size())
            for (int ind = 0; ind < mn.size() && ind < mx.size(); ind++) {
                btst x1 = arr[mn[ind]], x2 = arr[mx[mx.size() - ind - 1]];
                if (x1.to_ullong() > x2.to_ullong()) break;
                arr[mn[ind]] = x1 & x2;
                arr[mx[mx.size() - ind - 1]] = x1 | x2;
            }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += (arr[i].to_ullong() * arr[i].to_ullong());
    cout << sum << "\n";
}