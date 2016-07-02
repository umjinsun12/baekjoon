#include <iostream>
#include <vector>

using namespace std;

vector <int> a[20001];
int chk[20001];
int n,m;

void dfs(int x, int color)
{
	chk[x] = color;

	for(int i=0; i < a[x].size() ; i++)
	{
		int y = a[x][i];
		if(chk[y] == 0){
			dfs(y,3-color);
		}
	}
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i=0; i < m; i++)
		{
			int v,e;
			cin >> v >>e;

			a[v].push_back(e);
			a[e].push_back(v);
		}

		for(int i=1; i <= n; i++)
		{
			if(chk[i] == 0)
			{
				dfs(i, 1);
			}
		}

		bool ok = false;
		for(int i=1; i <=n ; i++)
		{
			for(int k=0; k < a[i].size(); k++)
			{
				int y = a[i][k];
				if(chk[y] == chk[i])
					ok = true;
			}
		}
		

		if(!ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';


		for(int i=0; i <=n ; i++)
		{
			a[i].clear();
			chk[i] = 0;
		}
	}
}