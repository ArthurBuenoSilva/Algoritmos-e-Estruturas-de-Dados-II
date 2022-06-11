#include <iostream>

using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
	int i, j; // contadores
	int chave;

	for (j = 1; j < tamanho; j++)
	{
		chave = vetor[j];
		i = j - 1;

		while ((i >= 0) && (vetor[i] < chave))
		{
			vetor[i + 1] = vetor[i];
			i = i - 1;
		}

		vetor[i + 1] = chave;
	}

	//Exibe o vetor ordenado
	for(int i = 0; i < tamanho; i++)
	{
		cout << vetor[i] << " ";
	}
	
	cout << endl;
}

int main()
{
	int vetor[100]; //Vetor de n�meros
	
	int cont = 0;	//Contador
	int aux = -1;	//Auxilia na leitura

	//L� o primeiro n�mero
	cin >> aux;

	//L� os outros n�meros at� encontrar 0
	while(aux != 0)
	{
		vetor[cont] = aux;
		cont++;
		cin >> aux;
	}
	
	//Chama a fun��o de ordena��o
	insercaoDireta(vetor, cont);

	return 0;
}