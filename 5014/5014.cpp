#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dist[1000001];

int main()
{
	int f,s,g,u,d;
	cin >> f >> s >> g >> u >> d;

	queue <int> q;

	memset(dist, -1, sizeof(dist));

	q.push(s);
	dist[s] = 0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		int next = now + u;
		if(next <= f && next >=1)
		{
			if(dist[next] == -1)
			{
				dist[next] = dist[now] +1;
				q.push(next);
			}
		}

		next = now - d;
		if(next <= f && next >= 1)
		{
			if(dist[next] == -1)
			{
				dist[next] = dist[now] +1;
				q.push(next);
			}
		}
	}

	if(dist[g] == -1)
		cout << "use the stairs\n";
	else
		cout << dist[g] << "\n";
}