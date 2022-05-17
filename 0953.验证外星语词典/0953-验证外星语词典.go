func isAlienSorted(words []string, order string) bool {
    m := make(map[byte]int)
    for i:=0; i<len(order); i++ {
        m[order[i]] = i
    }

    for j:=1; j<len(words); j++ {
        for i:=0; i<len(words[j-1]); i++  {
            a := m[words[j-1][i]]
            b := -1
            if i < len(words[j])  {
                b = m[words[j][i]]
            }

            if a < b  {
                break
            }
            if a >b  {
                return false
            }
        }
    }

    return true
}