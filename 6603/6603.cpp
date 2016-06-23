#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	while(1)
	{
		int n;
		cin >> n;

		if(n==0)
			break;
		
		vector <int> a(n);
		vector <int> b(n);
		vector < vector <int> > c;

		for(int i=0 ; i < n ; i++)
		{
			cin >> a[i];
			if(i>=n-6)
				b[i] = 1;
			else
				b[i] = 0;
		}


		do
		{
			vector<int> current;
			for(int i=0; i< n ; i++)
			{
				if(b[i]==1)
					current.push_back(a[i]);
			}
			c.push_back(current);
		}while(next_permutation(b.begin(),b.end()));

		reverse(c.begin(),c.end());

		for(int i=0 ; i<c.size() ; i++)
		{
			for(int j=0 ; j<c[i].size() ; j++)
			{
				cout << c[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
	}
}