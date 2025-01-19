class Solution {
public:
    int trapRainWater(vector<vector<int>>& matrix) {
        int row=matrix.size();//no of row
        int col=matrix[0].size();//no of column

        //create a visited 2d vector to check for already visited coordinate
        vector<vector<int>>vis(row,vector<int>(col,0));
            
        //create a priority queue to find smallest boundary element with its coordinate
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        //first int is for the smallest boundary element and next two int for its coordinate

        int stored_water=0;

        //As boundary elements can't store on themselves so we'll mark them visited
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 || i==row-1 || j==0 || j==col-1){
                    pq.push({matrix[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }

        int minbound=0,rr=0,cc=0;
        while(!pq.empty()){
            int currmin=pq.top().first;
            int r=pq.top().second.first;//x coordinate
            int c=pq.top().second.second;//y coordinate
            minbound=max(minbound,currmin);
            pq.pop();
            
            //for each min element, we'll check their neighbour
            //if neighbour element is less than the boundary element then it'll store (min_ele-neighbour) water, and we'll replace it with current boundary element
            //if neighbour is greater then we'll simple push into the priority queue and do nothing as it can store more water than the current min element

            //Now traverse for each boundary element

            //left, r=r,c=c-1
            rr=r,cc=c-1;
            if(rr>=0 and rr<row and cc>=0 and cc<col and vis[rr][cc]==false){
                pq.push({matrix[rr][cc],{rr,cc}});
                vis[rr][cc]=true;
                if(matrix[rr][cc]<minbound){
                    stored_water+=minbound-matrix[rr][cc];//adding differnce so to store water
                }
            }

            // right, r=r,c=c+1
            rr=r,cc=c+1;
            if(rr>=0 and rr<row and cc>=0 and cc<col and vis[rr][cc]==false){
                pq.push({matrix[rr][cc],{rr,cc}});
                vis[rr][cc]=true;
                if(matrix[rr][cc]<minbound){
                    stored_water+=minbound-matrix[rr][cc];//adding differnce so to store water
                }
            }

            // up, r=r-1,c=c
            rr=r-1,cc=c;
            if(rr>=0 and rr<row and cc>=0 and cc<col and vis[rr][cc]==false){
                pq.push({matrix[rr][cc],{rr,cc}});
                vis[rr][cc]=true;
                if(matrix[rr][cc]<minbound){
                    stored_water+=minbound-matrix[rr][cc];//adding differnce so to store water
                }
            }

            // down, r=r+1,c=c
            rr=r+1,cc=c;
            if(rr>=0 and rr<row and cc>=0 and cc<col and vis[rr][cc]==false){
                pq.push({matrix[rr][cc],{rr,cc}});
                vis[rr][cc]=true;
                if(matrix[rr][cc]<minbound){
                    stored_water+=minbound-matrix[rr][cc];//adding differnce so to store water
                }
            }
        }
        return stored_water;
    }
};