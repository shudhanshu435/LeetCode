class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        if (mat.empty() || mat[0].empty()) 
            return false;
        
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = n - 1, targetRow = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (t >= mat[mid][0] && t <= mat[mid][m - 1]) {
                targetRow = mid; 
                break;
            } else if (t < mat[mid][0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (targetRow == -1) 
            return false; 
        
        low = 0, high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mat[targetRow][mid] == t) {
                return true;  
            } else if (mat[targetRow][mid] < t) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return false;  // Element not found
    }
};