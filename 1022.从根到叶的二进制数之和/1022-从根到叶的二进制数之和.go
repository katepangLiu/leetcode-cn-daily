/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumRootToLeaf(root *TreeNode) int {
    sum := 0
    cur := 0

    dfs(root, &sum, cur)
    return sum
}

func dfs(root *TreeNode, sum *int, cur int) {
    if nil == root {
        return
    }

    cur = cur*2 + root.Val

    if nil == root.Left && nil == root.Right {
        *sum = *sum + cur
        return
    }

    dfs( root.Left, sum, cur )
    dfs( root.Right, sum, cur )
}