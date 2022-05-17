func findMaxConsecutiveOnes(nums []int) int {
    maxCount := 0
    count := 0

    for _,num := range nums {
        if 1 == num {
            count++
        } else {
            maxCount = max( maxCount, count)
            count = 0;
        }
    }

    maxCount = max( maxCount, count)
    return maxCount
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}