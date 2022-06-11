#include <iostream>

using namespace std;

int main()
{
	int *p = NULL;
	int tam = 0;
	int v[100];
	
	float m = 0;

	cin >> tam;

	p = v;

	for(int i = 0; i < tam; i++)
	{
		cin >> p[i];
	}
	
	for(int i = 0; i < tam; i++)
	{
		m += p[i];
	}
	
	cout << m / tam;
	
	return 0;
}
