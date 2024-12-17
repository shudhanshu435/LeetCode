class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        // map<char,int,greater<int>>mp;
        // for(char i:s){
        //     mp[i]++;
        // }
        // string ans="";
        // priority_queue<pair<char, int>> pq;
        
        // for (auto pair : mp) {
        //     pq.push({pair.first, pair.second});
        // }

        // while(1){
        //     char c=pq.top().first;
        //     int cc=pq.top().second;
        //     if(cc<=rl){
        //         while(cc--){
        //             ans+=c;
        //         }
        //     }
        //     else{
        //         cc=cc-rl;
        //         while(rl--){
        //             ans+=c;
        //         }

        //     }
        // }

        
        // return "";
        int n=s.length();
        vector<int>count(26,0);
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }

        string result="";

        int i=25;
        while(i>=0){
            if(count[i]==0){
                i--;
                continue;
            }

            char ch= 'a'+i;
            int freq=min(rl,count[i]);
            result.append(freq,ch);

            count[i]-=freq;

            if(count[i]>0){
                int j=i-1;

                while(j>=0 and count[j]==0)j--;
                if(j<0)break;

                result.push_back('a'+j);
                count[j]--;
            }

        }
        return result;
    }
};

// aababab
// bbaabaa
// bbabaa