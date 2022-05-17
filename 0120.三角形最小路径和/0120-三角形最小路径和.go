func minimumTotal(triangle [][]int) int {
    n := len(triangle)
    
    for i:=1; i<n; i++ {
        for j:=0; j<=i; j++ {
            if j == 0 {
                triangle[i][j] += triangle[i-1][j]
            } else if j == i {
                triangle[i][j] += triangle[i-1][j-1]
            } else {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j])
            }
        }
    }

    minTotal := triangle[n-1][0]
    for j:=1; j<n; j++ {
        minTotal = min(triangle[n-1][j], minTotal)
    }

    return minTotal
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}