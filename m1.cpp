#include <iostream>
#include <cmath>
using namespace std;

int a[10];
int n;

int go()
{
	int sum=0;
	for(int i=1 ; i < n ; i++)
	{
		sum += abs(a[i] - a[i-1]);
	}
	return sum;
}

int main()
{
	
	cin >> n;
	for(int i=0; i<n ; i++)
	{
		cin >> a[i];
	}

	
}