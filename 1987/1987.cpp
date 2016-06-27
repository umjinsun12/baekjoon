#include <iostream>
using namespace std;

char map[20][20];
int chk[26];
int r,c;
int ans;

void dfs(int x, int y, int k)
{
	if(x >= r || x < 0 || y >= c || y < 0)
		return;
	if(chk[map[x][y]-'A'] == 0)
	{
		chk[map[x][y]-'A'] = 1;

		if(ans < k)
			ans = k;

		dfs(x-1, y, k+1);
		dfs(x+1, y, k+1);
		dfs(x, y-1, k+1);
		dfs(x, y+1, k+1);

		chk[map[x][y]-'A'] = 0;
	}
}

int main()
{
	cin >> r >> c;
	for(int i=0 ;i < r ; i++)
	{
		for(int j=0 ; j < c ; j++)
			cin >> map[i][j];
	}

	dfs(0,0,1);

	cout << ans << '\n';
}