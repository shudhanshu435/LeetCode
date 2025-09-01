class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int cnt=1;
        int k=0;
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1])cnt++;
            else{
                if(k<n)chars[k++]=chars[i-1];
                else break;
                if(cnt>1){
                    string s=to_string(cnt);
                    for(auto &i:s){
                        if(k<n)chars[k++]=i;
                        else break;
                    }
                }
                cnt=1;
            }
        }
        // cout<<cnt<<endl;
        if(cnt==1 and k<n)chars[k++]=chars[n-1];
        else if(cnt>1 and k<n){
            chars[k++]=chars[n-1];
            // cout<<"sdf";
            // cout<<k<<endl;
            string s=to_string(cnt);
            // cout<<s<<endl;
            for(auto i:s){
                if(k<n)chars[k++]=i;
                else break;
            }
        }
        return min(k,n);
    }
};