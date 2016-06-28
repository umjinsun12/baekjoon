#include <iostream>
using namespace std;

int n;
int ans;
bool a[15][15];

int chk_col[15];
int chk_dig1[31];
int chk_dig2[31];

bool chk(int row, int col)
{
	if(chk_col[col])
		return false;
	if(chk_dig1[row+col])
		return false;
	if(chk_dig2[row-col+n-1])
		return false;
	return true;
}


void calc(int row)
{
	if(row == n)
	{
		ans++;
		return;
	}

	for(int col = 0 ; col < n ; col++)
	{
		if(chk(row,col))
		{
			chk_col[col] = true;
			chk_dig1[row+col] = true;
			chk_dig2[row-col+n-1] = true;
			a[row][col] = true;
			calc(row+1);
			chk_col[col] = false;
			chk_dig1[row+col] = false;
			chk_dig2[row-col+n-1] = false;
			a[row][col] = false;
		}
	}
}


int main()
{
	cin >> n;

	calc(0);

	cout << ans << '\n';
}