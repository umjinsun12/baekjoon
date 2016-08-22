#include <iostream>
#include <algorithm>
using namespace std;

int d[100001];

int main()
{
  int n;
  cin >> n;

  d[0] = 0;
  for(int i=1 ; i <= n ; i++)
  {
    d[i] = d[i-1] + 1;
    for(int j=1 ; j*j <= i ; j++)
    {
        d[i] = min(d[i-j*j] + 1,d[i]);
    }
  }

  cout << d[n] <<'\n';
}
