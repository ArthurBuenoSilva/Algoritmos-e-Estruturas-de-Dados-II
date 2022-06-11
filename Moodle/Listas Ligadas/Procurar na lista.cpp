#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, float x)
{
	for(list<int>::iterator p = lista.begin(); p != lista.end(); p++)
	{
		if(*p == x)
			return true;
	}
	
	return false;
}

int main()
{
	list<int> lista;

	int x = 0;
	int n = 0;

	cin >> x;

	while(x != 0)
	{
		lista.push_back(x);
		cin >> x;
	}

	cin >> n;

	if(encontrar(lista, n))
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;

	return 0;
}
