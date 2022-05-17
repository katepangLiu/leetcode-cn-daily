var max int     //���ֵ
var res []int   //���
var cur int     //��ǰ
var counter int //��ǰ����

func findMode(root *TreeNode) []int {
	res, max, cur, counter = []int{}, 1, 0, 0
	dfs(root)
	return res
}

func dfs(root *TreeNode) {
	if root != nil {
		dfs(root.Left)
		if root.Val != cur {
			counter = 0
		}
		counter++
		if max < counter {
			max = counter
			res = []int{root.Val}
		} else if max == counter {
			res = append(res, root.Val)
		}
		cur = root.Val
		dfs(root.Right)
	}
}