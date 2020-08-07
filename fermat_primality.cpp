#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

template <class T, class POW>
T binary_exp_iter(T a, POW b, T md) {
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
bool fermat_primality(T num) {
    if (num < 4) return num == 2 || num == 3;
    for (int i = 0; i < 10; i++) {
        T val = rand() % (num - 3) + 2;
        if (binary_exp_iter(val, num - 1, num) != 1) return false;
    }
    return true;
}

int main() {
	ll num;
	cin >> num;
	while(num) {
		cout << boolalpha << fermat_primality(num) << "\n";
		cin >> num;
	}
}