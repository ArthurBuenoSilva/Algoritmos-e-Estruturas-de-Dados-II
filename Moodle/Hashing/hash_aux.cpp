#include <iostream>

using namespace std;

int hash_aux(int k, int m)
{
	//Faz k mod n
	int h = k % m;

	return h >= 0 ? h : h + m;
}

int main()
{
	int k = 0;			//Chave
	int m = 0;			//Tamanho da tabela hash

	int aux1 = -1;		//Auxilia na leitura
	int aux2 = -1;		//Auxilia na leitura

	//Lê os valores
	cin >> aux1 >> aux2;

	//Faz a verificação de nulo
	while(aux1 != 0 && aux2 != 0)
	{
		k = aux1;
		m = aux2;

		//Chama e exibe o resultado da função
		cout << hash_aux(k, m) << endl;

		//Lê os valores
		cin >> aux1 >> aux2;
	}

	return 0;
}
