// Felipe Lages de Lima
// Felps-LDL
 
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define MAXN 10100
#define INTMAX 10000000000
#define pii pair<int, int> 
#define delta 0.0000001
#define ALL(x) x.begin(), x.end()
#define ll long long

using namespace std;

int qtd_vertice;

vector<pii> grafo[MAXN], arvore[MAXN];

void arvore_min(int origem)
{
    bool visitados[MAXN];
    for (int i = 0; i < MAXN; i++) visitados[i] = false;

    vector<int> vertices;
    vertices.push_back(origem);
    visitados[origem] = true;

    while(vertices.size() < qtd_vertice)
    {
        int menor_custo = MAXN, vertice_apontador = MAXN, adjacente = MAXN;

        for (int i : vertices)
        {
            for (auto vertice : grafo[i])
            {
                if (!visitados[vertice.first] && vertice.second < menor_custo)
                {
                    menor_custo = vertice.second;
                    vertice_apontador = i;
                    adjacente = vertice.first;
                }
            }
        }

        visitados[adjacente] = true;
        vertices.push_back(adjacente);
        arvore[vertice_apontador].push_back({adjacente, menor_custo});
        arvore[adjacente].push_back({vertice_apontador, menor_custo});
    }
}

int main()
{
    //optimize;

    cout << "Quantidade de vertices: ";
    cin >> qtd_vertice;

    /*
    for (int i = 1; i <= qtd_vertice; i++)
    {
        int vizinhos;
        cout << "Vertice " << i << " eh ligado a quantos vertices: ";
        cin >> vizinhos;
        cout << "Vizinhos do vertice " << i << ":\n";

        for (int j = 1; j <= vizinhos; j++)
        {
            int vizinho, custo;
            cout << "Vizinho " << j << ": ";
            cin >> vizinho;
            cout << "Custo: ";
            cin >> custo;

            grafo[i].push_back({vizinho, custo});
            grafo[vizinho].push_back({i, custo});
        }
    }
    */

    grafo[1].push_back({2, 4});
    grafo[1].push_back({8, 8});

    grafo[2].push_back({1, 4});
    grafo[2].push_back({8, 11});
    grafo[2].push_back({3, 8});

    grafo[3].push_back({2, 8});
    grafo[3].push_back({9, 2});
    grafo[3].push_back({6, 4});
    grafo[3].push_back({4, 7});

    grafo[4].push_back({3, 7});
    grafo[4].push_back({6, 14});
    grafo[4].push_back({5, 9});

    grafo[5].push_back({4, 9});
    grafo[5].push_back({6, 10});

    grafo[6].push_back({4, 14});
    grafo[6].push_back({7, 2});
    grafo[6].push_back({3, 4});
    grafo[6].push_back({5, 10});

    grafo[7].push_back({6, 2});
    grafo[7].push_back({8, 1});
    grafo[7].push_back({9, 6});

    grafo[8].push_back({2, 11});
    grafo[8].push_back({1, 8});
    grafo[8].push_back({7, 1});
    grafo[8].push_back({9, 7});
    
    grafo[9].push_back({3, 2});
    grafo[9].push_back({7, 6});
    grafo[9].push_back({8, 7});

    arvore_min(1);

    for (int i = 1; i <= qtd_vertice; i++)
    {
        cout << i;
        for (auto vertice : arvore[i])
        {   
            cout << " -> ";
            cout << vertice.first << ", custo: " << vertice.second;
        }

        cout << endl;
    }

    return 0;
}
