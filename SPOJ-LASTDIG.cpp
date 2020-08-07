#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

template <class T, class POW>
T binary_exp_iter(T a, POW b) {
    T res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
		res %= 10;
        a *= a;
		a %= 10;
        b >>= 1;
    }
    return res % 10;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
		cout << binary_exp_iter(a, b) << "\n";
	}
	return 0;
}