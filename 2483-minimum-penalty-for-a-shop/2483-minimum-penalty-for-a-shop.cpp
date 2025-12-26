class Solution {
public:
    int bestClosingTime(string customers) {
        int come=0,nt=0;
        int n=customers.size();
        for(auto &i:customers)if(i=='Y')come++;
        int pen=come;
        int ans=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='N')nt++;
            else come--;
            if(come+nt < pen){
                ans=i+1;
                pen=come+nt;
            }
        }
        return ans;
    }
};