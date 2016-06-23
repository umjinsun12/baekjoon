#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> a(n);
	for(int i=0 ; i < n ; i++)
	{
		cin >> a[i];
	}

	

	int tmp = next_permutation(a.begin(),a.end());

	for(int i=0 ; i < n ; i++)
	{
		if(!tmp)
		{
			cout << "-1";
			break;
		}
		cout << a[i] << " ";
	}
	cout << "\n";
}