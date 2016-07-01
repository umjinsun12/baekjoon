#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

struct point{
	int x;
	int y;
};

int a[9][9];
point blank[81];
int pn;


bool check(int x, int y)
{
	for(int i=0; i < 9 ; i++)
	{
		if(i==x)
			continue;

		if(a[i][y] == a[x][y])
			return false;
	}

	for(int i=0; i < 9 ; i++)
	{
		if(i==y)
			continue;

		if(a[x][i] == a[x][y])
			return false;
	}

	int p = x/3;
	int q = y/3;

	for(int i=0; i < 9 ; i++)
	{
		for(int j=0; j < 9 ; j++)
		{
			if(p == i/3 && q == j/3)
			{
				if(i==x && j==y)
					continue;

				if(a[x][y] == a[i][j])
					return false;
			}
		}
	}

	return true;


}

void go(int n)
{
	if(n==pn)
	{
		for(int i=0; i < 9 ; i++)
		{
			for(int j=0; j < 9 ; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << '\n';
		}

		exit(0);
	}

	for(int i=1; i<=9 ; i++)
	{
		a[blank[n].x][blank[n].y] = i;
		if(check(blank[n].x, blank[n].y))
			go(n+1);
		a[blank[n].x][blank[n].y] = 0;
	}
}


int main()
{
	for(int i=0 ; i < 9 ; i++)
	{
		for(int j=0; j < 9 ; j++)
		{
			cin >> a[i][j];
			if(a[i][j]==0)
			{
				point tmp;
				tmp.x = i;
				tmp.y = j;
				blank[pn++] = tmp;
			}

		}
	}
	go(0);

}