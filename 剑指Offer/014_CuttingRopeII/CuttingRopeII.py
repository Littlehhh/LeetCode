class Solution:
    def cuttingRope(self, n: int) -> int:
        def remainder(x, a, p=1000000007):
            rem = 1
            while a>0:
                if a & 1:
                    rem = (rem * x) % p
                x = x**2 % p
                a //= 2
            return rem;

        if n <= 3: return n-1;
        a,b,p = n // 3, n % 3,1000000007
        rem = remainder(3, a-1)
        if b==0: return (rem * 3) % p
        if b==1: return (rem * 4) % p
        return (rem * 6) % p 
