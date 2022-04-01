class Solution {
public:
    void reverseString(vector<char>& s) {
        
        vector<char>arr;
        int m=s.size();
        for(int i=0;i<m;i++)
        {
            arr.push_back(s[m-1-i]);
        }
         for(int i=0;i<m;i++)
        {
            s[i]=arr[i];
        }
    }
};