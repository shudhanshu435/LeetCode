class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int size = edges.size();
        vector<int>distance1(size,-1);
        vector<int>distance2(size,-1);
        
        int x=1;
        while(node1 != -1){
            if(distance1[node1] != -1) break;
            distance1[node1] += x;
            x++;
            node1 = edges[node1];
        }
        x =1;
        while(node2 != -1){ 
            if(distance2[node2] != -1) break;
            distance2[node2]+= x;
            x++;
            node2 = edges[node2];
        }
        int mini = INT_MAX;
        int ans=-1;
		// finding optimal answer
        for(int i=0; i<size;i++){
            if(distance1[i] != -1 && distance2[i] != -1)
                if(mini > max(distance1[i],distance2[i]) )
                {
                    mini = max(distance1[i],distance2[i]);
                    ans = i;
                }
        }
        
        return ans;
    }
};