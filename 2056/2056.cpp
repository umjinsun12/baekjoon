#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> a[10001];
int weight[10001];
int d[10001];
int ind[10001];

int main()
{
  int n;
  cin >> n;
  for(int i=1; i <= n ;i++)
  {
    int w;
    cin >> w;
    weight[i] = w;

    int t;
    cin >> t;
    for(int j=0; j < t ; j++)
    {
      int x;
      cin >> x;
      a[x].push_back(i);
      ind[i]++;
    }
  }

  queue <int> q;
  for(int i=1; i<=n ; i++)
  {
    if(ind[i]==0)
    {
      q.push(i);
      d[i] = weight[i];
    }
  }

  while(!q.empty())
  {
    int x = q.front();
    q.pop();
    for(int i=0 ; i<a[x].size() ; i++)
    {
      int y = a[x][i];
      ind[y]--;
      if(d[y] < d[x] + weight[y])
        d[y] = d[x] + weight[y];
      if(ind[y]==0)
        q.push(y);
    }
  }

  int ans=0;
  for(int i=1 ; i<=n ;i++)
  {
    if(ans < d[i])
      ans = d[i];
  }
  cout << ans << '\n';
}
