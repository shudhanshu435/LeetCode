class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        int n=s.length();
        vector<int>count(26,0); 
        for(int i=0;i<n;i++){ 
            count[s[i]-'a']++;
        }
        string res="";
        priority_queue<char> pq;
        
        for (int i=0;i<26;i++) {
            if(count[i]>0){
                char ch='a'+i;
                pq.push(ch);
            }
        }

        while(!pq.empty()){
            char c=pq.top();
            pq.pop();
            int freq=min(count[c-'a'],rl);
            res.append(freq,c);

            count[c-'a']-=freq;

            if(count[c-'a']>0 and !pq.empty()){
                char nextc=pq.top();
                pq.pop();
                res.push_back(nextc);
                count[nextc-'a']--;

                if(count[nextc-'a']>0)pq.push(nextc);

                pq.push(c);
            }
        }

        
        return res;
        // int n=s.length();
        // vector<int>count(26,0); //sc O(26)
        // for(int i=0;i<n;i++){ // O(n)
        //     count[s[i]-'a']++;
        // }

        // string result="";

        // int i=25; //O(n)
        // while(i>=0){
        //     if(count[i]==0){
        //         i--;
        //         continue;
        //     }

        //     char ch= 'a'+i;
        //     int freq=min(rl,count[i]);
        //     result.append(freq,ch);

        //     count[i]-=freq;

        //     if(count[i]>0){
        //         int j=i-1;

        //         while(j>=0 and count[j]==0)j--;//O(26)
        //         if(j<0)break;

        //         result.push_back('a'+j);
        //         count[j]--;
        //     }

        // }
        // return result;
    }
};

// aababab
// bbaabaa
// bbabaa