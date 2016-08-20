#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	int a = n;
	while (1)
	{
		int new_num = (a % 10) * 10 + (a % 10 + a / 10) % 10;
		cnt++;
		if (new_num == n)
			break;
		a = new_num;
	}
	cout << cnt << '\n';
}