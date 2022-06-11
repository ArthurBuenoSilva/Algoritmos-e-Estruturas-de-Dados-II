#include <iostream>

using namespace std;

int main()
{
	int *p = NULL;
	int tam = 0;
	int v[100];
	int q = 0;

	cin >> tam;

	p = v;

	for(int i = 0; i < tam; i++)
	{
		cin >> p[i];
	}

	for(int i = 0; i < tam; i++)
	{
		if(p[i] % 2 == 0  && p[i] > 0)
		{
			q++;
		}
	}
	
	cout << q;

	return 0;
}
