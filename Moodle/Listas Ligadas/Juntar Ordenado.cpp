#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> lista1;	//Lista ligada 1
	list<int> lista2;	//Lista ligada 2
	list<int> lista3;	//Lista ligada 3

	int aux = 0;		//Variável auxiliar para leitura
	int tam = 0;		//Tamanho das listas ligadas
	int count = 0;		//Contador

	//Lê um valor
	cin >> aux;

	//Executa até encontrar 0
	while(aux != 0)
	{
		//Adiciona um valor ao fim da lista
		lista1.push_back(aux);
		cin >> aux;
		tam++;
	}

	aux = 0;

	//Lê um valor
	cin >> aux;

	//Executa até encontrar 0
	while(aux != 0)
	{
		//Adiciona um valor ao fim da lista
		lista2.push_back(aux);
		cin >> aux;
		tam++;
	}

	//Ponteiros para percorrer as listas
	list<int>::iterator p1 = lista1.begin();
	list<int>::iterator p2 = lista2.begin();

	//Adiciona os valores das listas 1 e 2 em ordem crescente na lista 3
	while(count < tam)
	{
		//Verifica se chegou ao fim da lista 1
		if(p1 != lista1.end())
		{
			//Verifica se chegou ao fim da lista 1
			if(p2 != lista2.end())
			{
				if(*p1 == *p2)
				{
					lista3.push_back(*p1);
					p1++;
					p2++;
				}
				else if(*p1 > *p2)
				{
					lista3.push_back(*p2);
					p2++;
				}
				else
				{
					lista3.push_back(*p1);
					p1++;
				}
			}
			else//Fim da lista 2
			{
				//Adiciona o restante dos valores da lista 1 na lista 3
				while(p1 != lista1.end())
				{
					lista3.push_back(*p1);
					p1++;
				}
			}
		}
		else//Fim da lista 1
		{
			//Adiciona o restante dos valores da lista 2 na lista 3
			while(p2 != lista2.end())
			{
				lista3.push_back(*p2);
				p2++;
			}
		}

		count++;
	}

	//Exibe a lista 3
	for(list<int>::iterator p = lista3.begin(); p != lista3.end(); p++)
	{
		cout << *p << " ";
	}

	return 0;
}
