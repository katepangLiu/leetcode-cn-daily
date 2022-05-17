func diStringMatch(s string) []int {
	n := len(s)
	ans := make([]int, n+1)
	l := 0
	r := n

	for i, ch := range s {
		if ch == 'I' {
			ans[i] = l
			l++
		} else {
			ans[i] = r
			r--
		}
	}

	ans[n] = l
	return ans
}
