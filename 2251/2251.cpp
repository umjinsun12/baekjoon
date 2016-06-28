#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct bot{
	int a;
	int b;
};

int chk[201][201];
int cur[3];
int ans[201];
int mbot[3];

int main()
{
	cin >> mbot[0] >> mbot[1] >> mbot[2];

	queue <bot> q;
	bot start;
	start.a = 0;
	start.b = 0;
	chk[0][0] = 1;
	q.push(start);

	while(!q.empty())
	{
		bot now = q.front();
		q.pop();

		
		for(int i=0 ; i < 3 ; i++)
		{
			for(int j=0 ; j < 3 ; j++)
			{
				cur[0] = now.a;
				cur[1] = now.b;
				cur[2] = mbot[2] - now.a - now.b;

				if(i==j || cur[i]==0)
					continue;

				//i->j
				if(cur[i]+cur[j] > mbot[j])
				{
					cur[i] = cur[i] - (mbot[j] - cur[j]);
					cur[j] = mbot[j];
				}
				else if(cur[i]+cur[j] <= mbot[j])
				{
					cur[j] = cur[i]+cur[j];
					cur[i] = 0;
				}

				if(chk[cur[0]][cur[1]] == 0)
				{
					chk[cur[0]][cur[1]] = 1;
					bot next;
					next.a = cur[0];
					next.b = cur[1];
					q.push(next);
				}
			}
		}
	}

	memset(ans,-1,sizeof(ans));

	
	for(int j=0; j <= mbot[1] ; j++)
	{
		if(chk[0][j] != 0)
			ans[mbot[2] - j] = 1;
	}
	

	for(int i=0; i <= mbot[2]; i++)
	{
		if(ans[i] != -1)
			cout << i << " ";
	}
	cout << '\n';
}