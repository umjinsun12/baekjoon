#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector < pair<int,int> > a[1001];
int c[1001];

int main()
{
  int n,m;
  cin >> n >> m;
  for(int i= 0 ; i < m ; i++)
  {
    int x,y,w;
    cin >> x >> y >> w;
    a[x].push_back(make_pair(y,w));
    a[y].push_back(make_pair(x,w));
  }

  c[1] = 1;
  priority_queue < pair<int,int> > q;
  for(int i=0 ; i < a[1].size(); i++)
  {
    q.push(make_pair(-a[1][i].second,a[1][i].first));
  }

  int ans=0;
  while(!q.empty())
  {
    pair<int,int> now = q.top();
    q.pop();
    if(c[now.second] > 0)
      continue;
    c[now.second] = true;
    ans += -now.first;
    for(int i= 0 ; i < a[now.second].size() ; i++)
    {
      pair<int,int> next = a[now.second][i];
      q.push(make_pair(-next.second,next.first));
    }
  }

  cout << ans <<'\n';
}
