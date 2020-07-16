#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long *arr = new long[n + 1];
	for (int i = 0; i <= n; i++)
		cin >> arr[i];
	long x;
	cin >> x;
	long p = arr[n] * x;
	for (int i = n - 1; i > 0; i--)
		p = (p + arr[i]) * x;
	p += arr[0];
	cout << p << "\n";
}