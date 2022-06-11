#include <iostream>

using namespace std;

int main()
{
	int vetor[3];
	int *p = NULL;
	
	vetor[0] = 2;
	vetor[1] = 5;
	vetor[2] = -3;
	
	cout << "vetor = "<< vetor << endl;
	cout << "*vetor = "<< *vetor << endl << endl;

	p = vetor;
	cout << "*p = " << *p << endl;
	
	p++;
	cout << "*p = " << *p << endl;
	
	p++;
	cout << "*p = " << *p << endl;
	
	p--;
	cout << "*p = " << *p << endl;
	
	p--;
	cout << "*p = " << *p << endl;
	
	return 0;
}
