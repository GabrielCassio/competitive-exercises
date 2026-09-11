#include <bits/stdc++.h>

using namespace std;

// Example to declarate a data structure
vector<string> vs, myvector;

int main(){
    // Iterators
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it){
        cout << *it;
    }
    for (auto element: vs){
        cout << element;
    }

    // Dynamic Arrays
    vector<int> v;
    v.push_back(2); // [2]
    v.push_back(3); // [2, 3]
    v.push_back(7); // [2, 3, 7]
    v.push_back(5); // [2, 3, 7, 5]
    v[1] = 4; // sets element at index 1 to 4-> [2, 4, 7, 5]
    v.erase(v.begin() + 1); // removes element at index 1-> [2, 7, 5]
    // this remove method is O(n); to be avoided
    v.push_back(8); // [2, 7, 5, 8]
    v.erase(v.end()-1); // [2, 7, 5]
    // here, we remove the element from the end of the list; this is O(1).
    v.push_back(4); // [2, 7, 5, 4]
    v.push_back(4); // [2, 7, 5, 4, 4]
    v.push_back(9); // [2, 7, 5, 4, 4, 9]
    cout << v[2]; // 5
    v.erase(v.begin(), v.begin()+3); // [4, 4, 9]
    // this erases the first three elements; O(n) 

    // Stacks and the Various Types of Queues
    // Stacks
    stack<int> s;
    s.push(1); // [1]
    s.push(13); // [1, 13]
    cout << s.size() << endl; // 2
    s.pop(); // [1]
    cout << s.top() << endl; // 1
    s.pop(); // []
    cout << s.size() << endl; // 0 
    
    // Queues
    queue<int> q;
    q.push(1); // [1]
    q.push(3); // [3, 1]
    q.pop(); // [3]
    q.push(4); // [4, 3]
    cout << q.size() << endl; // 2
    cout << q.front() << endl; // 4

    // Deques
    deque<int> d;
    d.push_front(1); // [1]
    d.push_back(2); // [1, 2]
    d.push_front(3); // [3, 1, 2]
    d.push_back(4); // [3, 1, 2, 4]
    d.pop_back(); // [3, 1, 2]
    d.pop_front(); // [1, 2]

    // Priority Queues
    priority_queue<int> pq;
    pq.push(4); // [4]
    pq.push(2); // [2, 4]
    pq.push(1); // [1, 2, 4]
    pq.push(3); // [1, 2, 3, 4]
    cout << pq.top() << endl; // 4
    pq.pop(); // [1, 2, 3]
    pq.pop(); // [1, 2]
    pq.push(5); // [1, 2, 5]

    // Sets and Maps
    // Unordered set
    unordered_set<int> s;
    // s.insert(1); // [1]
    // s.insert(4); // [1, 4] in arbitrary order
    // s.insert(2);//[1,4,2]inarbitraryorder
    // s.insert(1);//[1,4,2]inarbitraryorder
    //theadd methoddidnothingbecause1wasalreadyintheset 
    // cout <<s.count(1) <<endl;//1
    // set.erase(1);//[2,4]inarbitraryorder
    // cout <<s.count(5) <<endl;//0
    // s.erase(0);//[2,4]inarbitraryorder
    // //iftheelementtoberemoveddoesnotexist,nothinghappens
    // for(int element:s){
    // cout <<element<< " ";
    // }
    // cout <<endl;
    // //Youcan iteratethroughanunorderedset,butitwilldosoinarbitrary

    // Unordered maps

    set<int> s;
    s.insert(1);//[1]
    s.insert(14);//[1,14]
    s.insert(9);//[1,9,14]
    s.insert(2);//[1,2,9,14]
    cout <<*s.upper_bound(7)<<'\n';//9
    cout <<*s.upper_bound(9)<<'\n';//14
    cout <<*s.lower_bound(5)<<'\n';//9
    cout <<*s.lower_bound(9)<<'\n';//9
    cout <<*s.begin() <<'\n';//1
    auto it= s.end();
    cout <<*(--it)<< '\n';//14
    s.erase(s.upper_bound(6));//[1,2,14]
}