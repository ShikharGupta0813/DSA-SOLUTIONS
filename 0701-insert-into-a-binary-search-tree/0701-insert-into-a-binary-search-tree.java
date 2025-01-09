/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        // Create the new node to be inserted
        TreeNode target = new TreeNode(val);
        // If the tree is empty, return the new node as the root
        if (root == null) return target;
        // Perform recursive DFS to insert the node
        dfs(root, target);
        // Return the root after insertion
        return root;
    }

    public TreeNode dfs(TreeNode node, TreeNode target) {
        // Base case: If we reach a null position, insert the target node here
        if (node == null) {
            return target;
        }
        // If the target value is less than the current node, traverse left
        else if (target.val < node.val) {
            node.left = dfs(node.left, target);
        } 
        // If the target value is greater than or equal to the current node, traverse right
        else {
            node.right = dfs(node.right, target);
        }
        // Return the current node to maintain the structure
        return node;
    }
}