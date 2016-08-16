#include <iostream>
using namespace std;

int a[1001];
int d[1001];

int main ()
{
	int n;
	cin >> n;
	for(int i=1; i <= n ; i++)
		cin >> a[i];

	d[0] = 1;
	d[1] = 1;

	for(int i=1; i <= n ; i++)
	{
		for(int j=i-1 i<=)
	}

	int ans = 0;
	for(int i=1 ; i <= n ; i++)
	{
		if(ans < d[i])
			ans = d[i];
	}

	cout << ans << '\n';
}