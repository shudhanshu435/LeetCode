class Solution
{
public:
    int closestTarget(vector<string> &words, string target, int startIndex)
    {
        int v=0,m=0,n=0;
        int len=words.size();
        int dis = 0, mini = INT_MAX;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == target)
            {
                v++;
                if(i<startIndex){m=startIndex-i;n=len-startIndex+i;}
                else {m=i-startIndex;n=len-i+startIndex;}
                dis=min(m,n);
                if(dis<=mini)mini=dis;
                // cout<<mini;
            }
        } // 0 4
        if(v==0)return -1;
        return mini;
    }
};