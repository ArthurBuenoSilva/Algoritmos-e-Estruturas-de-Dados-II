#include <iostream>
#include <iomanip>

using namespace std;

struct nota
{
	int nota[];
	float media;
};

int main()
{
	nota *notas;

	int tam = 0;
	float m = 0;

	cin >> tam;

	notas = new nota[tam];

	for(int i = 0; i < tam; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cin >> notas[i].nota[j];
			notas[i].media += notas[i].nota[j];
		}		
	}

	for(int i = 0; i < tam; i++)
	{
		notas[i].media /= 4;
		m += notas[i].media;
	}

	cout << fixed << setprecision(2) << m / tam << endl;

	delete [] notas;

	return 0;
}
