/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func convertBST(root *TreeNode) *TreeNode {
    var dfs func(*TreeNode)
    accumulator := 0
    
    dfs = func(root *TreeNode) { 
        if root == nil {
            return
        }

        dfs(root.Right)
        accumulator  += root.Val
        root.Val = accumulator
        dfs(root.Left)
    }

    dfs(root)
    return root
}