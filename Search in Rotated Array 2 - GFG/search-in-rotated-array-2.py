#User function Template for python3

class Solution:
    def Search(self, n, A, key):
        # code here
        l=0
        m=0
        h=n-1
        while l<=h:
            m=(l+h)//2
            if A[m]==key:
                return 1
            if A[l]==A[m] and A[m]==A[h]:
                l+=1
                h-=1
                continue
            if A[l]<=A[m]:
                if A[l]<=key and key<=A[m]:
                    h=m-1
                else:
                    l=m+1
            else:
                if A[m]<=key and key<=A[h]:
                    l=m+1
                else:
                    h=m-1
        return 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        ans = ob.Search(n, arr, k)
        print(ans)
        tc -= 1
# } Driver Code Ends