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
    void inorder(TreeNode* root, vector<int>& sortArr){
        if(root==NULL) return;
        inorder(root->left, sortArr);
        sortArr.push_back(root->val);
        inorder(root->right, sortArr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> sortArr;
        inorder(root,sortArr);
        int l=0, r=sortArr.size()-1;
        while(l<r){
            if(sortArr[l]+sortArr[r]==k) return true;
            else if(sortArr[l]+sortArr[r]>k) r--;
            else l++;
        }
        return false;
    }
};