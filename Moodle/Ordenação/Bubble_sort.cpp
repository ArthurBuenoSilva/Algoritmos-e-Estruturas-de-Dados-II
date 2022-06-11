#include <iostream>

using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
	int i, j; //Contadores
	int trab;
	int limite;
	
	bool troca;

	troca = true;
	limite = tamanho - 1;

	while (troca)
	{
		troca = false;

		for (i = 0; i < limite; i++)
		{
			if (vetor[i] > vetor[i + 1])
			{
				trab = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = trab;
				j = i;
				troca = true;
			}
		}

		limite = j;
	}

	for(int i = 0; i < tamanho; i++)
	{
		cout << vetor[i] << " ";
	}
	
	cout << endl;
}

int main()
{
	int vetor[100]; //Vetor de números

	int cont = 0;	//Contador
	int aux = -1;	//Auxilia na leitura

	//Lê o primeiro número
	cin >> aux;

	//Lê os outros números até encontrar 0
	while(aux != 0)
	{
		vetor[cont] = aux;
		cont++;
		cin >> aux;
	}

	//Chama a função de ordenação
	bubbleSort(vetor, cont);

	return 0;
}