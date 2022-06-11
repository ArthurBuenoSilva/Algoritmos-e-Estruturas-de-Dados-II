#include <iostream>

using namespace std;

//Função que realiza a busca sequencial
int sequencial(int vet[], int tam, int x)
{
	int pos = 0;			//Posição onde o número desejado está
	bool achou = false;		//Responsável por verificar se o número foi encontrado

	//Verifica se o número foi encontrado
	for(int i = 0; i < tam; i++)
	{
		if(vet[i] == x)
		{
			pos = i;
			achou = true;
		}
	}

	return achou ? pos : -1;
}

int main()
{
	int vetor[100];		//Vetor de números
	int n = 0;			//Número para ser encontrado

	int aux = 0;		//Variável auxiliar na leitura dos dados
	int cont = 0;		//Contador
	int pos = 0;		//Posição do número desejado

	while(aux != -1)
	{
		cin >> aux;

		if(aux != -1)
		{
			vetor[cont] = aux;
		}

		cont++;
	}

	//Leitura do número desejado
	cin >> n;

	//Chamada e retorno da função
	pos = sequencial(vetor, cont, n);

	//Verifica se o número foi encontrado
	if(pos != -1)
	{
		cout << n << " encontrado na posicao " << pos << endl;
	}
	else
	{
		cout << n << " nao encontrado" << endl;
	}

	return 0;
}