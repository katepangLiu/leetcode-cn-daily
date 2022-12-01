func nearestValidPoint(x int, y int, points [][]int) int {
    var ans int = -1
    minDis := math.MaxInt

    for i, p := range points {
        a := p[0]
        b := p[1]
        dis := math.MaxInt
        if a==x {
            dis = abs(b-y)
        } else if b==y {
            dis = abs(a-x)
        }

        if dis < minDis {
            minDis = dis
            ans = i
        }
    }

    return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}