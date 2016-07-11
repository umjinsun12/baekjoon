#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int a[100][100];
int d[100][100];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
	int n,m;
	scanf("%d %d",&n, &m);

	for(int i=0; i < n ; i++)
	{
		for(int j=0; j < m ; j++)
		{
			scanf("%1d",&a[i][j]);
			d[i][j] = 0;
		}
	}

	queue < pair<int,int> > q;
	q.push(make_pair(0,0));
	d[0][0] = 1;

	while(!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for(int i=0; i < 4 ; i++)
		{
			int x = now.first + dx[i];
			int y = now.second + dy[i];

			if(x>=0 && x < n && y >=0 && y < m)
			{
				if(a[x][y] !=0 && d[x][y] == 0)
				{
					q.push(make_pair(x,y));
					d[x][y] = d[now.first][now.second] + 1;
				}
			}
		}
	}

	cout << d[n-1][m-1] << '\n';

}