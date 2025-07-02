class Solution {
public:
    set<pair<int,pair<int,int>>>s;
    map<pair<int,int>,int>mp;

    int longpre(string&a, string&b){
        int m=a.size(),n=b.size();
        int i=0,cnt=0;
        while(i<m and i<n){
            if(a[i]!=b[i])break;
            cnt++;
            i++;
        }
        return cnt;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        if(n==1)return {0};

        for(int i=0;i<n-1;i++){
            int val=longpre(words[i],words[i+1]);
            s.insert({val,{i,i+1}});
            mp[{i,i+1}]=val;
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i==0){
                s.erase({mp[{i,i+1}],{i,i+1}});
                if(s.empty())ans.push_back(0);
                else ans.push_back((*s.rbegin()).first);
                s.insert({mp[{i,i+1}],{i,i+1}});
            }
            else if(i==n-1){
                s.erase({mp[{i-1,i}],{i-1,i}});
                if(s.empty())ans.push_back(0);
                else ans.push_back((*s.rbegin()).first);
                s.insert({mp[{i-1,i}],{i-1,i}});
            }
            else{
                s.erase({mp[{i-1,i}],{i-1,i}});
                s.erase({mp[{i,i+1}],{i,i+1}});
                s.insert({longpre(words[i-1],words[i+1]),{i-1,i+1}});
                if(s.empty())ans.push_back(0);
                else ans.push_back((*s.rbegin()).first);
                s.erase({longpre(words[i-1],words[i+1]),{i-1,i+1}});
                s.insert({mp[{i-1,i}],{i-1,i}});
                s.insert({mp[{i,i+1}],{i,i+1}});

            }
        }
        return ans;
    }
};