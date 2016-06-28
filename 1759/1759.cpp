#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int l,c;
	cin >> l >> c;
	char a;
	vector <char> list;
	vector <int> v;

	for(int i=0; i < c ; i++)
	{
		cin >> a;
		list.push_back(a);
	}

	sort(list.begin(),list.end());


	for(int i=0; i < l ; i++)
		v.push_back(0);

	for(int i=0; i < c-l ; i++)
		v.push_back(1);

	do
	{
		int m=0;
		int j=0;
		bool ok = false;
		for(int i=0; i < c ; i++)
		{
			if(v[i] == 0)
			{
				if(list[i] == 'a' || list[i] == 'e' || list[i] == 'o' || list[i] == 'u' || list[i] =='i')
					m++;
				else
					j++;
			}
		}

		if(m >= 1 && j>=2)
			ok = true;
		if(ok)
		{
			for(int i=0; i < c ; i++)
			{
				if(v[i] == 0)
					cout << list[i];
			}
			cout << '\n';
		}
		
	}while(next_permutation(v.begin(),v.end()));
}