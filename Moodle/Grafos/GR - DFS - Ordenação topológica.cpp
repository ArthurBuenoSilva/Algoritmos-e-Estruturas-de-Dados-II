#include <iostream>
#include <list>

using namespace std;

struct no
{
	int v;      // vertice adjacente
};

void ordenacao_topologica(int f[], int nVertices)
{
	int mPos = 0;
	int mVal = -1;
	int cont = 0;

	while(cont < nVertices)
	{
		for(int i = 0; i < nVertices; i++)
		{
			if(i == 0)
			{
				mVal = f[i];
			}
			
			if(f[i] >= mVal)
			{
				mVal = f[i];
				mPos = i;
			}
		}

		cout << mPos << " ";

		f[mPos] = -1;

		cont++;
	}

}

void dfs_visit(list<no>adj[], char color[], int d[], int pi[], int f[], int &time, int u, int nVertices)
{
	list<no>::iterator v;
	color[u] = 'g';
	time++;
	d[u] = time;
	for(v = adj[u].begin(); v != adj[u].end(); v++)
	{
		if(color[v->v] == 'w')
		{
			pi[v->v] = u;
			dfs_visit(adj, color, d, pi, f, time, v->v, nVertices);
		}
	}
	color[u] = 'b';
	f[u] = time = time + 1;
}

void dfs(list<no>adj[], int nVertices)
{
	int u = 0;
	list<no>::iterator v;
	int time = 0;
	int pi[19];
	int d[10];
	int f[10];
	char color[10];
	for(u = 0; u < nVertices; u++)
	{
		color[u] = 'w';
		pi[u] = -1;
	}
	time = 0;
	for(u = 0; u < nVertices; u++)
	{
		if(color[u] == 'w')
		{
			dfs_visit(adj, color, d, pi, f, time, u, nVertices);
		}
	}
	ordenacao_topologica(f, nVertices);
}

void cria_aresta(list<no>adj[], int u, int v, int orientado)
{
	no aux;                 //Var aux para inserir arestas em adj
	aux.v = v;
	adj[u].push_back(aux);
	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

int main()
{
	int nVertices = 0;  //N° de vertices do grafo
	int orientado = 0;
	int vOrigem = 0;    //Vertice de origem
	int vDestino = 0;   //Vertice de destino
	//Lê o n° de vertices
	cin >> nVertices >> orientado;
	list<no> adj[nVertices];        //Lista de adjacencia
	//Lê o o vertice de origem, o vertice de destino
	cin >> vOrigem >> vDestino;
	while(vOrigem != -1 && vDestino != -1)
	{
		cria_aresta(adj, vOrigem, vDestino, orientado);
		//Lê o o vertice de origem, o vertice de destino
		cin >> vOrigem >> vDestino;
	}
	dfs(adj, nVertices);
	return 0;
}
