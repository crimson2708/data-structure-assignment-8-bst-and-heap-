#include <iostream>
#include <vector>
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

void inorder(Node* root, vector<int>& arr) {
    if (root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= arr[i - 1])
            return false;
    }
    return true;
}

bool isBST(Node* root) {
    vector<int> arr;
    inorder(root, arr);
    return isSorted(arr);
}

int main() {
    Node* root1 = new Node(40);
    root1->left = new Node(20);
    root1->right = new Node(60);
    root1->left->left = new Node(10);
    root1->left->right = new Node(30);
    root1->right->left = new Node(50);
    root1->right->right = new Node(70);

    if (isBST(root1))
        cout << "Tree 1 is a BST" << endl;
    else
        cout << "Tree 1 is NOT a BST" << endl;

    Node* root2 = new Node(40);
    root2->left = new Node(20);
    root2->right = new Node(60);
    root2->left->left = new Node(10);
    root2->left->right = new Node(50);
    root2->right->left = new Node(30);
    root2->right->right = new Node(70);

    if (isBST(root2))
        cout << "Tree 2 is a BST" << endl;
    else
        cout << "Tree 2 is NOT a BST" << endl;

    return 0;
}
