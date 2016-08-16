#include <iostream>
#include <algorithm>
using namespace std;

int a[200001];
int n, c;

bool possible(int c, int mid){
  int cnt = 1;
  int last = a[0];
  for(int i=0; i < n ; i++)
  {
    if(a[i] - last >= mid){
      cnt++;
      last = a[i];
    }
  }

  return cnt >= c;
}


int main()
{

  cin >> n >> c;

  for(int i=0 ; i < n ; i++)
    cin >> a[i];

  sort(a, a+n);

  int l = 1;
  int r = a[n-1] - a[0];

  int ans = l;
  while(l <= r)
  {
    int mid = (l+r)/2;
    if(possible(c,mid)){
      if(ans < mid){
        ans = mid;
      }
      l = mid + 1;
    }
    else{
      r = mid - 1;
    }
  }

  cout << ans <<'\n';
  return 0;
}
