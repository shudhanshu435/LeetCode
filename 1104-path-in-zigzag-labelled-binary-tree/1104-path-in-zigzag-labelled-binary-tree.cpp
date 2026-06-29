class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int x=log2(label);
        if(label==1)return {1};
        vector<int>ans;
        int nl=0;
        int diff=label-(1<<x);
        ans.push_back(label);
        nl=diff/2;
        bool b=1;
        x--;
        while(x>=0){
            int val=(1<<x)+nl;
            int st=(1<<x);
            if(b){
                int fl=(1<<(x+1))-1-val;
                ans.push_back(st+fl);
            }
            else ans.push_back(val);
            nl/=2;
            b=!b;
            x--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



// 1 
// 2 3
// 4 5 6 7
// 8 9 10 11 12 13 14 15