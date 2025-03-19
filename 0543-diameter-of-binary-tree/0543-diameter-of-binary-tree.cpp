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
   int helper(TreeNode* root,int &curr){
     if(root==NULL){
            return 0;
        }
        int left =helper(root->left,curr);
        int right =helper(root->right,curr);

        curr=max(curr,left+right);

        return 1+max(left,right);
    
   }

    int diameterOfBinaryTree(TreeNode* root) {
       int curr =0;
       helper(root,curr);
       return curr;
    }
};