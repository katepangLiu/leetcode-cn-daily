/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function isUnivalTree(root: TreeNode | null): boolean {
    if ( null == root ) {
        return true;
    }

    return dfs(root, root.val);
};

function dfs(root: TreeNode, val: number) : boolean {
    if ( null == root ) {
        return true;
    }

    if( val != root.val ) {
        return false;
    }

    return dfs(root.left, val) && dfs(root.right, val);
}