class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int count=0,cnt=0;
        for(int i=0;i<ransomNote.length();i++){
            for(int j=0;j<magazine.length();j++){
                if(ransomNote[i]==magazine[j]){
                    magazine.erase(j,1);
                    count++;
                    break;
                }
                
            }
        }
        if(count==ransomNote.length())return 1;
        else  return 0;
    }
};