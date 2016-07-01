#include <iostream>
using namespace std;

int a[15][15];
int ans;
int n;


bool chk(int row, int col)
{
	for(int i=0; i< n ; i++)
	{
		if(i==row)
			continue;
		if(a[i][col])
			return false;
	}
	
	int x = row - 1;
	int y = col - 1;
	while(x >= 0 && y >=0 )
	{
		if(a[x][y])
			return false;
		x--;
		y--;
	}

	x = row - 1;
	y = col + 1;
	while(x >= 0 && y < n)
	{
		if(a[x][y])
			return false;
		x--;
		y++;
	}

	return true;
}

void calc(int row)
{
	if(row == n)
		ans++;

	for(int col=0; col < n ; col++)
	{
		a[row][col] = 1;
		if(chk(row,col))
			calc(row+1);
		a[row][col] = 0;
	}
}

int main()
{
	cin >> n;
	calc(0);
	cout << ans << '\n';
}