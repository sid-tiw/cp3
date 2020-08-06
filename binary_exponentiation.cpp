#include <iostream>
#include <string>

using namespace std;

template <class T>
T binary_exp_rec(T a, T b) {
    T ans, ml = 1;
	if (!b) return 1;
    if (b % 2 == 0) ans = binary_exp_rec(a, b / 2);
    if (b % 2 != 0) {
        ans = binary_exp_rec(a, (b - 1) / 2);
        ml = a;
    }
    return ans * ans * ml;
}

template<class T>
T binary_exp_iter(T a, T b) {
	T res = 1;
	while (b > 0) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int main() {
	cout << binary_exp_iter(3, 5);
	return 0;
}