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

	i = 0;

	while(i < 11)
	{
		cout << T[i].k << " ";

		i++;
	}

	cout << endl;

	return 0;
}
