class Solution {
public:
    int maxArea(vector<int>& h) {
        int i=0,j=h.size()-1;
        int ans=0;
        while(i<j){
            ans=max(ans,(j-i)*min(h[i],h[j]));
            if(h[i]==h[j]){i++;j--;}
            else if(h[i]<h[j])i++;
            else j--;
            cout<<ans<<endl;
        }
        return ans;
    }
};