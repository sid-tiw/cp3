#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, k, sum = 0;
	cin >> n >> k;
	set<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		auto it = lower_bound(arr.begin(), arr.end(), make_pair(temp, 0));
		if (it == arr.end() || (*it).first != temp) {
			arr.insert(make_pair(temp, 1));
			continue;
		}
		auto som = *it;
		som.second++;
		arr.erase(it);
		arr.insert(som);
	}
	while (k--) {
		auto it = *(--arr.end());
		it.second--;
		int val = floor(it.first / 2);
		arr.erase((--arr.end()));
		if (it.second != 0) arr.insert(it);
		auto it_t = lower_bound(arr.begin(), arr.end(), make_pair(val, 0));
		if (it_t == arr.end() || (*it_t).first != val) {
			arr.insert(make_pair(val, 1));
			continue;
		}
		auto som = *it_t;
		som.second++;
		arr.erase(it_t);
		arr.insert(som);
	}
	for (auto it : arr) sum += (ll)it.first * it.second;
	cout << sum;
	return 0;
}