#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector <int> a[1001];
int chk[1001];
int ans;

void dfs(int start)
{
	chk[start] = true;
	for(int i=0 ; i < a[start].size() ; i++)
	{
		int y = a[start][i];
		if(chk[y]==0)
			dfs(y);
	}
}


int main()
{
	cin >> n >> m;

	for(int i=0; i < m ; i++)
	{
		int u,v;
		cin >> u >> v;

		a[u].push_back(v);
		a[v].push_back(u);
	}


	for(int i=1; i <= n; i++)
	{
		if(chk[i]==false)
		{
			dfs(i);
			ans++;
		}
	}

	cout << ans << '\n';

}