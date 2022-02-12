class Solution {
public:
    int countSegments(string s) {
        stringstream str(s); // Used for breaking words 
        string word; // to store individual words 
  
        int count = 0; 
        while (str >> word) 
           count++; 
        return count;
    }
};