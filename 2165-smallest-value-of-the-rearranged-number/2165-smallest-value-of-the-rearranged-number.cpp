class Solution {
public:
    long long smallestNumber(long long num) {
        long long ans;
        string s=to_string(num);
        string ss="";
        sort(s.begin(),s.end());
        if(s[0]=='-'){
            ss+="-";
            for(int i=s.length()-1;i>0;i--){
                ss+=s[i];
            }
            //ans=stoi(ss);
            stringstream sss;  
              sss << ss;  
              sss >> ans;
        }
        else{
            cout<<s;
            for(int i=0;i<s.length();i++){
                if(s[i]!='0'){
                    swap(s[i],s[0]);
                    break;
                }
            }
            //ans=stoi(s);
            stringstream ss;  
              ss << s;  
              ss >> ans;
            
        }
        return ans;
        
    }
};