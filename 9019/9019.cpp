#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int chk[10001];
char track[10001];
int from[10001];

void bfs(int start)
{
	memset(chk,0,sizeof(chk));
	memset(track, 0 ,sizeof(track));
	memset(from, 0 , sizeof(from));

	queue <int> q;
	q.push(start);
	chk[start] = 1;
	while(!q.empty())
	{
		int x= q.front();
		q.pop();

		int op_d1 = (2*x) % 10000;
		int op_d2 = x-1;
		if(op_d2 < 0)
			op_d2 = 9999;
		int op_d3 = (x%1000)*10 + x/1000;
		int op_d4 = (x/10) + (x%10)*1000;

		if(chk[op_d1] == false)
		{
			chk[op_d1] = true;
			from[op_d1] = x;
			track[op_d1] = 'D';
			q.push(op_d1);
		}

		if(chk[op_d2] == false)
		{
			chk[op_d2] = true;
			from[op_d2] = x;
			track[op_d2] = 'S';
			q.push(op_d2);
		}

		if(chk[op_d3] == false)
		{
			chk[op_d3] = true;
			from[op_d3] = x;
			track[op_d3] = 'L';
			q.push(op_d3);
		}

		if(chk[op_d4] == false)
		{
			chk[op_d4] = true;
			from[op_d4] = x;
			track[op_d4] = 'R';
			q.push(op_d4);
		}
	}
}

void output(int a, int b)
{
	if(a==b) return;
	output(a, from[b]);
	cout << track[b];
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,b;
		cin >> a >> b;

		bfs(a);

		output(a,b);
		cout << '\n';
	}
}