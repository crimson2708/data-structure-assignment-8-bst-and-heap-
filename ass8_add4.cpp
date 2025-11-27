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

vector<int> rightView(Node* root){
    vector<int> res;
    if(root == nullptr) return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; ++i){
            Node* cur = q.front(); q.pop();
            if(i == sz - 1) res.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return res;
}

int main(){
    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        if(n == 0){
            cout << "\n";
            continue;
        }
        vector<Node*> nodes(n, nullptr);
        for(int i = 0; i < n; ++i){
            if(arr[i] != -1) nodes[i] = new Node(arr[i]);
        }
        for(int i = 0; i < n; ++i){
            if(nodes[i] != nullptr){
                int li = 2*i + 1;
                int ri = 2*i + 2;
                if(li < n) nodes[i]->left = nodes[li];
                if(ri < n) nodes[i]->right = nodes[ri];
            }
        }
        Node* root = nodes[0];
        vector<int> view = rightView(root);
        for(size_t i = 0; i < view.size(); ++i){
            if(i) cout << " ";
            cout << view[i];
        }
        cout << "\n";
        for(int i = 0; i < n; ++i) if(nodes[i] != nullptr) delete nodes[i];
    }
    return 0;
}
