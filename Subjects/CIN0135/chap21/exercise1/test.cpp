#include "vector.h"

#include <random>

using namespace std;

int main(void){
    // Inicialização do gerador de números pseudoaleatórios
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1,10);

    // Declarando splices que serão emendados
    int len1 = 10; int len2 = 20; int pos = 5;
    int array[len1]; int array1[len2];


    cout << "Primeira Lista: " << endl;
    for (int i = 0; i < len1; i++){
        array[i] = distrib(gen);
        cout << array[i] << " ";
    }

    cout << endl << "Segunda Lista: " << endl;
    for (int j = 0; j < len2; j++){
        array1[j] = distrib(gen);
        cout << array1[j] << " ";
    }

    int* result_arr = splice(array, len1, array1, len2, pos);


    for (int k = 0; k < (len1 + len2); k++)
    {
        if (k == pos) cout << endl << "Posicao de corte inicial do splice <---------------------------";
        
        cout    << endl << "O valor do Array apos o SPLICE na posicao " << k
                << " e: " << result_arr[k];

        if (k == pos + len2) cout << endl << "Posicao de corte final do splice <----------------------------";
    }
    
    return 0;
}