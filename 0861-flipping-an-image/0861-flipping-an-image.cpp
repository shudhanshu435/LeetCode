class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            int x=0,y=image[0].size()-1;
            while(x<=y){
                if(x==y){
                    image[i][x]=!image[i][x];break;
                }
                int t=image[i][x];
                image[i][x]=!image[i][y];
                image[i][y]=!t;
                x++;y--;
            }
        }
        return image;
    }
};


/*

1 1 0
1 0 1
0 0 0

*/