#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    Node* root;

    Node* copy(Node* node) {
        if (!node) return nullptr;
        Node* newNode = new Node(node->value);
        newNode->left = copy(node->left);
        newNode->right = copy(node->right);
        return newNode;
    }

    bool isomorphic(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return isomorphic(a->left, b->left) && isomorphic(a->right, b->right);
    }

    Node* add(Node* a, Node* b) {
        if (!a || !b) return nullptr;
        Node* newNode = new Node(a->value + b->value);
        newNode->left = add(a->left, b->left);
        newNode->right = add(a->right, b->right);
        return newNode;
    }

    Node* subtract(Node* a, Node* b) {
        if (!a || !b) return nullptr;
        Node* newNode = new Node(a->value - b->value);
        newNode->left = subtract(a->left, b->left);
        newNode->right = subtract(a->right, b->right);
        return newNode;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->value)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    int* getByIndex(Node* node, int& i, int index) {
        if (!node) return nullptr;
        int* res = getByIndex(node->left, i, index);
        if (res) return res;

        if (i == index) return &node->value;
        i++;

        return getByIndex(node->right, i, index);
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BinaryTree() : root(nullptr) {}

    BinaryTree(Node* r) : root(r) {}

    BinaryTree(const BinaryTree& other) {
        root = copy(other.root);
    }

    ~BinaryTree() {
        destroy(root);
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool isIsomorphicTo(const BinaryTree& other) {
        return isomorphic(this->root, other.root);
    }

    BinaryTree operator+(const BinaryTree& other) {
        if (!isIsomorphicTo(other)) {
            cout << "Drzewa nie są izomorficzne!\n";
            return BinaryTree();
        }
        return BinaryTree(add(this->root, other.root));
    }

    BinaryTree operator-(const BinaryTree& other) {
        if (!isIsomorphicTo(other)) {
            cout << "Drzewa nie są izomorficzne!\n";
            return BinaryTree();
        }
        return BinaryTree(subtract(this->root, other.root));
    }

    int& operator[](int index) {
        int i = 0;
        int* ptr = getByIndex(root, i, index);
        if (!ptr) {
            cout << "Błąd: indeks poza zakresem!\n";
            exit(1);
        }
        return *ptr;
    }

    void print() {
        inorder(root);
        cout << "\n";
    }
};

int main() {
    int n1, n2, val;
    cin >> n1;
    BinaryTree t1;
    for (int i = 0; i < n1; ++i) {
        cin >> val;
        t1.insert(val);
    }

    cin >> n2;
    BinaryTree t2;
    for (int i = 0; i < n2; ++i) {
        cin >> val;
        t2.insert(val);
    }

    if (t1.isIsomorphicTo(t2)) {
        cout << "Drzewa są izomorficzne.\n";
        BinaryTree t_add = t1 + t2;
        BinaryTree t_sub = t1 - t2;

        cout << "t1 + t2: ";
        t_add.print();

        cout << "t1 - t2: ";
        t_sub.print();
    } else {
        cout << "Drzewa nie są izomorficzne.\n";
    }

    return 0;
}
