#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

template <class T, class POW>
T binary_exp(T a, POW b, T md) {
    T res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        res %= md;
        a *= a;
        a %= md;
        b >>= 1;
    }
    return res % md;
}

template <class T>
bool check_base(T base, T prime, T exp, T fact) {
    if (base == prime) return true;
    T vl = 1;
    for (T i = 0; i < exp; i++) {
        if (!((binary_exp(base, vl * fact, prime) + 1) % prime)) return true;
        vl *= 2;
    }
    if (binary_exp(base, fact, prime) == 1) return true;
    return false;
}

template <class T>
bool miller_rabin(T prm) {
    if (prm < 4) return prm == 2 || prm == 3;
    T exp = 0, fact = prm - 1;
    while (!(fact & 1)) {
        fact /= 2;
        exp++;
    }
    vector<T> primes_64 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (auto it : primes_64)
        if (!check_base(it, prm, exp, fact)) return false;
    return true;
}

int main() {
    // ofstream of("primes.txt");
    // int lim = 100000;
    // vector<int> primes;
    // for (int i = 2; i < lim; i++)
    //     if (miller_rabin(i)) primes.push_back(i);
    // for (auto it : primes) of << it << " ";
    while (true) {
        long long val;
        cin >> val;
        if (!val) break;
        cout << boolalpha << miller_rabin(val) << "\n";
    }
    return 0;
}