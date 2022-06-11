#include <iostream>

using namespace std;

//Função recursiva para calcular a^n
int pot(int a, int n)
{
	if(n == 0)
		return 1;
	else if(n > 0)
		return a * pot(a, n - 1);
}

int main()
{
	int a = 0;	//Base
	int n = 0;	//Expoente
	int r = 0; 	//Resultado

	//Lê os valores para base e expoente
	cin >> a >> n;

	//Chama a função e armazena seu retorno
	r = pot(a, n);
	
	//Exibi o resultado
	cout << r << endl;

	return 0;
}