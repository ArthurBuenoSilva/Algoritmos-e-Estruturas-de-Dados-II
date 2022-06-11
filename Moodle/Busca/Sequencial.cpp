#include <iostream>

using namespace std;

//Fun��o que realiza a busca sequencial
int sequencial(int vet[], int tam, int x)
{
	int pos = 0;			//Posi��o onde o n�mero desejado est�
	bool achou = false;		//Respons�vel por verificar se o n�mero foi encontrado

	//Verifica se o n�mero foi encontrado
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
	int vetor[100];		//Vetor de n�meros
	int n = 0;			//N�mero para ser encontrado

	int aux = 0;		//Vari�vel auxiliar na leitura dos dados
	int cont = 0;		//Contador
	int pos = 0;		//Posi��o do n�mero desejado

	while(aux != -1)
	{
		cin >> aux;

		if(aux != -1)
		{
			vetor[cont] = aux;
		}

		cont++;
	}

	//Leitura do n�mero desejado
	cin >> n;

	//Chamada e retorno da fun��o
	pos = sequencial(vetor, cont, n);

	//Verifica se o n�mero foi encontrado
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