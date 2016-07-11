#include <iostream>
#include <queue>
using namespace std;

int a[1000][1000];
int d[1000][1000];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
	int m,n;
	cin >> m >> n;

	queue <pair<int,int> > q;

	for(int i=0 ; i < n ; i++)
	{
		for(int j=0; j < m ; j++)
		{
			cin >> a[i][j];
			d[i][j] = -1;
			if(a[i][j] == 1)
			{
				d[i][j] = 0;
				q.push(make_pair(i,j));
			}
		}
	}


	while(!q.empty())
	{
		pair<int,int> now = q.front();
		q.pop();

		for(int i=0; i < 4 ; i++)
		{
			int x = now.first + dx[i];
			int y = now.second + dy[i];

			if(x >= 0 && x < n && y >= 0 && y < m)
			{
				if(a[x][y]==0 && d[x][y]==-1)
				{
					q.push(make_pair(x,y));
					d[x][y] = d[now.first][now.second] + 1;
				}
			}
		}
	}

	int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (ans < d[i][j]) {
                ans = d[i][j];
            }
        }
    }

	for(int i=0; i < n ;i++)
	{
		for(int j=0; j < m ; j++)
		{
			if(d[i][j] == -1 && a[i][j] == 0)
				ans = -1;
		}
	}

	cout << ans << '\n';
	return 0;
}