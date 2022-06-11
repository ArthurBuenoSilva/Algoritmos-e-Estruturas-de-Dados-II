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

	notas = new nota;

	for(int i = 0; i < 4; i++)
	{
		cin >> notas->nota[i];
	}

	for(int i = 0; i < 4; i++)
	{
		notas->media += notas->nota[i];
	}
	
	notas->media /= 4;
	
	cout << fixed << setprecision(2) << notas->media << endl;

	delete [] notas;

	return 0;
}
