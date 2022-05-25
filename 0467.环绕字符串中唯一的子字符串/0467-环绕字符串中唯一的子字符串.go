func findSubstringInWraproundString(p string) int {
    ans := 0
    dp := [26]int{0}
    cnt := 0

    for i, _ := range p {
        if i == 0 {
            cnt = 1
        } else if( ( p[i] - p[i-1] + 26) % 26 == 1 ) {
            cnt++
        } else {
            cnt = 1
        }
        j := p[i] - 'a'
        dp[j] = max(dp[j], cnt)
    }

    for _, cnt := range dp {
        ans += cnt
    }
    return ans
}

func max( a, b int) int {
    if a < b {
        return b
    }
    return a
}