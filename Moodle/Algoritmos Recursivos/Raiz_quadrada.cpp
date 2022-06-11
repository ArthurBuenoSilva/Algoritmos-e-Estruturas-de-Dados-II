#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Função responsável por calcular a raiz quadrada de um número
float raiz(float x, float x0, float e)
{
	if(abs(pow(x0, 2) - x) <= e)
	{
		return x0;
	}
	else
	{
		return raiz(x, (pow(x0, 2) + x) / (2 * x0), e);
	}
}

int main()
{
	float x = 0; 		//Número a ser calculado
	float x0 = 0;		//Estimativa inicial da raiz
	float e = 0;		//Limitante superior
	float r = 0;		//Armazena o retorno da função

	//Lê os valores
	cin >> x >> x0 >> e;

	//Chama e recebe o retorno da função
	r = raiz(x, x0, e);

	//Exibe o resultado
	cout << fixed << setprecision(2);
	cout << r << endl;

	return 0;
}