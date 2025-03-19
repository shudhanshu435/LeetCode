class Solution {
public:
    int twoEggDrop(int n) {
        n=n*2;
        int i=1;
        while(i*(i+1)<n)i++;
        return i;
    }
};