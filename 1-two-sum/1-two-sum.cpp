class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
map<int,int> mp;
for (int i = 0; i < nums.size(); i++)
{
mp[nums[i]]=i;
}
for (int i = 0; i < nums.size(); i++)
{
int complement = target - nums[i];
if (mp.find(complement)!=mp.end() && mp[complement] != i)
{
return vector<int> { i, mp[complement] };
}
}
// In case there is no solution, we'll just return null
return vector<int> {};
}
};
