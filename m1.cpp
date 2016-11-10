#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> a[1001];
int d[1001];

void dfs(int start)
{
  if(d[start] > 0) return;

  d[start] = 1;

  for(int i= 0 ; i < a[start].size() ; i++)
  {
    int y = a[start][i];
    if(d[y] == 0)
    {
        cout << y << " ";
        dfs(y);
    }
  }
}

void bfs(int start)
{
  queue <int> q;
  q.push(start);

  d[start] = 1;

  while(!q.empty())
  {
      int x = q.front();
      q.pop();

      cout << x << " ";

      for(int i=0 ; i < a[x].size() ;i++)
      {
        int y = a[x][i];
        if(d[y] == 0)
        {
          d[y] = 1;
          q.push(y);
        }
      }
  }
}

int main()
{
  int n, m ,v;
  cin >> n >> m >> v;

  for(int i= 0 ; i < m ; i++)
  {
    int x,y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  for(int i= 0 ; i <= n ; i++)
  {
    sort(a[i].begin(), a[i].end());
  }

  cout << v << " ";
  dfs(v);

  cout << '\n';

  memset(d,0,sizeof(d));

  bfs(v);

}
