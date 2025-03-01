def powMod(b,e):
    ans=1
    while e>0:
        if e&1:
            ans=(ans*b)%1337
            e-=1
        else:
            b=(b*b)%1337
            e//=2
    return ans
class Solution:

    def superPow(self, a: int, b: List[int]) -> int:
        num=0
        for i in b:
            num=(num*10)+i
        # print(num)
        return powMod(a,num)