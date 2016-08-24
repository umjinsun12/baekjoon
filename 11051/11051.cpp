#include <iostream>
using namespace std;

int d[1001][1001];
int mod = 10007;

int main()
{
	int n, k;
	cin >> n >> k;

	d[1][0] = 1;
	d[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			d[i][j] += d[i - 1][j - 1] % mod;
			if (i - 1 >= j)
				d[i][j] += d[i - 1][j] % mod;
		}
	}

	cout << d[n][k] % mod << '\n';

}