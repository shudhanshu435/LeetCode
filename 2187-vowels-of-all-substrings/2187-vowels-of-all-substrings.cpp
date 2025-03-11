class Solution {
public:
    bool isVow(char ch){
        return (ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u');
    }
    long long countVowels(string word) {
        int n=word.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(isVow(word[i])){
                ans+=(i+1)*1ll*(n-i);
            }
        }
        return ans;
    }
};