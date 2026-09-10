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
class BSTIterator {
        stack<TreeNode*> myStack;
        // reverse -> true -> before
        // reverse -> false -> next
        bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tempNode->right);
        else pushAll(tempNode->left);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode* node){
        for(;node != NULL;){
            myStack.push(node);
            if(reverse == true) node = node->right;
            else node = node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        //next
        BSTIterator l(root, false);
        //before
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j>k) j=r.next();
            else i=l.next();
        }
        return false;
    }
};