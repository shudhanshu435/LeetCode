class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, k = 0; // i and j are pointers, k is the offset
        
        while (j + k < s.size()) {
            if (s[i + k] == s[j + k]) {
                k++; // Move the offset if characters match
            } else if (s[i + k] > s[j + k]) {
                j = j + k + 1; // Move j to skip the current comparison
                k = 0; // Reset offset
            } else {
                i = max(i + k + 1, j); // Move i to the next position
                j = i + 1; // Ensure j is always ahead of i
                k = 0; // Reset offset
            }
        }
        
        return s.substr(i);
    }
};