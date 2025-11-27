#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v){ val = v; left = right = nullptr; }
};

Node* buildRec(const vector<int>& inorder, int iL, int iR, const vector<int>& postorder, int pL, int pR, const unordered_map<int,int>& idx){
    if(iL > iR) return nullptr;
    int rootVal = postorder[pR];
    Node* root = new Node(rootVal);
    int inRoot = idx.at(rootVal);
    int leftSize = inRoot - iL;
    root->left = buildRec(inorder, iL, inRoot-1, postorder, pL, pL+leftSize-1, idx);
    root->right = buildRec(inorder, inRoot+1, iR, postorder, pL+leftSize, pR-1, idx);
    return root;
}

Node* buildTree(const vector<int>& inorder, const vector<int>& postorder){
    int n = inorder.size();
    if(n == 0) return nullptr;
    unordered_map<int,int> idx;
    for(int i=0;i<n;i++) idx[inorder[i]] = i;
    return buildRec(inorder, 0, n-1, postorder, 0, n-1, idx);
}

void printLevelOrder(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    bool first = true;
    while(!q.empty()){
        Node* cur = q.front(); q.pop();
        if(!first) cout << " ";
        first = false;
        cout << cur->val;
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    cout << "\n";
}

void deleteTree(Node* root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    int n;
    if(!(cin >> n)) return 0;
    vector<int> inorder(n), postorder(n);
    for(int i=0;i<n;i++) cin >> inorder[i];
    for(int i=0;i<n;i++) cin >> postorder[i];
    Node* root = buildTree(inorder, postorder);
    printLevelOrder(root);
    deleteTree(root);
    return 0;
}
