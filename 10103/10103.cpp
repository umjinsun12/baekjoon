#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int a=100,b=100;
	for(int i=0; i<n; i++)
	{
		int x, y;
		cin >> x >> y;
		
		if(x>y)
			b -= x;
		else if(x<y)
			a -= y;
	}

	cout << a << '\n';
	cout << b << '\n';
}