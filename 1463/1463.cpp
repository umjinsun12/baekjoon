#include <iostream>
#include <algorithm>
using namespace std;

int ans;
int a,b,c;
int d[1000000];


int go(int n)
{
	if(n==1)
		return 0;

	if(d[n] > 0)
		return d[n];

	d[n] = go(n-1)+1;

	if(n%3==0)
		d[n] = min(d[n],go(n/3)+1);

	if(n%2==0)
		d[n] = min(d[n],go(n/2)+1);

	return d[n];
}


int main()
{
	int n;
	cin >> n;

	cout << go(n) << '\n';
}