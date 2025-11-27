#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) { val = v; left = right = nullptr; }
};

vector<TreeNode*> generateTreesRange(int start, int end) {
    vector<TreeNode*> res;
    if (start > end) {
        res.push_back(nullptr);
        return res;
    }
    for (int rootVal = start; rootVal <= end; ++rootVal) {
        vector<TreeNode*> leftTrees = generateTreesRange(start, rootVal - 1);
        vector<TreeNode*> rightTrees = generateTreesRange(rootVal + 1, end);
        for (TreeNode* L : leftTrees) {
            for (TreeNode* R : rightTrees) {
                TreeNode* root = new TreeNode(rootVal);
                root->left = L;
                root->right = R;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesRange(1, n);
}

string serializeLevel(TreeNode* root) {
    if (!root) return "[]";
    queue<TreeNode*> q;
    q.push(root);
    vector<string> out;
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            out.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            out.push_back("null");
        }
    }
    int i = (int)out.size() - 1;
    while (i >= 0 && out[i] == "null") --i;
    if (i < 0) return "[]";
    string s = "[";
    for (int j = 0; j <= i; ++j) {
        s += out[j];
        if (j != i) s += ",";
    }
    s += "]";
    return s;
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<TreeNode*> trees = generateTrees(n);
    cout << "[";
    for (size_t i = 0; i < trees.size(); ++i) {
        cout << serializeLevel(trees[i]);
        if (i + 1 < trees.size()) cout << ",";
    }
    cout << "]";
    for (TreeNode* t : trees) deleteTree(t);
    return 0;
}
