#include <iostream>
using namespace std;

int ans;
int n,s;
int num[20];
int chk[20];

void go(int idx, int cnt)
{
	if(idx == n)
	{
		int sum = 0;
		for(int i=0; i < n ; i++)
		{
			if(chk[i] == true)
				sum += num[i];
		}


		if(sum == s && cnt!=0)
			ans++;

		return;
	}

	chk[idx] = true;
	go(idx+1,cnt+1);
	chk[idx] = false;
	go(idx+1,cnt);
}

int main()
{
	cin >> n >> s;
	for(int i=0; i < n ; i++)
	{
		int tmp;
		cin >> tmp;
		num[i] = tmp;
	}

	ans=0;
	go(0,0);

	cout << ans << '\n';
}