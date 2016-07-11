#include <iostream>
#include <queue>
using namespace std;

int a[50][50];
int d[50][50];

int dx[8] = {1, -1, 0 , 0, 1, -1, 1, -1};
int dy[8] = {0,  0, 1 ,-1, 1, -1, -1, 1};

int main()
{
	while(1)
	{
		int w,h;
		cin >> w >> h;
		if(w == 0 && h==0)
			break;

		for(int i=0 ; i < h ; i++)
		{
			for(int j=0; j < w ; j++)
			{
				cin >> a[i][j];
			}
		}

		
		int cnt = 0;

		for(int i=0 ; i < h ; i++)
		{
			for(int j=0; j < w ; j++)
			{
				if(a[i][j] == 0)
					continue;
				if(d[i][j] > 0)
					continue;

				cnt++;

				d[i][j] = cnt;
				queue < pair<int,int> > q;
				q.push(make_pair(i,j));

				while(!q.empty())
				{
					pair<int, int> now = q.front();
					q.pop();
					for(int k=0; k < 8; k++)
					{
						int x = now.first + dx[k];
						int y = now.second + dy[k];

						if(x >= 0 && x < h && y >= 0 && y < w)
						{
							if(d[x][y] == 0 && a[x][y]!=0)
							{
								q.push(make_pair(x,y));
								d[x][y] = cnt;
							}
						}
					} 
				}
			}
		}

		cout << cnt << '\n';

		for(int i=0 ; i < 50 ; i++)
		{
			for(int j=0; j < 50 ; j++)
			{
				a[i][j] = 0;
				d[i][j] = 0;
			}
		}
	}
}