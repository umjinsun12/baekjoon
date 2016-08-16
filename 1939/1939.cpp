#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int start, fin;
vector < pair<int, int> > a[10001];
int chk[10001];

bool possible(int x, int mid)
{
	queue <int> q;
	q.push(x);
	chk[x] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == fin)
			return true;
		for (int i = 0; i < a[now].size(); i++)
		{
			int next = a[now][i].first;
			int next_weight = a[now][i].second;
			if (chk[next] == 0 && next_weight >= mid)
			{
				chk[next] = 1;
				q.push(next);
			}
		}
	}
	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
		a[v].push_back(make_pair(u, w));
	}


	cin >> start >> fin;

	int l = 1;
	int r = 1000000000;
	int ans = 0;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		memset(chk, 0, sizeof(chk));
		if (possible(start, mid)) {
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;

	}

	cout << ans << '\n';
}