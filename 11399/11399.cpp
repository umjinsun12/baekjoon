#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];

int main()
{
	int n;
	cin >> n;
	for(int i=0 ; i < n ; i++)
	{
		cin >> a[i];
	}

	sort(a,a+n);

	int sum = 0;
	for(int i=0 ; i < n ; i++)
	{
		for(int j=i ; j >= 0 ; j--)
			sum += a[j];
	}

	cout << sum <<'\n';

}