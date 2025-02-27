class Solution {
public:
    int calculate(string s) {
        string a="";
        int n=s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')a+=s[i];
        }
        s=a;
        // cout<<s<<endl;
        // a.clear();
        // for(int i=0;i<s.length();i++){
        //     a+=s[i];
        //     if(i<n-1 and s[i]=='(' and (s[i+1]=='+' or s[i+1]=='-')){
        //         a+='0';
        //     }
        // }
        // s=a;
        // cout<<s<<endl;
        stack<char>st;
        long long ans=0,numm;
        for(int i=0;i<s.length();i++){
            if(s[i]!=')')st.push(s[i]);
            else{
                numm=0;
                ans=0;
                while(!st.empty() and st.top()!='('){
                    // char ch=st.top();
                    // long long num=0;
                    string nunu="";
                    while(!st.empty() and isdigit(st.top())){
                        nunu+=st.top();
                        st.pop();
                    }
                    reverse(nunu.begin(),nunu.end());
                    // cout<<nunu<<endl;
                    // cout<<nunu<<endl;
                    if (!nunu.empty()) {
                        numm = stoi(nunu);
                    } else {
                        continue;
                    }
                    if(!st.empty() and st.top()=='+'){
                        ans=ans+numm;
                        st.pop();
                    }
                    else if(!st.empty() and st.top()=='-'){
                        ans=ans-numm;
                        st.pop();
                    }
                    else if(!st.empty() and st.top()=='(')ans=ans+numm;
                    // ans=numm+ans;
                    // cout<<ans<<endl;
                }
                st.pop();
                long long rev=0;
                // cout<<ans<<endl;
                if(ans<0){
                    if(!st.empty() and st.top()=='+'){
                        st.pop();
                        st.push('-');
                    }
                    else if(!st.empty() and st.top()=='-'){
                        st.pop();
                        st.push('+');
                    }
                    else if(st.empty())st.push('-');
                    ans=(-1)*(ans);
                }
                string ss=to_string(ans);
                for(int i=0;i<ss.size();i++)st.push(ss[i]);
                // cout<<st.top()<<endl;

            }
        }
        // while(!st.empty()){cout<<st.top();st.pop();}
        // cout<<endl;
        ans=0;
        while(!st.empty()){
            long long num=0;
            string nunu="";
            while(!st.empty() and isdigit(st.top())){
                nunu+=st.top();
                st.pop();
            }
            reverse(nunu.begin(),nunu.end());
            // cout<<nunu<<endl;
            if (!nunu.empty()) { 
                numm = stoi(nunu);
            } else {
                continue;
            }
            if(!st.empty() and st.top()=='+'){
                ans=ans+numm;
                st.pop();
            }
            else if(!st.empty() and st.top()=='-'){
                ans=ans-numm;
                st.pop();
            }
            // else if(!st.empty() and st.top()=='(')ans=ans+numm;
            else if(st.empty())ans+=numm;
            // ans=numm+ans;
            
        }
        return ans;
    }
};

/*
352
253

*/