class Solution {
public:
    #define p pair<int,int>
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<p,vector<p>,greater<p>>pq; //min heap
        for(int i=0;i<n;i++){
            pq.push(make_pair(nums[i],i));
        }
        long long score=0;
        vector<bool>visited(n,false);
        while(!pq.empty()){
            p temp = pq.top();
            pq.pop();
            int ele=temp.first;
            int ind=temp.second;
            if(visited[ind]==false){
                score+=ele;
                visited[ind]=true;
                if(ind-1>=0 and visited[ind-1]==false)visited[ind-1]=true;
                if(ind+1<n and visited[ind+1]==false)visited[ind+1]=true;
            }
        }

        return score;
    }
};