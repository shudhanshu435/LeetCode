class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        stack<int>s;
        int n=bits.size();
        if(bits[n-1]!=0)return 0;
        bits.pop_back();
        for(int i=0;i<n-1;i++){
            if(bits[i]==0){
                if(!s.empty())s.pop();
            }
            else{
                if(!s.empty())s.pop();
                else s.push(1);
            }
        }
        return s.size()==0;
    }
};