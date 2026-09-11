#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
using namespace std;
using vi = vector<int>;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

using qn = queue<Node*>;

class BinaryTree {
    private:
        int max_size;
        Node* root; // A raiz será o primeiro elemento inserido na árvore

        void preorder(Node* node, vi& res) const {
            if (node == nullptr) return;
            res.push_back(node->value);
            preorder(node->left, res);
            preorder(node->right, res);
            return;
        }
        void inorder(Node* node, vi& res) const {
            if (node == nullptr) return;
            inorder(node->left, res);
            res.push_back(node->value);
            inorder(node->right, res);
            return;
        }
        void postorder(Node* node, vi& res) const {
            if (node == nullptr) return;
            postorder(node->left, res);
            postorder(node->right, res);
            res.push_back(node->value);
            return;
        }

        void print(const vi& res) const {
            for (int val : res) {
                cout << val << " ";
            }
            return;
        }

        void clear() {
            return;
        }

    public:
        BinaryTree(int size) : max_size(size), root(nullptr) {}
        ~BinaryTree() { clear(); }

        void insert(int value) {
            
            if (root == nullptr) {
                root = new Node(value);
                return;
            }

            qn q; q.push(root);

            while (!q.empty()) {
                Node* curr_node = q.front(); q.pop();
                
                if (curr_node->left == nullptr) {
                    curr_node->left = new Node(value);
                    return;
                } else {
                    q.push(curr_node->left);
                }

                if (curr_node->right == nullptr) {
                    curr_node->right = new Node(value);
                    return;
                } else {
                    q.push(curr_node->right);
                }
            }
        }

        void preorder(){
            vi res; preorder(root, res); print(res);
            return;
        }
        void inorder(){
            vi res; inorder(root, res); print(res);
            return;
        }
        void postorder(){
            vi res; postorder(root, res); print(res);
            return;
        }
};


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    BinaryTree tree(n);
    while (n--) {
        int k; cin >> k;
        tree.insert(k);
    }

    cout << "Pre-order: "; tree.preorder();
    cout << endl;
    cout << "In-order: "; tree.inorder();
    cout << endl;
    cout << "Post-order: "; tree.postorder();
    cout << endl;

    return 0;
}