class Solution {
public:
    int countCollisions(string dir) {
        int cnt=0;
        int n=dir.size();
        int i=0,j=n-1;
        while(i<n and dir[i]=='L')i++;
        while(j>=0 and dir[j]=='R')j--;
        if(i>j)return 0;
        for(;i<j;i++){
            if(dir[i]=='S' and (dir[i+1]=='S' or dir[i+1]=='R'))continue;
            if(dir[i]=='S')cnt++;
            else if(dir[i]=='R' and dir[i+1]=='L')cnt+=2;
            else if(dir[i]=='R' and (dir[i+1]=='S' or dir[i+1]=='R'))cnt++;
            else if(dir[i]=='L' and (dir[i+1]=='S' or dir[i]=='R'))continue;
            if(dir[i]=='L' and dir[i+1]=='L')cnt++;
        }
        return cnt;
    }
};

// SRLRLLR