/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfsHelper(TreeNode *root, int x, int y, int depth, TreeNode *parent, vector<int> &infoDepth, vector<TreeNode *> &infoParent) {
        if (root == NULL) 
            return;
        
        if (root->val == x || root->val == y) {
            infoDepth.push_back(depth);
            infoParent.push_back(parent);
        }
        
        dfsHelper(root->left, x, y, depth + 1, root, infoDepth, infoParent);
        dfsHelper(root->right, x, y, depth + 1, root, infoDepth, infoParent);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) 
            return false;
        
        vector<int> infoDepth;
        vector<TreeNode *> infoParent;
        dfsHelper(root, x, y, 0, NULL, infoDepth, infoParent);
        
        if (infoParent[0] && infoParent[1])
            return (infoDepth[0] == infoDepth[1]) && (infoParent[0] != infoParent[1]);
        else
            return false;
        
    }
};
//Dung bfs de ra duoc ds con cung 1 level
// kiem tra ds xem co x y hay khong
// neu duyet het ma khong co thi tra ve false
// neu co thi kiem tra tiep x y co cung cha hay khong