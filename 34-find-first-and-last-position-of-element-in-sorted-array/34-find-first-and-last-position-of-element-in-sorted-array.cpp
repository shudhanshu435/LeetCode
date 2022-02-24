class Solution
{
public:
    int binarySearch(vector<int> &nums, int x, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == x)
                return mid;
            if (nums[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int siz = nums.size();
        vector<int> vec;
        int index = binarySearch(nums, target, 0, siz - 1);
        if (index == -1)
        {
            vec.push_back(-1);
            vec.push_back(-1);
            return vec;
        }
        int t = index;

        for (int i = index; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                t = i;
            }
            else if (nums[i] < target)
            {
                break;
            }
        }
        vec.push_back(t);
        for (int i = index; i < siz; i++)
        {
            if (nums[i] == target)
            {
                t = i;
            }
            else if (nums[i] > target)
            {
                break;
            }
        }
        vec.push_back(t);

        return vec;
    }
};