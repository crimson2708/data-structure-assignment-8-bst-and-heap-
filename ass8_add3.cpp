#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v){
        val = v;
        left = right = nullptr;
    }
};

int maxDepth(Node* root){
    if(root == nullptr) return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    if(l > r) return l + 1;
    else return r + 1;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        if(n == 0){
            cout << 0 << "\n";
            continue;
        }

        vector<Node*> nodes(n, nullptr);

        for(int i = 0; i < n; i++){
            if(arr[i] != -1) nodes[i] = new Node(arr[i]);
        }

        for(int i = 0; i < n; i++){
            if(nodes[i] != nullptr){
                int li = 2*i + 1;
                int ri = 2*i + 2;

                if(li < n) nodes[i]->left = nodes[li];
                if(ri < n) nodes[i]->right = nodes[ri];
            }
        }

        Node* root = nodes[0];

        cout << maxDepth(root) << "\n";

        for(int i = 0; i < n; i++){
            if(nodes[i] != nullptr) delete nodes[i];
        }
    }

    return 0;
}
