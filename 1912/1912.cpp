#include <iostream>
using namespace std;

int a[100001];
int d[100001];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		d[i] = a[i];
		if (i == 0) continue;
		if (d[i] < d[i-1] + a[i])
			d[i] = d[i-1] + a[i];
	}

	int ans = d[0];
	for (int i = 1; i < n; i++)
	{
		if (ans < d[i])
			ans = d[i];
	}

	cout << ans << '\n';
}