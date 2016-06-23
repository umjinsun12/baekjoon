#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector <int> a;

int go(int n)
{
	int sum=0;
	for(int i=1; i<a.size() ; i++)
	{
		sum += abs(a[i] - a[i-1]);
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i < n ; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	sort(a.begin(),a.end());

	int ans = 0;

	do{
		int tmp = go(n);
		if(tmp > ans)
			ans = tmp;
	}while(next_permutation(a.begin(),a.end()));

	cout << ans << '\n';
}