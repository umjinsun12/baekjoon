#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct xy {
	int x;
	int y;
};

struct planet
{
	int x;
	int y;
	int r;
};

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		xy start;
		xy finish;
		scanf("%d %d %d %d", &start.x, &start.y, &finish.x, &finish.y);

		int n;
		int c=0;
		struct planet planet_arr[50];
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d %d %d", &planet_arr[c].x, &planet_arr[c].y, &planet_arr[c].r);
			c++;
		}

		int cnt = 0;
		for (int i = 0; i < c; i++)
		{
			int sd = (planet_arr[i].x - start.x)*(planet_arr[i].x - start.x) + (planet_arr[i].y - start.y)*(planet_arr[i].y - start.y);
			int fd = (planet_arr[i].x - finish.x)*(planet_arr[i].x - finish.x) + (planet_arr[i].y - finish.y)*(planet_arr[i].y - finish.y);
			int r = planet_arr[i].r;

			if(sd >= r*r || fd >= r*r)
			{
				if (sd < r*r)
					cnt++;
				if (fd < r*r)
					cnt++;
			}
		}
	
		printf("%d\n", cnt);
	}
}