#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> a[501];
int weight[501];
int ind[501];
int d[501];

int main()
{
  int n;
  cin >> n;
  for(int i=1; i<=n ; i++)
  {
    cin >> weight[i];
    int x;
    while(1)
    {
      cin >> x;
      if(x==-1)
        break;
      else
      {
        a[x].push_back(i);
        ind[i]++;
      }
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
    for(int i=0 ; i < a[x].size(); i++)
    {
      int y = a[x][i];
      ind[y]--;
      if(d[y] < d[x] + weight[y])
        d[y] = d[x] + weight[y];
      if(ind[y]==0)
        q.push(y);
    }
  }

  for(int i=1 ; i<=n ; i++)
    cout << d[i] << '\n';
}
