#include <iostream>

using namespace std;

struct dados
{
	int k;
	int status;
};

int hash_aux(int k, int m)
{
	//Faz h'(k) = k mod n
	int h = k % m;

	return h >= 0 ? h : h + m;
}

int hash1(int k, int i, int m)
{
	int h = hash_aux(k, m);

	//Faz h(k) = h'(k) + i mod n
	return (h + i) % m;
}

int hash_search(dados T[], int m, int k)
{
	int i = 0;
	int j = 0;

	do
	{
		j = hash1(k, i, m);

		if(T[j].k == k)
		{
			return j;
		}

		i++;
	}
	while(T[j].status != 0 && i < m);

	return -1;
}

int hash_insert(dados T[], int m, int k)
{
	int i = 0;

	do
	{
		int j = hash1(k, i, m);
		if (T[j].status != 1)
		{
			T[j].k = k;
			T[j].status = 1;
			return j;
		}
		else
		{
			i++;
		}
	}
	while(i != m);

	return -1;
}

int main()
{
	dados T[100];		//Vetor de structs

	int m = 0;			//Tamanho da tabela
	int i = 0;			//Contador
	int k = 0;			//Chave

	int chave = 0;
	int r = 0;

	//Lê o valor
	cin >> m;

	while(i < 100)
	{
		T[i].k = -1;
		T[i].status = 0;
		i++;
	}


	//Lê o segundo valor
	cin >> k;

	while(k != 0)
	{
		hash_insert(T, m, k);

		cin >> k;
	}

	//Lê a chave
	cin >> chave;

	r = hash_search(T, m, chave);

	if(r == -1)
	{
		cout << "Chave " << chave << " nao encontrada" << endl;
	}
	else
	{
		cout << "Chave " << chave << " encontrada na posicao " << r << endl;
	}

	cout << endl;

	return 0;
}