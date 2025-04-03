class Solution:
    def modpo(self, b: int, e: int, mod: int) -> int:
        res=1
        while e:
            if e&1:
                res=(res*b)%mod
            b=(b*b)%mod
            e//=2
        return res
    def minNonZeroProduct(self, p: int) -> int:
        MOD=1000000007
        if p==1:
            return 1
        
        maxi=(1<<p)-1
        b=maxi-1
        power=(maxi-1)//2
        
        result=(self.modpo(b,power,MOD)*maxi)%MOD
        return result