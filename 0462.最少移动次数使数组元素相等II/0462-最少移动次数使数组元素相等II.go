func minMoves2(nums []int) int {
    moves := 0
    //https://pkg.go.dev/sort
    sort.Ints(nums)
    mid := nums[len(nums)/2]
    for _,num := range nums {
        moves += abs( num - mid )
    }

    return moves
}

func abs(a int) int {
    if a < 0 {
        return 0 - a
    }
    return a
}