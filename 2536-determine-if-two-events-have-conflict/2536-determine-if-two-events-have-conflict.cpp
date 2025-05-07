class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if((event1[0]>=event2[0] and event1[0]<=event2[1]) or (event1[1]>=event2[0] and event1[1]<=event2[1]) or (event2[0]>=event1[0] and event2[0]<=event1[1]) or (event2[1]>=event1[0] and event2[1]<=event1[1]))return 1;
        return 0;
    }
};