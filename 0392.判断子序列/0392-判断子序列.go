func isSubsequence(s string, t string) bool {
    m := len(s)
    n := len(t)

    i := 0
    j := 0

    for i<m && j<n {
        if s[i] == t[j] {
            i++
        }
        j++
    }

    return i == m
}