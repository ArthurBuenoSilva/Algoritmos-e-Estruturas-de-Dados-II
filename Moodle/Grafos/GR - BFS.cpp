#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

struct no
{
	int v; 		// vertice adjacente
	int p; 		// peso da aresta
};

void bfs(list<no>adj[], int nVertices, int s)
{
	int state[nVertices];
	int p[nVertices];
	int u = 0;
	int v = 0;

	for(int u = 0; u < nVertices; u++)
	{
		if(u != s)
		{
			state[u] = -1;		//undiscovered
			p[u] = - 1;
		}
	}

	list<int> Q;
	state[s] = 0;				//discovered
	p[s] = -1;
	Q.push_back(s);

	list<no>::iterator it;

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop_front();
		cout << u << endl;

		for(it = adj[u].begin(); it != adj[u].end(); it++)
		{
			v = it -> v;
			cout << u << " " << v << endl;

			if(state[v] == -1)
			{
				state[v] = 0;	//discovered
				p[v] = u;
				Q.push_back(v);
			}
		}

		state[u] = 1;			//processed
	}
}

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux;					//Var aux para inserir arestas em adj

	aux.v = v;
	aux.p = p;

	adj[u].push_back(aux);

	if(orientado == 0)
	{
		aux.v = u;

		adj[v].push_back(aux);
	}
}

int main()
{
	int nVertices = 0;	//N° de vertices do grafo
	int vInicial = 0;	//Vertice inicial

	int vOrigem = 0;	//Vertice de origem
	int vDestino = 0;	//Vertice de destino
	int pAresta = 0;	//Peso da aresta

	//Lê o n° de vertices e o vertice inicial
	cin >> nVertices >> vInicial;

	list<no> adj[nVertices];		//Lista de adjacencia

	//Lê o o vertice de origem, o vertice de destino e o peso da aresta
	cin >> vOrigem >> vDestino >> pAresta;

	while(vOrigem != -1 && vDestino != -1 && pAresta != -1)
	{
		cria_aresta(adj, vOrigem, vDestino, pAresta, 0);

		//Lê o o vertice de origem, o vertice de destino e o peso da aresta
		cin >> vOrigem >> vDestino >> pAresta;
	}

	bfs(adj, nVertices, vInicial);

	return 0;
}
