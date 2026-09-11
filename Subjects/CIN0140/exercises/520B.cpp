// struct Node {
//     int val;
//     char op;
// };

// class Graph {
//     private:
//         int n;
//         vector<vector<Node>> adj; // Lista adjacente de arestas
//         bool directed;
//         vector<bool> visited;

//     public:

//         Graph(int n, bool directed = false) : n(n), adj(n), visited(n, false), directed(directed) {}

//         void addEdge(int u, int v, char op) {
//             if (u < 0 || v < 0 || u > n - 1 || v > n - 1) return;

//             if (directed) {
//                 adj[u].push_back({v, op});
//             } else {
//                 adj[u].push_back({v, op});
//                 adj[v].push_back({u, op});
//             }            
//         }

//         const vector<Node>& neighbors(int u) const {
//             return adj[u];
//         }

//         void print() {
//             cout << "Lista de adjacências:" << endl;
//             for (int i = 0; i < n; i++) {
//                 cout << "Index - " << i << ": ";
//                 for (auto j = 0; j < adj[i].size(); j++) {
//                     cout << "(" << adj[i][j].val << ", " << adj[i][j].op << ") ";
//                 }
//                 cout << endl;
//             }
//             cout << endl;
//             return;
//         }
// };

/**
 * RED BUTTON - multiplica por 2
 * BLUE BUTTON - subtrai 1
 * Objetivo: Menor número de clicks até nesse n ser m | Problema do Menor Caminho
 * Dado dois valores de escolhas é possível que criar uma árvore binária
 * que servirá para bfs com a finalidade de encontrar o menor ramo
 * 
 */
#include <iostream>
#include <vector>
#include <queue>


#define endl '\n'
using namespace std;

/**
 * @param u: vértice inicial
 * @return: vetor de distâncias do vértice u para todos os outros vértices
 */
int bfs(int ival, int fval) {
    
    if (ival == fval) return 0;
    
    int n = 2e4; int INF = 1e9;
    
    vector<int> dist(n, INF); dist[ival] = 0;  // vetor de distâncias do vértice 0 para todos os outros vértices
    queue<int> q; q.push(ival); // cria uma fila para armazenar os vértices a serem visitados, iniciando pelo vértice 0
    
    while (!q.empty()) { // enquanto essa fila não estiver vazia
        int u = q.front(); q.pop(); // remove o vértice u da fila e vá para o próximo vértice vizinho
        int bval = u - 1;
        int rval = u * 2;
        
        if (bval < 0 || rval > n) continue;

        if (dist[bval] != INF && dist[rval] != INF) continue;
        
        if (bval == fval || rval == fval) return dist[u] + 1;
        
        if (bval >= 0 && dist[bval] == INF) {
            dist[bval] = dist[u] + 1;
            q.push(bval);
        }
        if (rval < n && dist[rval] == INF) {
            dist[rval] = dist[u] + 1;
            q.push(rval);
        }
    }
    
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    cout << bfs(n, m) << endl;

    return 0;
}
