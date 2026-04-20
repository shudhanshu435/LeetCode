class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ret = 0, tmp = 0;
        for(size_t i = 0; i < colors.size(); ++i)
        {
            for(size_t j = i+1; j < colors.size(); ++j)
                if(colors[i] != colors[j])
                    tmp = j - i;
            ret = max(ret, tmp);
        }
        return ret;
    }
};