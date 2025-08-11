class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        lis=[]
        for i in range(0,32):
            if n&(1<<i):
                lis.append(1<<i)
        
        s=len(lis)
        for i in range(1,s):
            lis[i]=lis[i-1]*lis[i]
        
        ans=[]
        for i in queries:
            if i[0]==0:
                ans.append(lis[i[1]]%1000000007)
            else:
                ans.append((lis[i[1]]//lis[i[0]-1])%1000000007)
            
        return ans