#include <iostream>
#include <algorithm>
using namespace std;

int a[501][501];
int d[501][501];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++)
			cin >> a[i][j];
	}

	d[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == i) {
				d[i][j] = d[i - 1][j - 1] + a[i][j];
			}
			else if (j == 0) {
				d[i][j] = d[i - 1][j] + a[i][j];
			}
			else {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + a[i][j];
			}
		}
	}


	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (ans < d[n - 1][i])
			ans = d[n - 1][i];
	}
