class Solution:
    def cuttingRope(self, n: int) -> int:
        f = [0]*(n+1)
        for i in range(2, n+1) :
            for j in range (1, i) :
                f[i] = max(f[i], j*(i-j), j*f[i-j])
        
        return f[n]