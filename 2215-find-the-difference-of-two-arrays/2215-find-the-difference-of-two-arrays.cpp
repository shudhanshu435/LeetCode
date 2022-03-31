class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> vec;
        vector<int> vec1, vec2;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (count(nums2.begin(), nums2.end(), nums1[i]))
                continue;
            else
            {
                if (count(vec1.begin(), vec1.end(), nums1[i]))
                    continue;
                else
                    vec1.push_back(nums1[i]);
            }
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (count(nums1.begin(), nums1.end(), nums2[i]))
                continue;
            else
            {
                if (count(vec2.begin(), vec2.end(), nums2[i]))continue;
                else vec2.push_back(nums2[i]);
            }
        }
        vec.push_back(vec1);
        vec.push_back(vec2);
        return vec;
    }
};