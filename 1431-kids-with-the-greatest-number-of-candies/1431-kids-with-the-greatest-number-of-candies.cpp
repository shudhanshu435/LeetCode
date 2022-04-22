class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *max_element(candies.begin(),candies.end());
		int n=candies.size();
		vector<bool>ans;
		for(int i=0;i<n;i++){
			candies[i]=candies[i]+extraCandies;
			if(candies[i]>=m)			ans.push_back(true);
			else
				ans.push_back(false);
		}
		return ans;
        
        
    }
};