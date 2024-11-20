// class Solution {
// public:
// // recursion
//     int res=INT_MAX;
//     void solve(string& s, int k, int i, int j, int minute, vector<int>freq){
//         if(freq[0]>=k and freq[1]>=k and freq[2]>=k){
//             res=min(res,minute);
//             return;
//         }
//         if(i>j)return;

//         //delete from first and call solve
//         vector<int>left=freq;
//         left[s[i]-'a']+=1;
//         solve(s,k,i+1,j,minute+1,left);

//         //delete from last and call solve
//         vector<int>right=freq;
//         right[s[j]-'a']+=1;
//         solve(s,k,i,j-1,minute+1,right);
//     }
//     int takeCharacters(string s, int k) {
//         int i=0,j=s.size()-1,minute=0;
//         vector<int>freq(3,0);

//         solve(s,k,i,j,minute,freq);

//         return res==INT_MAX?-1:res;
//     }
// };


class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0,b=0,c=0,notdeleted=0,n=s.size();
        for(auto i:s){
            if(i=='a')a++;
            else if(i=='b')b++;
            else c++;
        }

        if(a<k or b<k or c<k)return -1;

        int i=0,j=0;
        while(j<n){
            if(s[j]=='a')a--;
            else if(s[j]=='b')b--;
            else c--;

            while(i<=j and (a<k or b<k or c<k)){
                if(s[i]=='a')a++;
                else if(s[i]=='b')b++;
                else c++;

                i++;
            }
            notdeleted = max(notdeleted, j-i+1);
            j++;
        }
        return n-notdeleted;
    }
};