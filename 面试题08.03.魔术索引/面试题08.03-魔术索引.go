func findMagicIndex(nums []int) int {
    n := len(nums)
    i := 0
    for i < n {
        if nums[i] == i {
            return i
        }
        //����������һ����������������;
        i = max(i+1, nums[i]) 
    }
    return -1
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}