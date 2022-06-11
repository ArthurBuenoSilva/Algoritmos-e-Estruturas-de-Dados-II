#include <iostream>

using namespace std;

int binaria(int vetor[], int tamanho, int x)
{
	bool achou; //Variável auxiliar p/ busca
	int baixo, meio, alto; //Variáveis auxiliáres

	baixo = 0;
	alto = tamanho - 1;
	achou = false;

	while((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) / 2;

		if (x < vetor[meio])
			alto = meio - 1;
		else if (x > vetor[meio])
			baixo = meio + 1;
		else
			achou = true;
	}

	return achou ? meio : -1;
}

int main()
{
	int vetor[100];			//Vetor de números
	int n = 0;				//Número para ser encontrado

	int aux = 0;			//Variável auxiliar na leitura dos dados
	int cont = 0;			//Contador

	int retorno = 0; 	//Armazena o retorno da função

	//Leitura dos IDs
	while(aux != -1)
	{
		cin >> aux;

		if(aux != -1)
		{
			vetor[cont] = aux;
		}

		cont++;
	}

	//Leitura do ID desejado
	cin >> n;

	//Chama e recebe o retorno da função
	retorno = binaria(vetor, cont, n);

	//Verifica o retorno da função
	if(retorno != -1)
		cout << "Possui acesso" << endl;
	else
		cout << "Nao possui acesso" << endl;

	return 0;
}