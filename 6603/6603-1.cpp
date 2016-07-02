#include <iostream>
#include <vector>
using namespace std;

int size;
int a[50];
int chk[50];

void go(int index, int cnt)
{
	if(index==size && cnt == 6)
	{
		for(int i=0; i < size; i++)
		{
			if(chk[i] == 1)
				cout << a[i] << " ";
		}
		cout << '\n';
		return ;
	}

	if(index > size)
		return;

	if(chk[index] > 0)
		return;

	chk[index] = true;
	go(index+1, cnt+1);
	chk[index] = false;
	go(index+1, cnt);

	return;
}



int main()
{
	while(1)
	{
	cin >> size;
	if(size==0)
		break;

	for(int i=0; i < size; i++)
	{
		int tmp;
			cin >> tmp;
			a[i] = tmp;
		}

		go(0,0);
		cout << '\n';
	}

}