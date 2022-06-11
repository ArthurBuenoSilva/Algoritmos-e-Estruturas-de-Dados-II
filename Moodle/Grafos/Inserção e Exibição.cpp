#include <iostream>
#include <list>

using namespace std;

struct no
{
	int v;	//Destino da aresta
	int p;	//Peso da aresta
};

int main()
{
	list<no> adj[10];		//Lista de adjacencia
	list<no>::iterator q;	//Iterador para varrer a lista de adjacencia

	int nVertices = 0; 		//N° de vertices do grafo
	int u = 0;				//Origem de uma aresta
	int v = 0;				//Destino de uma aresta
	int p = 0;				//Peso da aresta u-v
	int i = 0;				//Contador
	int o = 1;				// 0 -> Não orientado	1 -> Orientado

	no aux;					//Var aux para inserir arestas em adj

	cin >> nVertices >> o;

	//Lendo e inserindo arestas
	for(i = 0; i < nVertices; i++)
	{
		cin >> u >> v >> p;
		
		aux.v = v;
		aux.p = p;
			
		adj[u].push_back(aux);
		
		if(o == 0)
		{
			aux.v = u;

			adj[v].push_back(aux);
		}
	}

	cout << endl << "Lista de adjacencia: " << endl;

	//Exibindo a lista de adjacencia
	for(i = 0; i < nVertices; i++)
		for(q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << " " << q->v << " " << q->p << endl;


	return 0;
}
