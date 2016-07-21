#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int d[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	d[0] = 0;

	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (ans < d[i])
			ans = d[i];
	}

	cout << ans << '\n';
}