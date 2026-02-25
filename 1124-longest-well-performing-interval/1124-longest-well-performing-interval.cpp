class Solution {
public:
    int longestWPI(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=8)arr[i]=-1;
            else arr[i]=1;
        }
        vector<int>pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+arr[i];
        }
        // -1 -1 1  1 -1 1 1 -1
        // -1 -2 -1 0 -1 0 1 0
        
        //stack
        // 0 1 
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty() or pref[i]<pref[st.top()])st.push(i);
        }
        
        int maxi=0;
        for(int i=n;i>=0;i--){
            while(!st.empty() and pref[i]>pref[st.top()]){
                maxi=max(maxi,i-st.top());
                st.pop();
            }
        }
        
        
        return maxi;
    }
};