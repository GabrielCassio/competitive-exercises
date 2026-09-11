/** 
 * Para cada novo nome adicionamos o registro, e para cada nome repetido,
 * apenas incrementamos o contador de registros. Eu usarei hashing para armazenar os nomes e contá-los.
 * Quais os prós-contras?
 * */ 

#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        string key;
        int count;
        Node*next;

        Node(const string& k, int c) : key(k), count(c), next(nullptr) {}
};

class HashMap {
    private:
        Node** table;
        int size;

        /**
         * Implementação de um Polynomial Rolling Hash Function para strings.
         */
        long long hash_function(const string& key) {
            const int p = 31;
            long long hash_value = 0;
            long long p_pow = 1;
            for (char c : key) {
                hash_value = (hash_value + (c - 'a' + 1) * p_pow) % size;
                p_pow = (p_pow * p) % size;
            }
            return hash_value;
        }

    public:
        HashMap(int size) : size(size) {
            table = new Node*[size]; // Criando array de Nós
            for (int i = 0; i < size; i++) {
                table[i] = new Node("", 0); // Inicializando cada posição com um nó vazio / head vazio
            }
            return;
        }
        ~HashMap() {
            for (int i = 0; i < size; i++) { // Varrendo chaining list
                Node* current = table[i]->next; // pulando o primeiro nó da lista encadeada
                while (current) {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            delete[] table;
            return;
        }

        void insert(const string& key) {
            long long index = hash_function(key);
            Node* current = table[index]; // Pegando o nó da tabela na referida posição
            while (current) {
                if (current->key == key) {
                    current->count++; return;
                } else if (current->next == nullptr) {
                    current->next = new Node(key, 1); return;
                }
                current = current->next;
            }
            return;
        }

        int search(const string& key) {
            long long index = hash_function(key);
            Node* current = table[index];
            while (current) {
                if (current->key == key) {
                    return current->count;
                }
                current = current->next;
            }
            return 0;
        }

        Node** get_map() const {
            return table;
        }
};

int main() {

    HashMap map(10000); // Criando um HashMap com 100 posições

    int n; cin >> n;
    while (n--) {
        string name; cin >> name;
        if (map.search(name) == 0) {
            map.insert(name);
            cout << "OK" << endl;
        } else {
            cout << name << map.search(name) << endl;
            map.insert(name);
        }
    }

    // Node* table = map.get_map()[0];
    // cout << "Tabela Hash:" << endl;
    // while (table)
    // {
    //     cout << "Nome: " << table->key << ", Contagem: " << table->count << endl;
    //     table = table->next;    
    // }
    
    return 0;
}