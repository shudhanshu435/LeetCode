class Solution {
public:
    
    int result(int n)
    {
        int g=n;
            while(n>0)
            {
                int t=n%10;
                if(t==0||g%t!=0)
                {
                    return -1;
                }
                n/=10;
            }
        return 1;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>vec;
        for(int i=left;i<=right;i++)
        {
            int n=result(i);
            if(n==1)vec.push_back(i);
        }
        return vec;
    }
};
