class Solution {
public:
    // int arr[100000002];
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // memset(arr, -1, sizeof(arr));
        unordered_set<string>pref;
        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            while(!s.empty()){
                // if(arr[s]==-1)
                pref.insert(s);
                // arr[stoi(s)]++;
                s.pop_back();
            }
        }
        sort(arr2.begin(),arr2.end());

        int max_len=0;

        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            while(s.length()>max_len){
                if(pref.find(s)!=pref.end())max_len=s.length();
                s.pop_back();
            }
        }

        return max_len;
    }
};