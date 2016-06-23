#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);

	for(int i=1; i<=n ; i++)
		a[i-1] = i;
	
	sort(a.begin(),a.end());

	do{
		for(int i=0 ; i<a.size(); i++)
			cout << a[i] << " ";
		cout << '\n';
	}while(next_permutation(a.begin(),a.end()));

}