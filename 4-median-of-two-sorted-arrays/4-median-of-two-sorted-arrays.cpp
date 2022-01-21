class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> vec;
        int len = nums1.size() + nums2.size();
        if (nums1.size() == 0 && nums2.size() != 0)
        {
            for (int i = 0; i < nums2.size(); i++)
            {
                vec.push_back(nums2[i]);
            }
        }
        else if (nums2.size() == 0 && nums1.size() != 0)
        {
            for (int i = 0; i < nums1.size(); i++)
            {
                vec.push_back(nums1[i]);
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (i < nums1.size())
                    vec.push_back(nums1[i]);
                else
                    vec.push_back(nums2[i - nums1.size()]);
            }
        }
            sort(vec.begin(), vec.end());
            int s=vec.size();
            int i = s / 2;
            double res;
            if (s & 1)
                res = vec[i];
            else
            {
                double d = (vec[i] + vec[i - 1]);
                res = d / 2;
            }
            return res;
    }
};