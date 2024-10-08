#include <iostream>
using namespace std;

template<typename T>
class BST {
public: 
    BST() : size(0), root(nullptr) {}
    ~BST() {
        clear(root);
    }

    int get_size() {
        return size;
    }

    void insert(T data) {
        root = insert(root, data);
    }

    bool search(T data) const {
        return search(root, data) != nullptr;
    }

    int get_size_of_subtree(int val) const {
        Node* current = search(root, val);
        if (current == nullptr) return 0;
        return get_size_of_subtree(current);
    }

private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;

        Node(T data = T(), Node* left = nullptr, Node* right = nullptr) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
    };

    int size;
    Node* root;

    Node* insert(Node* current, T data) {
        if (current == nullptr) {
            size++; return new Node(data); 
        }
        if (data < current->data) current->left = insert(current->left, data);
        else if (data > current->data) current->right = insert(current->right, data);
        return current;
    }

    Node* search(Node* current, T data) const {
        if (current == nullptr) return nullptr;
        if (current->data == data) return current;
        return (data < current->data) ? search(current->left, data) : search(current->right, data);
    }

    int get_size_of_subtree(Node* current) const {
        if (current == nullptr) return 0;
        return 1 + get_size_of_subtree(current->left) + get_size_of_subtree(current->right);
    }

    void clear(Node* current) {
        if (current == nullptr) return;
        clear(current->left);
        clear(current->right);
        delete current;
    }
};

int main() {
    int n; cin >> n;
    BST<int> bst;
    while (n--) {
        int x; cin >> x;
        bst.insert(x);
    }
    int val; cin >> val;
    cout << bst.get_size_of_subtree(val);
    
    return 0;
}