#include <iostream>
#include <iomanip>
#include <list>
#include <climits>

using namespace std;

struct no
{
	int v; 		// vertice adjacente
	float p; 		// peso da aresta
};

void dijkstra(list<no>adj[], int nVertices, int start, int end)
{
	int u = 0;
	int v = 0;
	list<no>::iterator p;
	int destino = 0;
	float weight = 0;
	float dist = 0;
	bool intree[nVertices];
	float distance[nVertices];
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

			if(distance[destino] > distance[v] + weight)
			{
				distance[destino] = distance[v] + weight;
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

	cout << "Menor caminho: ";

	list<int> pilha;
	int cont = end;
	int pai = 0;

	pilha.push_front(end);
	pai = parent[end];

	while(cont >= start)
	{
		pilha.push_front(pai);
		pai = parent[pai];
		cont--;
	}
	
	for(list<int>::iterator p = pilha.begin(); p != pilha.end(); p++)
	{
		cout << *p << " ";
	}

	cout << endl << "Custo: " << distance[end];
}

void cria_aresta(list<no>adj[], int u, int v, float p, int orientado)
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
	int nVertices = 0;	//N? de vertices do grafo
	int vInicial = 0;	//Vertice inicial
	int orientado = 0;

	int vOrigem = 0;	//Vertice de origem
	int vDestino = 0;	//Vertice de destino
	int vDestino2 = 0;	//Vertice de destino
	float pAresta = 0;	//Peso da aresta

	//L? o n? de vertices e o vertice inicial
	cin >> nVertices >> orientado >> vInicial >> vDestino2;

	list<no> adj[nVertices];		//Lista de adjacencia

	//L? o o vertice de origem, o vertice de destino e o peso da aresta
	cin >> vOrigem >> vDestino >> pAresta;

	while(vOrigem != -1 && vDestino != -1 && pAresta != -1)
	{
		cria_aresta(adj, vOrigem, vDestino, pAresta, orientado);

		//L? o o vertice de origem, o vertice de destino e o peso da aresta
		cin >> vOrigem >> vDestino >> pAresta;
	}

	dijkstra(adj, nVertices, vInicial, vDestino2);

	return 0;
}
