#include <iostream>
#include <iomanip>
#include <list>
#include <climits>

using namespace std;

struct no
{
	int v; 		// vertice adjacente
	int p; 		// peso da aresta
};

void prim(list<no>adj[], int nVertices, int start)
{
	int u = 0;
	int v = 0;
	list<no>::iterator p;
	int destino = 0;
	int weight = 0;
	int dist = 0;
	bool intree[nVertices];
	int distance[nVertices];
	int parent[nVertices];

	for(u = 0; u < nVertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}

	distance[start] = 0;
	v = start;

	while(intree[v] == false)
	{
		intree[v] = true;

		for(p = adj[v].begin(); p != adj[v].end(); p++)
		{
			destino = p->v;
			weight = p->p;

			if(distance[destino] > weight && intree[destino] == false)
			{
				distance[destino] = weight;
				parent[destino] = v;
			}
		}

		v = 0;
		dist = INT_MAX;

		for(u = 0; u < nVertices; u++)
		{
			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}
	}

	cout << "Arvore Geradora Minima:" << endl;

	int custo = 0;
	
	for(u = 0; u < nVertices; u++)
	{
		if(parent[u] != -1)
		{
			cout << parent[u] << " " << u << endl;
		}
		
		custo += distance[u];
	}
	
	cout << "Custo: " << custo;
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
	int orientado = 0;

	int vOrigem = 0;	//Vertice de origem
	int vDestino = 0;	//Vertice de destino
	int pAresta = 0;	//Peso da aresta

	//Lê o n° de vertices e o vertice inicial
	cin >> nVertices >> orientado >> vInicial;

	list<no> adj[nVertices];		//Lista de adjacencia

	//Lê o o vertice de origem, o vertice de destino e o peso da aresta
	cin >> vOrigem >> vDestino >> pAresta;

	while(vOrigem != -1 && vDestino != -1 && pAresta != -1)
	{
		cria_aresta(adj, vOrigem, vDestino, pAresta, orientado);

		//Lê o o vertice de origem, o vertice de destino e o peso da aresta
		cin >> vOrigem >> vDestino >> pAresta;
	}

	prim(adj, nVertices, vInicial);

	return 0;
}
