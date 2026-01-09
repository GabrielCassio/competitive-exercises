// Aplicação do conceito de LIFO sobre sequências não ordenadas
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using vi = vector<int>;
using vs = vector<string>;
using sti = stack<int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vi vecStationA(n, 0);
    vs vecStationC;
    for(int i = 0; i < n; i++) cin >> vecStationA[i];

    sti stiStationB;
    int nextNum = 1; int numOps = 0; bool isPossible = true;
    while (!vecStationA.empty()){ // Verifica o conjunto inicial (vector) até ficar vazio
        bool goToC = false;
        bool existElemInB = !stiStationB.empty();
        if (vecStationA[vecStationA.size() - 1] == nextNum){
            numOps++;
            goToC = true;
            vecStationC.push_back("A C");
            vecStationA.pop_back();
            nextNum++;
        }
        if (existElemInB){
            if (stiStationB.top() == nextNum){
                numOps++;
                goToC = true;
                vecStationC.push_back("B C");
                stiStationB.pop();
                nextNum++;
            }
        }
        if (!goToC){
            if(existElemInB){
                if (vecStationA[vecStationA.size() - 1] > stiStationB.top()){
                    isPossible = false;
                    break;
                }
            }
            numOps++;
            vecStationC.push_back("A B");
            stiStationB.push(vecStationA[vecStationA.size() - 1]);
            vecStationA.pop_back();
        }
    }

    while (!stiStationB.empty() && isPossible){ // Caso a LIFO não esteja vazia continua fazendo as atrivuições necessárias
        numOps++; nextNum++;
        vecStationC.push_back("B C");
        stiStationB.pop();
    }

    if (!isPossible) cout << "-1";
    else{
        cout << numOps << endl;
        for (int i = 0; i < vecStationC.size(); i++) cout << vecStationC[i] << endl;
    }
    return 0;
}