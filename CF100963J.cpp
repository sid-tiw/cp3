#include <iostream>

using namespace std;
typedef long long ll;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, a, k;
    cin >> n >> m >> a >> k;
    while (n || m || a || k) {
        auto it = extended_gcd(m, a);
        ll gcd = it.first * m + it.second * a, lcm = m / gcd * a;
        if ((k + a - n) % gcd != 0) {
            cout << "Impossible\n";
            cin >> n >> m >> a >> k;
            continue;
        }
        ll fac = (k + a - n) / gcd;
        ll x = it.first * fac, y = it.second * fac;
        ll ans1 = n + x * m, ans2 = k + a - y * a;
        while (ans1 < n || ans2 < k + a) {
            ans1 += lcm;
            ans2 += lcm;
        }
        cout << ans1 << "\n";
        cin >> n >> m >> a >> k;
    }
    return 0;
}