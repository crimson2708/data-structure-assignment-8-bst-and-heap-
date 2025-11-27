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

Node* inorderSuccessor(Node* root, Node* x){
    Node* succ = NULL;
    while(root){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

int main(){
    Node* root = NULL;
    int a[] = {20,8,22,4,12,10,14};
    for(int i=0;i<7;i++) root = insertNode(root,a[i]);
    Node* x = root->left->right; 
    Node* s = inorderSuccessor(root,x);
    if(s) cout<<s->data;
    else cout<<"No successor";
    return 0;
}
