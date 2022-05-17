/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var convertBST = function(root) {
    let accumulator = 0;
    var dfs = (root) => {
        if(root == null) {
            return
        }
        dfs(root.right);
        accumulator += root.val;
        root.val = accumulator;
        dfs(root.left);
    };
    dfs(root);
    return root;
};