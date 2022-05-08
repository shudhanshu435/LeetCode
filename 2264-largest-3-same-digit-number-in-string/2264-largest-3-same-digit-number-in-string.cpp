class Solution {
public:
    string largestGoodInteger(string num) {
        string s="";
        string ss;
        int cnt=0;
        for(int i=1;i<num.length()-1;i++){
            if((num[i-1]==num[i]) && (num[i]==num[i+1])){s+=num[i];
            cnt++;
        }
        }
        if(cnt==0)return ss;
        sort(s.begin(),s.end());
        cout<<s[s.length()-1]<<endl;
        ss+=s.substr(s.length()-1,1);
        ss+=s.substr(s.length()-1,1);
        ss+=s.substr(s.length()-1,1);
        return ss;
    }
};