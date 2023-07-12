#User function Template for python3

class Solution:
    def search(self, A : list, l : int, h : int, key : int):
        # l: The starting index
        # h: The ending index, you have to search the key in this range
        # Complete this function
        l=0
        m=0
        h=len(A)-1
        while l<=h:
            m=(l+h)//2
            if A[m]==key:
                return m
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
        return -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        A = [int(x) for x in input().split()]
        k = int(input())
        ob=Solution()
        print(ob.search(A, 0, n - 1, k))
# } Driver Code Ends