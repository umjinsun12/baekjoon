#include <iostream>
using namespace std;

int a[1001];
int d[1001];
int d2[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}

	for (int i = n-1; i >= 0; i--)
	{
		d2[i] = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j] && d2[i] < d2[j] + 1)
				d2[i] = d2[j] + 1;
		}
	}
	

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (ans < d[i] + d2[i] -1)
			ans = d[i] + d2[i] -1;
	}

	cout << ans << '\n';
}