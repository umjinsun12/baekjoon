#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int c[10000];
int chk[10000];
int cnt[10000];
int path[10000];

void bfs(int start)
{
	for(int i=0; i < 10000; i++)
	{
		chk[i] = false;
		cnt[i] = false;
	}
	queue <int> q;
	q.push(start);
	chk[start] = true;
	cnt[start] = 0;

	while(!q.empty())
	{
		int x = q.front();
		int tmp = x;
		q.pop();

		for(int i=0; i < 4 ; i++)
		{
			int target = x%10;
			for(int j=0; j < 10 ; j++)
			{
				if(target == j)
					continue;

				int y = tmp - target*pow(10,i) + j*pow(10,i);

				if(chk[y] == false && c[y] == false && y >= 1000)
				{
					chk[y] = true;
					cnt[y] = cnt[tmp] + 1;
					path[y] = tmp;
					q.push(y);
				}
			}
			x = x/10;
		}

	}
}


int main()
{
	int n;
	cin >> n;
	vector <int> prime;

	c[1] = false;
	for(int i=2; i < 10000 ; i++)
	{
		if(c[i] == false)
		{
			prime.push_back(i);
			for(int j = i+i; j < 10000 ; j+=i)
			{
				c[j] = true;//소수가 아니면
			}
		}
	}


	for(int i=0; i< n ; i++)
	{
		int a,b;
		cin >> a >> b;

		bfs(a);

		cout << cnt[b] << '\n';
	}

}