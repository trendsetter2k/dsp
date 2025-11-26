#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        key = val;
        left = right = NULL;
        height = 1;
    }
};

// Function to get height of node
int getHeight(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

// Function to get balance factor
int getBalance(Node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Right rotation (LL rotation)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotation (RR rotation)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert into AVL tree
Node* insertNode(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else
        return root; // duplicate keys not allowed

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check balance factor
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // unchanged node
}

// Search operation
bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (key == root->key) return true;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Inorder traversal for checking
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 10);

    cout << "Inorder traversal of AVL tree: ";
    inorder(root);

    int x = 20;
    if (search(root, x))
        cout << "\nElement " << x << " found!";
    else
        cout << "\nElement " << x << " not found!";

    return 0;
}
