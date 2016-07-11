#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[25][25];
int d[25][25];

int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0,1,-1};

int main()
{
	scanf("%d",&n);

	for(int i=0; i < n ; i++)
	{
		for(int j=0; j < n ; j++)
			scanf("%1d",&a[i][j]);
	}

	int cnt = 1;
	vector <int> ans;

	for(int i=0; i < n ; i++)
	{
		for(int j=0; j < n ; j++)
		{
			if(a[i][j] == 0)
				continue;

			if(d[i][j] > 0)
				continue;

			queue < pair <int,int> > q;
			int anscnt = 0;
			q.push(make_pair(i,j));
			d[i][j] = cnt;
			anscnt++;

			while(!q.empty())
			{
				pair <int, int> now = q.front();
				q.pop();

				for(int k=0; k < 4 ; k++)
				{
					int x = now.first + dx[k];
					int y = now.second + dy[k];
					if(x >= 0 && x < n && y >= 0 && y < n)
					{
						if(a[x][y]!=0 && d[x][y] == 0)
						{
							q.push(make_pair(x,y));
							d[x][y] = cnt;
							anscnt++;
						}
					}

				}
			}
			cnt++;
			ans.push_back(anscnt);
		}
	}

	sort(ans.begin(),ans.end());

	printf("%lu\n",ans.size());

	for(int i=0; i < ans.size() ; i++)
		printf("%d\n",ans[i]);
}
