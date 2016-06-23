#include <iostream>
#include <vector>
using namespace std;

long long int fac[21];
int c[21];

int main()
{
	fac[0] = 1;
	for(int i=1; i < 21 ; i++)
	{
		fac[i] = i*fac[i-1];
	}

	int n;
	cin >> n;
	int m;
	cin >> m;
	if(m==1)
	{
		long long int k;
		cin >> k;

		vector <int> a;

		for(int i=0; i < n ; i++)
		{
			for(int j=1; j <= n ; j++)
			{
				if(c[j] == true)
					continue;

				if(fac[n-i-1] < k)
					k -= fac[n-i-1];
				else
				{
					a.push_back(j);
					c[j] = true;
					break;
				}
			}
		}

		for(int i=0; i < a.size() ; i++)
			cout << a[i] << " ";

		cout << '\n';
	}
	else if(m==2)
	{
		vector <int> a(n);
		for(int i=0; i<n ; i++)
			cin >> a[i];

		long long int cnt = 0;
		for(int i=0; i < n ; i++)
		{
			for(int j = 1 ; j < a[i] ; j++)
			{
				if(c[j]==false)
					cnt += fac[n-i-1];
			}
			c[a[i]] = true;
		}

		cout << cnt+1 << '\n';
	}
}