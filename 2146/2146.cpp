#include <iostream>
#include <queue>
using namespace std;

int a[100][100];
int d[100][100];

int dist[100][100];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
	int n;
	cin >> n;
	for(int i=0; i < n ; i++)
	{
		for(int j=0; j < n ; j++)
		{
			cin >> a[i][j];
		}
	}

	
	int color=1;
	for(int i=0; i< n ; i++)
	{
		for(int j=0; j < n ; j++)
		{
			if(a[i][j] == 0)
				continue;
			if(d[i][j] > 0)
				continue;

			d[i][j] = color;
			queue < pair<int,int> > q;
			q.push(make_pair(i,j));

			while(!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for(int k=0; k < 4 ; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];

					if(nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						if(d[nx][ny]==0 && a[nx][ny]==1)
						{
							q.push(make_pair(nx,ny));
							d[nx][ny] = color;
						}
					}
				}
			}
			color++;
		}
	}




	queue < pair<int,int> > q;
	for(int i=0; i < n ; i++)
	{
		for(int j=0; j < n ; j++)
		{
			if(d[i][j] > 0)
				q.push(make_pair(i,j));
		}
	}

	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0; i < 4 ; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx>=0 && nx < n && ny >= 0 && ny < n)
			{
				if(d[nx][ny]==0)
				{
					d[nx][ny] = d[x][y];
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}

	int ans = 1000000;
	for(int i=0 ; i < n ; i++)
	{
		for(int j=0; j < n ; j++)
		{

			for(int k=0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if(nx>=0 && nx < n && ny >= 0 && ny < n)
				{
					if(d[nx][ny] != d[i][j])
					{
						if(ans > dist[i][j]+dist[nx][ny])
							ans = dist[i][j]+dist[nx][ny];
					}
				}
			}

		}
	}

	cout << ans << '\n';
}