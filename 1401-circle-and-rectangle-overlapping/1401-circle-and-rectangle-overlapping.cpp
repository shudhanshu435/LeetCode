class Solution {
public:
    bool pos(int x, int y, int cx, int cy, int r){
        if((cx-x)*(cx-x) + (cy-y)*(cy-y) <= r*r)return 1;
        return 0;
    }
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        if(xc>=x1 and xc<=x2 and yc>=y1 and yc<=y2)return 1;
        for(int i=y1;i<=y2;i++){
            if(pos(x1,i,xc,yc,r) or pos(x2,i,xc,yc,r))return 1;
        }
        for(int i=x1;i<=x2;i++){
            if(pos(i,y1,xc,yc,r) or pos(i,y2,xc,yc,r))return 1;
        }
        return 0;
    }
};