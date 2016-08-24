#include <iostream>
#include <string.h>
using namespace std;

int a[21];
int d[10001];

int main()
{
    int t;
    cin >> t;

    for(int tc=0 ; tc < t ; tc++)
    {
      int n;
      cin >> n;
      for(int i=0 ; i < n ; i++)
        cin >> a[i];

      memset(d,0,sizeof(d));
      d[0] = 1;
      int m;
      cin >> m;
      for(int i=0 ; i < n ; i++)
      {
        for(int j=a[i] ; j <= m ; j++)
        {
            d[j] += d[j-a[i]];
        }
      }

      cout << d[m] << '\n';
    }

}
