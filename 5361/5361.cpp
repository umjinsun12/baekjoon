#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >>t;
  for(int tc= 0 ; tc < t ; tc++)
  {
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    printf("$%.2f\n",350.34*a+230.90*b+190.55*c+125.30*d+180.90*e);
  }
}
