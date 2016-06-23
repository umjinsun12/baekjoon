#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int a[10001];

int main()
{
	long long int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}

	

	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}