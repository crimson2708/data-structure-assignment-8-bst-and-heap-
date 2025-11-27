#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int v){
        data=v;
        left=right=NULL;
    }
};

Node* insertNode(Node* root, int val){
    if(root==NULL) return new Node(val);
    if(val < root->data) root->left = insertNode(root->left,val);
    else root->right = insertNode(root->right,val);
    return root;
}

Node* inorderPredecessor(Node* root, Node* x){
    Node* pred = NULL;
    while(root){
        if(x->data > root->data){
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

int main(){
    Node* root = NULL;
    int a[] = {20,8,22,4,12,10,14};
    for(int i=0;i<7;i++) root = insertNode(root,a[i]);
    Node* x = root->left->right; 
    Node* p = inorderPredecessor(root,x);
    if(p) cout<<p->data;
    else cout<<"No predecessor";
    return 0;
}
