class noh {
    public:
        int key;
        int element;
        noh* esq;
        noh* dir;
        noh(int e, int k, noh* dir_noh = nullptr, noh* esq_noh = nullptr): element(e), key(k), esq(esq_noh), dir(dir_noh) {}
        noh(noh* dir_noh = nullptr, noh* esq_noh = nullptr): esq(esq_noh), dir(dir_noh) {}
};


class arvore {
    private:
        noh* root;
        noh* curr_noh;

        void init() {
            root = curr_noh = new noh;
            return;
        }

    public:
        
        arvore() {
            init();
        }
        ~arvore() {}

        void operator == (noh* ohter) {
            
        }

        int chave() { return curr_noh->key; }
        
};


noh* busca (arvore r, int k) {
    if (r == nullptr || r->chave == k)
        return r;
    if (r->chave > k)
        return busca (r->esq, k);
    else
        return busca (r->dir, k);
}

int main () {
    return 0;
}