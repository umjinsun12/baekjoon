#include <iostream>
#include <algorithm>
using namespace std;

int a[301];
int d[301][3];

int main()
{
	int n;
	cin >> n;

	for(int i=1 ; i <= n ; i++)
		cin >> a[i];


	for(int i=1 ; i <= n ; i++)
	{
			d[i][2] = max(a[i] + d[i-1][1],d[i][2]);
			d[i][1] = max(a[i] + d[i-2][2],d[i][1]);
			d[i][1] = max(a[i] + d[i-2][1],d[i][1]);
	}

	cout << max(d[n][1],d[n][2]) << '\n';
}
