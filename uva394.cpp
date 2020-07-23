/*
 * Siddhartha Tiwari
 * Date: 22-08-2020
 */

#include <bits/stdc++.h>
using namespace std;
#ifdef MYCOMP
class pscr {
   public:
    pscr() { cerr << "\n"; }
    template <class T,
              typename enable_if<is_fundamental<T>::value, T>::type* = nullptr>
    pscr operator<<(T var) const {
        cerr << var;
        return *this;
    }
    template <class T, typename enable_if<!is_fundamental<T>::value &&
                                              !is_pointer<T>::value,
                                          T>::type* = nullptr>
    pscr operator<<(T& var) const {
        typedef typename T::value_type temp_type;
        vector<temp_type> temp;
        temp.insert(temp.begin(), var.begin(), var.end());
        auto it = temp.begin();
        for (; it != (--temp.end()); it++) *this << *it << string(", ");
        *this << *it;
        return *this;
    }
    template <class T,
              typename enable_if<is_pointer<T>::value, T>::type* = nullptr>
    pscr operator<<(T var) const {
        cerr << "Can't print an array. Try something different.\n";
        return *this;
    }
    template <class T1, class T2>
    pscr operator<<(pair<T1, T2> var) const {
        *this << "(" << var.first << ", " << var.second << ")";
        return *this;
    }
    pscr operator<<(const char str[]) const {
        string tstr(str);
        cerr << tstr;
        return *this;
    }
    pscr operator<<(string var) const {
        cerr << var;
        return *this;
    }
};
#endif
#define debug(...) "[[" << #__VA_ARGS__ << ": " << __VA_ARGS__ << "]]\t\t"
#define vctr vector<unsigned int>
#define mp map<string, int>
#define mp1 map<string, vctr>

int main() {
    int N, R;
    cin >> N >> R;
    vector<string> arrays(N);
    map<string, pair<mp, mp1>> ass;
    vector<pair<string, vctr>> queries;
    for (int i = 0; i < N; i++) {
        cin >> arrays[i];
        unsigned int B, CD, D;
        cin >> B >> CD >> D;
        vctr ld(D), ud(D);
        for (int j = 0; j < D; j++) cin >> ld[j] >> ud[j];
        mp temp1 = {{"B", B}, {"CD", CD}, {"D", D}};
        mp1 temp2 = {{"ld", ld}, {"ud", ud}};
        ass[arrays[i]] = make_pair(temp1, temp2);
    }
    for (int i = 0; i < R; i++) {
        string nm;
        cin >> nm;
        int dim = ass[nm].first["D"];
        vctr temp(dim);
        for (int j = 0; j < dim; j++) cin >> temp[j];
        long prev = ass[nm].first["CD"];
        long addr = (1L) * prev * temp[dim - 1],
             sum = (1L) * prev * ass[nm].second["ld"][dim - 1];
        for (int j = dim - 2; j >= 0; j--) {
            long cd =
                (1L) * prev *
                (ass[nm].second["ud"][j + 1] - ass[nm].second["ld"][j + 1] + 1);
            prev = cd;
            addr += (1L) * prev * temp[j];
            sum += (1L) * prev * ass[nm].second["ld"][j];
        }
        long c0 = ass[nm].first["B"] - sum;
        addr += c0;
        cout << nm << "[";
        auto it = temp.begin();
        for (; it != (temp.end() - 1); it++) cout << *it << ", ";
        cout << *it << "] = " << addr << "\n";
    }
    return 0;
}
