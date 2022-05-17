func addStrings(num1 string, num2 string) string {
    ans := ""
    i := len(num1) - 1
    j := len(num2) - 1
    val := 0

    for i>=0 || j>=0 || val >0 {
        val1 := 0
        val2 := 0
        if( i>=0 ) {
            val1 = int(num1[i] - '0')
        }
        if( j>=0 ) {
            val2 = int(num2[j] - '0')
        }
        i--;
        j--;

        val += val1 + val2
        ans = strconv.Itoa(val%10) + ans
        val = val/10
    }

    return ans
}