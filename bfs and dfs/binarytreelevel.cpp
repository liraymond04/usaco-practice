#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class TreeNode {
public:
  TreeNode(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
  int data;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* constructTree() {
   TreeNode* root = new TreeNode(2);
   TreeNode* leftNode = new TreeNode(7);
   TreeNode* rightNode = new TreeNode(5);
   root->left = leftNode;
   root->right = rightNode;
   TreeNode* node = new TreeNode(2);
   leftNode->left = node;
   node = new TreeNode(6);
   leftNode->right = node;
   leftNode = node;
   node = new TreeNode(5);
   leftNode->left = node;
   node = new TreeNode(11);
   leftNode->right = node;
   node = new TreeNode(9);
   rightNode->right = node;
   rightNode = node;
   node = new TreeNode(4);
   rightNode->left = node;
   return root;
}

int dfs(TreeNode *root, int d) {
    int m = d;
    if (root->left != NULL) {
        m = max(m, dfs(root->left, d + 1));
    }
    if (root->right != NULL) {
        m = max(m, dfs(root->right, d + 1));
    }
    return m;
}

int bfs(TreeNode *root) {
    queue<pair<TreeNode*, int> > q;

    int m = 0;

    q.push({root, 0});
    pair<TreeNode*, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        m = max(m, cur.second);
        if (cur.first->left != NULL) {
            q.push({cur.first->left, cur.second + 1});
        }
        if (cur.first->right != NULL) {
            q.push({cur.first->right, cur.second + 1});
        }
    }

    return m;
}

int main() {
    TreeNode *root = constructTree();
    
    cout << dfs(root, 0) << "\n";
    cout << bfs(root) << "\n";

    return 0;
}