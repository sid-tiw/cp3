#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <class T>
pair<T, T> extended_gcd(T a, T b) {
    pair<T, T> pa(1, 0), pb(0, 1), temp;
    while (b) {
        if (a % b == 0) return pb;
        T q = a / b;
        temp = pair<T, T>(pa.first - q * pb.first, pa.second - q * pb.second);
        pa = pb;
        pb = temp;
        swap(a, b);
        b %= a;
    }
    return pb;
}

int main() {
	int a = 18, b = 12;
	cin >> a >> b;
	auto it = extended_gcd(a, b);
	cout << it.first * a + it.second * b << "\n";
	return 0;
}