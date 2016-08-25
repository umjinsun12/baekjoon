#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector < pair<int,int> > a[10001];
int c[10001];

int main()
{
  int n,m;
  cin >> n >> m;
  for(int i=0 ; i < m ; i++)
  {
    int s,e,w;
    cin >> s >> e >> w;
    a[s].push_back(make_pair(e,w));
    a[e].push_back(make_pair(s,w));
  }

  c[1] = 1;
  priority_queue < pair <int,int> > q;
  for(int i=0 ; i < a[1].size() ; i++)
  {
    q.push(make_pair(-a[1][i].second, a[1][i].first));
  }

  int ans=0;
  while(!q.empty()){
    pair <int, int> now = q.top();
    q.pop();
    if(c[now.second] > 0)
      continue;
    c[now.second] = 1;
    ans += -now.first;
    int x = now.second;
    for(int i=0 ; i < a[x].size() ; i++)
    {
      pair <int, int> next = a[x][i];
      q.push(make_pair(-next.second,next.first));
    }
  }

  cout << ans <<'\n';
}
