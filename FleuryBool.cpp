// Grupo 1
// euleriano
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define MAXN 100
#define INTMAX 10000000000
#define pii pair<int, int> 
#define delta 0.0000001
#define ALL(x) x.begin(), x.end()
#define ll long long

using namespace std;

int cont = 0;

// MAXN = quantidade de vértices
bool grafos[MAXN][MAXN];
vector<bool> visitados(MAXN, false);
vector<int> caminho;

// Remove a aresta
void delEdge(int origem, int destino)
{
    grafos[origem][destino] = false;
    grafos[destino][origem] = false;
}

// Adiciona a aresta
void addEdge(int origem, int destino)
{
    grafos[origem][destino] = true;
    grafos[destino][origem] = true;
}

// Seta visitados
void setVisitados()
{
    for (int i = 0; i < MAXN; i++) visitados[i] = false;
}

// Seta como sem arestas inicialmente
void setEdge()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            grafos[i][j] = false;
        }
    }
}

// Busca em profundidade
void DFS(int origem)
{
    visitados[origem] = true;
    cont++;

    for (auto vizinho : grafos[origem])
    {
        if (!visitados[vizinho]) DFS(vizinho);
    }
}

// Verifica se é ponte
bool isBridge(int origem, int destino)
{
    cont = 0;
    DFS(origem);

    int temp = cont;
    cont = 0;

    // Remove temporariamente a aresta
    delEdge(origem, destino);

    setVisitados();
    DFS(origem);

    // Adiciona a aresta novamente
    addEdge(origem, destino);
    
    return cont != temp;
}

void euler(int origem)
{
    bool ok = false;
    int ultimo = -1;
    for (int vizinho = 0; vizinho < MAXN; vizinho++)
    {
        // Se existir tal aresta
        if (grafos[origem][vizinho])
        {
            ultimo = vizinho;
            // Se não for ponte ou for o último vizinho ele remove a aresta
            if (!isBridge(origem, vizinho))
            {
                ok = true;
                caminho.push_back(vizinho);
                delEdge(origem, vizinho);
                euler(vizinho);
                break;
            }
        }
    }

    // Verificação pra ver se existe aresta pra adicionar partindo do ponto atual
    if (ultimo != -1 && !ok)
    {
        caminho.push_back(ultimo);
        delEdge(origem, ultimo);
        euler(ultimo);
    }
}

int main()
{
    while(true)
    {
        caminho.clear();
        setVisitados();
        setEdge();
        addEdge(0, 1);
        addEdge(0, 2);
        addEdge(1, 2);
        addEdge(2, 3);

        int valor = 0;

        cout << "Valor: ";
        cin >> valor;

        caminho.push_back(valor);
        euler(valor);


        for (auto elemento : caminho) cout << elemento << " -> ";
        cout << endl;
    }

    return 0;
}
