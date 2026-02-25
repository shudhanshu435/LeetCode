class Solution {
public:
    int maxWidthRamp(vector<int>& pref) {
        stack<int>st;
        int n=pref.size()-1;
        for(int i=0;i<n;i++){
            if(st.empty() or pref[i]<=pref[st.top()])st.push(i);
        }
        
        int maxi=0;
        for(int i=n;i>=0;i--){
            while(!st.empty() and pref[i]>=pref[st.top()]){
                maxi=max(maxi,i-st.top());
                st.pop();
            }
        }
        
        
        return maxi;
    }
};
