#include <iostream>
#include <vector>
#include <string>

#define endl '\n'
using namespace std;

struct Task {
    int id;
    int priority;
};

struct Result {
    int id;
    int num_ops;
    int num_rest;
};

void add_task(vector<Task>& tasks, int id, int priority) {
    tasks.push_back({id, priority});
    return;
}

void update_task(vector<Task>& tasks, int id, int priority) {
    for (auto& task : tasks) {
        if (task.id == id) {
            task.priority = priority;
            break;
        }
    }
    return;
}

const Result remove_task(vector<Task>& tasks) {

    if (tasks.empty()) {
        return {-1, -1, -1};
    }

    int max_priority = -1;
    for (const auto& task : tasks) {
        if (task.priority > max_priority) {
            max_priority = task.priority;
        }
    }

    Result result = {-1, -1, -1};
    for (int i = 0; i < tasks.size(); ++i) {
        if ((tasks[i].priority == max_priority) && (tasks[i].id < result.id || result.id == -1)) {
            result.id = tasks[i].id;
            result.num_ops = i + 1;
            result.num_rest = int(tasks.size() - 1);   
        }
    }

    tasks.erase(tasks.begin() + result.num_ops - 1);
    return {result.id, result.num_ops, result.num_rest};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q; 
    vector<Task> tasks;
    string task;
    for (int i = 0; i < q; i++) {
        cin >> task;        

        if (task == "NEXT") {
            auto result = remove_task(tasks);
            if (result.id == -1) {
                cout << "FILA VAZIA" << endl;
            } else {
                cout << result.id << " " << result.num_ops << " " << result.num_rest << endl;
            }
        } else if (task == "ADD") {
            int id, priority; cin >> id >> priority;
            add_task(tasks, id, priority);
        } else if (task == "UPDATE") {
            int id, priority; cin >> id >> priority;
            update_task(tasks, id, priority);
        }
    }

    return 0;
}