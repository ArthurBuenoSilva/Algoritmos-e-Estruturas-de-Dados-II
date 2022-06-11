#include <iostream>
#include <cstring>
#include <list>

using namespace std;

void exibir(list<int> lista, string nome)
{
	cout << nome << ": ";
	
	for(list<int>::iterator p = lista.begin(); p != lista.end(); p++)
	{
		cout << *p << " ";
	}
	
	cout << endl;
}

int main()
{
	list<int> estoque;
	list<int> venda;

	int n = 0;
	int count = 0;
	int aux = 0;
	int cod = 0;
	
	cin >> n;

	while(count < n)
	{
		cin >> aux;

		switch(aux)
		{
			case 1:
			{
				cin >> cod;
				estoque.push_back(cod);
				
				break;
			}
			case 2:
			{
				venda.push_front(*estoque.begin());
				estoque.pop_front();
				break;
			}
		}
		
		count++;
	}
	
	exibir(estoque, "Estoque");
	
	exibir(venda, "Venda");

	return 0;
}
