class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int siz=matrix.size();
        int l=matrix[0][0];
        int h=matrix[siz-1][siz-1];
        while(l<h){
            int mid=l+(h-l)/2;
            int cnt=0;
            for(int i=0;i<siz;i++){
                cnt += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            
            if(cnt<k)l=mid+1;
            else h=mid;
        }
        return l;
    }
};