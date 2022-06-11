#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct dados
{
	int codigo; 		//C�digo do produto
	int quantidade; 	//Quantidade em estoque
	float preco; 		//Pre�o unit�rio
};

//Fun��o que organiza o vetor em ordem crescente
void quickSort(dados vetor[], int i, int j)
{
	dados trab, pivo;
	int esq = i;
	int dir = j;
	
	pivo.codigo = vetor[(int)round((esq + dir) / 2.0)].codigo;
	
	do
	{
		while (vetor[esq].codigo < pivo.codigo)
			esq++;
		
		while (vetor[dir].codigo > pivo.codigo)
			dir--;
		
		if (esq <= dir)
		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	}
	while (esq <= dir);
	
	if (dir - i >= 0)
		quickSort(vetor, i, dir);
	if (j - esq >= 0)
		quickSort(vetor, esq, j);
}

int main()
{
	dados Dados[100];

	int n = 0; 		//N�mero de produtos
	int aux = 0;	//Auxilia na leitura dos dados

	//L� o n�mero de produtos
	cin >> n;

	//L� os dados
	while(aux < n)
	{
		cin >> Dados[aux].codigo;
		cin >> Dados[aux].quantidade;
		cin >> Dados[aux].preco;

		aux++;
	}

	//Organiza o vetor em ordem crescente
	quickSort(Dados, 0, n - 1);

	aux = 0;

	//Exibe o Vetor
	while(aux < n)
	{
		cout << " Codigo: " << Dados[aux].codigo << endl;
		cout << "Quantidade em estoque: " << Dados[aux].quantidade << endl;
		cout << fixed << setprecision(2);
		cout << "Preco unitario: R$ " << Dados[aux].preco << endl;

		aux++;
	}

	return 0;
}