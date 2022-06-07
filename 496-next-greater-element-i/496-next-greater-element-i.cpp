class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> vec;
        for (int i = 0; i < nums1.size(); i++)
        {
            auto match = find(nums2.begin(), nums2.end(), nums1[i]);
            int m = match - nums2.begin();
            cout<<m<<endl;
            int cnt = 0;
            for (int j = m+1; j < nums2.size(); j++)
            {
                if (nums2[j] > nums2[m])
                {
                    vec.push_back(nums2[j]);
                    cnt++;
                    break;
                }
            }
            if (cnt == 0)
                vec.push_back(-1);
        }
        return vec;
    }
};