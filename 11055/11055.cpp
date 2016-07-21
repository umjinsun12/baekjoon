#include <iostream>
using namespace std;

int a[1001];
int d[1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		d[i] = a[i];
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && d[i] < d[j] + a[i])
				d[i] = d[j] + a[i];
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