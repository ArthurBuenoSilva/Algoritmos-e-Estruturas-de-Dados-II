#include <iostream>

using namespace std;

int main()
{
	int *p = NULL;
	int tam = 0;
	int v[100];
	int m = 0;

	cin >> tam;

	p = v;

	for(int i = 0; i < tam; i++)
	{
		cin >> p[i];
		
		if(i == 0)
			m = p[i];
	}

	for(int i = 0; i < tam; i++)
	{
		if(p[i] > m)
		{
			m = p[i];
		}
	}
	
	cout << m;

	return 0;
}
