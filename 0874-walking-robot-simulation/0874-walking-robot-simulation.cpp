class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>,bool>mp;
        for(auto &i:obstacles){
            mp[{i[0],i[1]}]=1;
        }
        int x=0,y=0;
        char dr='N';
        int ans=0;
        for(auto &i:commands){
            int m=i;
            if(i==-1){
                if(dr=='N')dr='E';
                else if(dr=='E')dr='S';
                else if(dr=='S')dr='W';
                else dr='N';
            }
            else if(i==-2){
                if(dr=='N')dr='W';
                else if(dr=='E')dr='N';
                else if(dr=='S')dr='E';
                else dr='S';
            }
            else{
                int move=i;
                if(dr=='N'){
                    for(int m=0;m<move;m++){
                        if(mp[{x,y+1}]==1)break;
                        y=y+1;
                        ans=max(ans,(x*x)+(y*y));
                    }
                }
                else if(dr=='E'){
                    for(int m=0;m<move;m++){
                        if(mp[{x+1,y}]==1)break;
                        x=x+1;
                        ans=max(ans,(x*x)+(y*y));
                    }
                }
                else if(dr=='S'){
                    for(int m=0;m<move;m++){
                        if(mp[{x,y-1}]==1)break;
                        y=y-1;
                        ans=max(ans,(x*x)+(y*y));
                    }
                }
                else{
                    for(int m=0;m<move;m++){
                        if(mp[{x-1,y}]==1)break;
                        x=x-1;
                        ans=max(ans,(x*x)+(y*y));
                    }
                }
            }
        }
        return ans;
    }
};