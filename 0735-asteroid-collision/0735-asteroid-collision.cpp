class Solution {
public:
    vector<int> asteroidCollision(vector<int>& aa) {
        stack<int>s;
        int n=aa.size();
        for(int i=0;i<n;i++){
            bool pushkaru=1;
            while(!s.empty() and s.top()>0 and aa[i]<0){
                if(abs(s.top())<abs(aa[i])){
                    s.pop();
                }
                else if(abs(s.top())==abs(aa[i])){
                    pushkaru=0;
                    s.pop();
                    break;
                }
                else{
                    pushkaru=0;
                    break;
                }
            }
            if(pushkaru)s.push(aa[i]);
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};