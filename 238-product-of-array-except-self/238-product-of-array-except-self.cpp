class Solution
{
public:
      vector<int> productExceptSelf(vector<int> &nums)
      {
            long long int mul = 1;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                  if (nums[i] == 0)
                        cnt++;
                  else
                        mul *= nums[i];
            }
            vector<int> vec(nums.size(), 0);
            if (cnt >= 2)
            {
                  return vec;
            }
            else if (cnt == 1)
            {
                  for (int i = 0; i < nums.size(); i++)
                  {
                        if (nums[i] == 0)
                              vec[i] = mul;
                  }
            }
          else {
              for(int i=0;i<nums.size();i++){
                  vec[i]=mul/nums[i];
              }
          }
            return vec;
      }
};