#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long r = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = 0; k < j; k++)
			{
				r++;
			}
		}
	}
	cout << r << "\n";
	return 0;
}