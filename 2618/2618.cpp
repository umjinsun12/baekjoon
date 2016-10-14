#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;

struct pt {
	int x;
	int y;
	pt(int x, int y) : x(x), y(y) {
	}
};


const int inf = 100000000;
int dist[1001][1001];
int dp[1001][1001];
int p[1001][1001];
vector <pt> a;

int main()
{
	int n;
	cin >> n;
	int w;
	cin >> w;
	a.push_back(pt(0, 0));
	for (int i = 0; i < w; i++) {
		int x, y;
		cin >> x >> y;
		a.push_back(pt(x, y));
	}


	for (int i = 0; i <= w; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			dist[i][j] = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
			dp[i][j] = inf;
		}
	}

	dp[0][0] = 0;
	for (int i = 1; i <= w; i++)
	{
		for (int j = 0; j <= i - 1; j++)
		{
			if (j == 0)
				dist[j][i] = abs(a[i].x - 1) + abs(a[i].y - 1);

			if (dp[i][i - 1] > dp[j][i - 1] + dist[j][i]) // 1번 경찰차
			{
				dp[i][i - 1] = dp[j][i - 1] + dist[j][i];
				p[i][i - 1] = j;
			}

			if (dp[i][j] > dp[i - 1][j] + dist[i][i - 1]) {
				dp[i][j] = dp[i - 1][j] + dist[i][i - 1];
				p[i][j] = i - 1;
			}


			if (j == 0)
				dist[j][i] = abs(a[i].x - n) + abs(a[i].y - n);

			if (dp[i - 1][i] > dp[i - 1][j] + dist[j][i]) // 2번 경찰차
			{
				dp[i - 1][i] = dp[i - 1][j] + dist[j][i];
				p[i - 1][i] = j;
			}

			if (dp[j][i] > dp[j][i - 1] + dist[i - 1][i])
			{
				dp[j][i] = dp[j][i - 1] + dist[i - 1][i];
				p[j][i] = i - 1;
			}

		}
	}

	dp[0][0] = inf;
	int ans = inf;
	int x, y;
	for (int i = 0; i <= w; i++) {
		if (dp[w][i] < ans)
		{
			ans = dp[w][i];
			x = w;
			y = i;
		}

		if (dp[i][w] < ans)
		{
			ans = dp[i][w];
			x = i;
			y = w;
		}
	}

	cout << ans << '\n';

	stack <int> s;
	for (int i = 0; i < w; i++)
	{
		int prev = p[x][y];
		if (x > y) {
			s.push(1);
			x = prev;
		}
		else {
			s.push(2);
			y = prev;
		}
	}

	while (!s.empty()) {
		cout << s.top() << '\n';
		s.pop();
	}

	//dp[i][j] = dp[i-1][i] + dist[i-1][i]; or dp[i][j] =
}
