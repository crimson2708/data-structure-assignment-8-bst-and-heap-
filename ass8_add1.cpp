#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) {
        data = v;
        left = right = NULL;
    }
};

Node* insertLevelOrder(vector<int>& arr, int i) {
    if(i >= arr.size()) return NULL;
    if(arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = insertLevelOrder(arr, 2*i + 1);
    root->right = insertLevelOrder(arr, 2*i + 2);
    return root;
}

int sumLeftLeaves(Node* root) {
    if(!root) return 0;
    int sum = 0;
    if(root->left && !root->left->left && !root->left->right)
        sum += root->left->data;
    sum += sumLeftLeaves(root->left);
    sum += sumLeftLeaves(root->right);
    return sum;
}

int main() {
    vector<int> arr = {3,9,20,-1,-1,15,7};
    Node* root = insertLevelOrder(arr, 0);
    cout << sumLeftLeaves(root);
    return 0;
}
