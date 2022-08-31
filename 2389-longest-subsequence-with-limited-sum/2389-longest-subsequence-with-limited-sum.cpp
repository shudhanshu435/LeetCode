class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int sum=0;
        vector<int>vec;
        sort(nums.begin(),nums.end());
         for(int i=0;i<queries.size();i++){
            for(int j=0;j<nums.size();j++){
               sum+=nums[j];
               if(sum==queries[i]){vec.push_back(j+1);break;}
               else if(sum>queries[i]){vec.push_back(j);break;}
               else if(j==nums.size()-1){vec.push_back(j+1);break;}
           } 
        sum=0;
       } 
        return vec;
       
    }
};
