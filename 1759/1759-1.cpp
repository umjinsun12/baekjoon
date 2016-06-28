#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool chk(string &passwd)
{
	int m=0;
	int j=0;
	for(int i=0; i < passwd.size() ; i++)
	{
		if(passwd[i] == 'a' || passwd[i] == 'e' || passwd[i] == 'u' || passwd[i] == 'i' || passwd[i] == 'o')
			m++;
		else
			j++;
	}
	return m>=1 && j>=2;
}

void go(int n, vector<char> &alpha, string passwd, int i)
{
	if(passwd.size() == n)
	{
		if(chk(passwd))
			cout << passwd << '\n';
		return;
	}

	if(i >= alpha.size()) return;
	go(n, alpha, passwd+alpha[i], i+1);
	go(n, alpha, passwd, i+1);
}

int main()
{
	int l, c;
	cin >> l >> c;

	vector <char> alpha;
	for(int i=0; i < c ; i++)
	{
		char a;
		cin >> a;
		alpha.push_back(a);
	}

	sort(alpha.begin(), alpha.end());

	string passwd = "";
	go(l, alpha, passwd, 0);
}