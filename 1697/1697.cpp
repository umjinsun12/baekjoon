#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, k;
#define MAX 200001
int dis[200001];



void bfs(int start)
{
	for(int i=0; i< 200001; i++)
		dis[i] = -1;

	queue <int> q;
	q.push(start);
	int cnt=0;
	dis[start] =  cnt;
	cnt++;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		if(x-1 < MAX && x-1 >= 0)
		{
			if(dis[x-1]==-1)
			{
				dis[x-1] = dis[x] + 1;
				q.push(x-1);
			}
		}

		if(x+1 < MAX && x+1 >= 0)
		{
			if(dis[x+1]==-1)
			{
				dis[x+1] = dis[x] + 1;
				q.push(x+1);
			}
		}

		if(2*x < MAX && 2*x >= 0 )
		{
			if(dis[2*x]==-1)
			{
				dis[2*x] = dis[x] + 1;
				q.push(2*x);
			}
		}

	}
}

int main(){

	cin >> n >> k;
	
	bfs(n);

	cout << dis[k] << '\n';
}