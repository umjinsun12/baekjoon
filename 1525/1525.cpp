#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

int main()
{
	int start = 0;
	for(int i=0; i<9; i++)
	{
		int a;
		cin >> a;
		if(a == 0)
			a = 9;

		start = start * 10 + a;
	}

	map<int,int> dist;
	queue <int> q;
	q.push(start);
	dist[start] = 0;

	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		string s = to_string(now);
		int z = s.find('9');

		int up = z - 3;
		int down = z + 3;
		int left = z%3 - 1;
		int right = z%3 + 1;

		if(up < 9 && up >= 0)
		{	
			string tmp_s = s;
			swap(tmp_s[z],tmp_s[up]);
			int tmp = stoi(tmp_s);

			if(dist.count(tmp) == 0)
			{
				dist[tmp] = dist[now] + 1;
				q.push(tmp);
			}
		}

		if(down < 9 && down >= 0)
		{
			string tmp_s = s;
			swap(tmp_s[z],tmp_s[down]);
			int tmp = stoi(tmp_s);

			if(dist.count(tmp) == 0)
			{
				dist[tmp] = dist[now] + 1;
				q.push(tmp);
			}
		}

		if(left < 3 && left >= 0)
		{
			left = z - 1;
			string tmp_s = s;
			swap(tmp_s[z],tmp_s[left]);
			int tmp = stoi(tmp_s);

			if(dist.count(tmp) == 0)
			{
				dist[tmp] = dist[now] + 1;
				q.push(tmp);
			}
		}

		if(right < 3 && right >= 0)
		{
			right = z + 1;
			string tmp_s = s;
			swap(tmp_s[z],tmp_s[right]);
			int tmp = stoi(tmp_s);

			if(dist.count(tmp) == 0)
			{
				dist[tmp] = dist[now] + 1;
				q.push(tmp);
			}
		}
	}

	if(dist.count(123456789)==0)
		cout << "-1" << '\n';
	else
		cout << dist[123456789] << '\n';

}