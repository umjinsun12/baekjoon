#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int door[21];
int d[21][21][21];
int n;

int go(int i, int door1, int door2){
  if(i==n)
    return 0;

  int &ans = d[i][door1][door2];
  if(ans != -1)
    return ans;

  ans = min(go(i+1, door[i],door2) + abs(door[i]-door1),
            go(i+1, door1,door[i]) + abs(door[i]-door2));
  return ans;
}

int main()
{

    cin >> n;

    int door1,door2;
    cin >> door1 >> door2;

    cin >> n;
    for(int i=0 ; i < n ; i++)
      cin >> door[i];

    memset(d,-1,sizeof(d));
    cout << go(0, door1, door2) <<'\n';
}
