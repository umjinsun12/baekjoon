#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int a1[8];
int b1[8];

int add()
{
	int a=0,b=0;
	for(int i=0; i < 8 ; i++)
	{
		if(a1[i] != 0)
			a +=  a1[i]*pow(10,i);
		if(b1[i] != 0)
			b +=  b1[i]*pow(10,i);
	}

	return a+b;
}

int main()
{
	int a,b;
	cin >> a >> b;

	for(int i=0; i < 8 ; i++)
	{
		a1[i] = a%10;
		b1[i] = b%10;
		a/=10;
		b/=10;

	}

	for(int i=0; i < 8 ; i++)
	{
		if(a1[i] == 6)
			a1[i] = 5;

		if(b1[i] == 6)
			b1[i] = 5;
	}

	cout << add() << " ";

	for(int i=0; i < 8 ; i++)
	{
		if(a1[i] == 5)
			a1[i] = 6;

		if(b1[i] == 5)
			b1[i] = 6;
	}

	cout << add() << '\n';
}