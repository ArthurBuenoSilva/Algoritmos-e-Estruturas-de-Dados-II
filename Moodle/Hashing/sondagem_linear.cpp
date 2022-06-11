#include <iostream>

using namespace std;

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

int main()
{
	int k = 0;			//Chave
	int m = 0;			//Tamanho da tabela hash
	int i = 0;			//Tentativas

	//Lê os valores
	cin >> k >> m;

	while(i < m)
	{
		cout << hash1(k, i, m) << " ";

		i++;
	}

	cout << endl;

	return 0;
}
