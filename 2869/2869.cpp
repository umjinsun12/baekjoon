#include <iostream>
using namespace std;

int main()
{
	int a, b, v;
	cin >> a >> b >> v;

	int day = 0;
	int pos = 0;
	while (1)
	{
		pos += a;
		if (pos >= v)
			break;
		pos -= b;
		day++;
	}

	cout << day + 1 << '\n';
}