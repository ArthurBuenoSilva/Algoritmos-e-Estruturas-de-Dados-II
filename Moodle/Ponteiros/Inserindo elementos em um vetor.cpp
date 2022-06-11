#include <iostream>

using namespace std;

int main()
{
	int *p = NULL;
	int tam = 0;
	int v[100];

	cin >> tam;

	p = v;

	for(int i = 0; i < tam; i++)
	{
		cin >> p[i];
	}
	
	for(int i = 0; i < tam; i++)
	{
		cout << p[i] << " ";
	}
	
	return 0;
}
