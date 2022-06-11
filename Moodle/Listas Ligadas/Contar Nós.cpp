#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista)
{
	int count = 0;
	
	for(list<int>::iterator p = lista.begin(); p != lista.end(); p++)
	{
		count++;
	}
	
	return count;
}

int main()
{
	list<int> lista;

	int x = 0;

	cin >> x;

	while(x != 0)
	{
		lista.push_back(x);
		cin >> x;
	}
	
	cout << contar(lista) << endl;

	return 0;
}
