class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(),n.end());
        cout<<n[n.length()-1];
        int m=(int)n[n.length()-1]-48;
        return m;
    }
};