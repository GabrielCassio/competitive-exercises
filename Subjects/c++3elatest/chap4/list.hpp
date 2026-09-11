#pragma once

template <typename E>
class List {
    private:
        //void operator = (const List&) {} 
        void operator = (const List&) {}
        // List(const List&) {} // Versão antiga
        List(const List&) {}

    public:
        
        List() {}
        virtual ~List() {}

        virtual void clear() = 0;
        virtual void insert(const E& item) = 0;
        virtual void append(const E& item) = 0;
        virtual E remove() = 0;
        virtual void moveToStart() = 0;
        virtual void moveToEnd() = 0;
        virtual void prev() = 0;
        virtual void next() = 0;
        virtual int length() const = 0;
        virtual int currPos() const = 0;
        virtual void moveToPos(int pos) = 0;
        virtual const E& getValue() const = 0;

        bool find(List<E>& list, const E& item);
        
};

// Criado apenas para fins de exemplo
// Como funcionaria um find usando o operador ==
template<typename E>
bool List<E>::find(List<E>& list, const E& item) {
    E it;
    for (list.moveToStart(); list.currPos() < list.length(); list.next()){
        it = list.getValue();
        if (it == item) return true;
    }
    return false;
}