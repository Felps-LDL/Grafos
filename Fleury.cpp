// Grupo 1
// euleriano
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define MAXN 1000
#define INTMAX 10000000000
#define pii pair<int, int> 
#define delta 0.0000001
#define ALL(x) x.begin(), x.end()
#define ll long long

using namespace std;

int cont = 0;
vector<int> grafos[MAXN];
vector<bool> visitados(MAXN, false);
vector<int> caminho;

// Caminho euleriano ou nao
bool verify_euler()
{
    for (auto vertice : grafos)
    {
        if (!(vertice.empty())) return false;
    }

    return true;
}

// Remove a aresta
void delEdge(int origem, int destino)
{
    // Remove pela posição
    for (int i = 0; i < grafos[origem].size(); i++)
    {
        if (grafos[origem][i] == destino)
        {
            grafos[origem].erase(grafos[origem].begin() + i);
            break;
        }
    }

    for (int i = 0; i < grafos[destino].size(); i++)
    {
        if (grafos[destino][i] == origem)
        {
            grafos[destino].erase(grafos[destino].begin() + i);
            break;
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

    for (int i = 0; i < MAXN; i++) visitados[i] = false;
    DFS(origem);

    // Adiciona a aresta novamente
    grafos[origem].push_back(destino);
    grafos[destino].push_back(origem);
    
    return cont != temp;
}

void euler(int origem)
{
    for (auto vizinho : grafos[origem])
    {
        // Se não for ponte ou for o último vizinho ele remove a aresta
        if (!isBridge(origem, vizinho) || grafos[origem][grafos[origem].size() - 1] == vizinho)
        {
            caminho.push_back(vizinho);
            delEdge(origem, vizinho);
            euler(vizinho);
            break;
        }
    }
}

int main()
{
    grafos[0].push_back(1);
    grafos[0].push_back(2);
    grafos[1].push_back(0);
    grafos[1].push_back(2);
    grafos[2].push_back(0);
    grafos[2].push_back(1);
    grafos[2].push_back(3);
    grafos[3].push_back(2);

    int valor = 0;

    cout << "Valor: ";
    cin >> valor;

    caminho.push_back(valor);
    euler(valor);

    cout << "Caminho: ";
    for (auto elemento : caminho) cout << elemento << " -> ";
    cout << endl;

    if (verify_euler()) cout << "Eh um caminho euleriano\n";
    else cout << "Nao eh um caminho euleriano";


    return 0;
}
