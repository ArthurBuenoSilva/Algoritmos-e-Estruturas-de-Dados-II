#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> lista;				//ponteiro para a lista
	list<int>::iterator p;			//Iterador para varrer a lista

	int x = 0;						//Var aux para a leitura dos dados
	int soma = 0;					//Soma dos elementos da lista

	//Inserindo elementos
	cin >> x;
	while(x != 0)
	{
		lista.push_front(x);
		cin >> x;
	}

	//Calculando a soma dos elementos da lista
	for(p = lista.begin(); p != lista.end(); p++)
		soma += *p;
	
	cout << "soma = " << soma << endl;

	//Liberando a memória utilizada pela lista
	while(!lista.empty())
		lista.pop_front();


	return 0;
}
