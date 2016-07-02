#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char a[200];

int main()
{
	int m;
	scanf("%d",&m);
	int n = 20;
	int s;

	for(int tc=0; tc < m ; tc++)
	{
		scanf("%s",a);

		if(!strcmp(a,"all"))
			s = (1<<n) - 1;
		else if(!strcmp(a,"empty"))
			s = 0;
		else
		{
			int x;
			scanf("%d",&x);
			x--;

			if(!strcmp(a,"add"))	
				s = (s | (1<<x));
			else if(!strcmp(a,"remove"))
				s = (s & ~(1<<x));
			else if(!strcmp(a,"check"))
			{
				int res = (s & (1<<x));
				if(res)
					printf("1\n");
				else
					printf("0\n");
			}
			else if(!strcmp(a,"toggle"))
				s = (s ^ (1<<x));
		}
	}
}