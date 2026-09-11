/**
 * O primeiro passo para a resolução será implementar o conceito de soma ponderada para obter a maior soma possível.
 * Como assim?
 * Dado j intervalos de query deve-se a quantidade de vezes um valor se repete, com base nisso deve-se 
 * em ordem de grande numero de repeticoes e valor absoluto.
 */
// #include <ctime>

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;
using ll = long long;
// using vi = vector<int>;
using vll = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0; int q = 0; cin >> n >> q;
    vll list(n, 0), diff(n + 2, 0);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    
    int updt_val = 1;
    while (q--) {
        int l, r; cin >> l >> r;
        diff[l] += updt_val;
        diff[r + 1] -= updt_val;
    }
    
    vll prefix_sum(n+1, 0);
    for (int j = 1; j <= n; j++) {
        diff[j] += diff[j - 1];
        prefix_sum[j] += diff[j];
    }

    sort(list.begin(), list.end());
    sort(prefix_sum.begin(), prefix_sum.end());

    ll sum = 0;
    for (int k = 1; k <= n; k++) {
        sum += list[k - 1] * prefix_sum[k];
    }
    cout << sum << endl;
    
    
    return 0;
}

//srand(time(0));

/**
 * A função de partição de partição serve para ordenar (a partição, ora bolas)
 * com base no pivot, nesse caso o último da partição
 */
// int partition(vector<int>& vec, int low, int high) {
//     // Escolha do pivot
//     // O pivot é um valor escolhido para comparação de modo a ordenar os 
//     // menores do que ele à esquerda e maiores do que ele à direita
//     int random_index = low + rand() % (high - low + 1); // Escolha aleatória (random partition)
//     swap(vec[random_index], vec[high]);
//     int pivot = vec[high];
//     int i = low - 1; // Posição de exchange

//     for(int j = low; j <= high - 1; j++) {
//         if (vec[j] < pivot) {
//             i++;
//             swap(vec[i], vec[j]); // Faz a troca do valor comparado com o pivot com o valor na posição i (especifica de troca)
//         }
//     }

//     swap(vec[i + 1], vec[high]);

//     return i + 1;
// }

// void quicksort(vector<int>& vec, int low, int high) {

//     if (low < high) {
//         int pi = partition(vec, low, high); 

//         quicksort(vec, low, pi - 1); // Chama o quicksort para o subconjunto/vetor à esquerda
//         quicksort(vec, pi + 1, high); // Chama o quicksort para p subconjunto/vetor à direita
//     }

//     return;
// }

// quicksort(list, 0, n - 1);
// quicksort(prefix_sum, 0, n);

// cout << "Produto entre: " << list[k - 1] << " & " << prefix_sum[k] << endl;
// 5 3
// 5 2 4 1 3
// 1 5
// 2 3
// 2 3
