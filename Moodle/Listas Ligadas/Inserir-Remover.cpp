#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> fila;					//ponteiro para a fila

	//Inserindo elementos na fila
	fila.push_back(2); 				//Inseri elementos no inicio da fila
	fila.push_back(1);
	fila.push_back(5);

	cout << *fila.begin() << endl;	//Exibe o primeiro elemento

	//Removendo elementos da fila

	while(!fila.empty())
	{
		cout << *fila.begin() << endl;
		fila.pop_front();			//Remove o primeiro elemento
	}

	return 0;
}
