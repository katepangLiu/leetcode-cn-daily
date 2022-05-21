func repeatedNTimes(nums []int) int {
    s := make(map[int]bool);
    for _, v := range nums {
        if s[v] {
            return v;
        }
        s[v] = true;
    }

    // Never
    return -1;
}