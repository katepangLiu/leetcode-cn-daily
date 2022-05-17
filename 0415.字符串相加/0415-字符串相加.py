class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        ans = ""
        i = len(num1)-1
        j = len(num2)-1
        val = 0

        while i>=0 or j>=0 or val>0:
            val1 = int(num1[i]) if i>=0 else 0
            val2 = int(num2[j]) if j>=0 else 0
            i, j = i-1, j-1

            val = val + val1 + val2;
            ans = str(val%10) + ans
            val = val//10

        return ans