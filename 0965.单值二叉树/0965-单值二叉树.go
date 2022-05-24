/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isUnivalTree(root *TreeNode) bool {
    if root == nil  {
        return true
    }

    val := root.Val
    return dfs(root, val)
}

func dfs( root *TreeNode, val int ) bool {
    if root == nil {
        return true
    }

    if val != root.Val {
        return false
    }

    return dfs(root.Left, val) && dfs(root.Right, val)    

}