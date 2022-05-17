func intersect(nums1 []int, nums2 []int) []int {
    if( len(nums1) > len(nums2) ) {
        return intersect(nums2, nums1)
    }

    m := map[int]int{}
    for _,num := range nums1 {
        m[num]++
    }

    ans := []int{}
    for _,num := range nums2 {
        if( m[num] > 0 ) {
            ans = append( ans, num);
            m[num]--
        }
    }

    return ans
}