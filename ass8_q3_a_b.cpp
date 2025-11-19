#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int key) {
    if (root == NULL) 
        return new Node(key);

    if (key < root->data) 
        root->left = insertNode(root->left, key);
    else if (key > root->data) 
        root->right = insertNode(root->right, key);

    return root;
}

Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) 
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }

    return root;
}

void inorderPrint(Node* root) {
    if (root == NULL) 
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Inorder after inserts: ";
    inorderPrint(root);
    cout << endl;

    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inorderPrint(root);
    cout << endl;

    root = deleteNode(root, 30);
    cout << "After deleting 30: ";
    inorderPrint(root);
    cout << endl;

    root = deleteNode(root, 50);
    cout << "After deleting 50: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
