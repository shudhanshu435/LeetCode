class TaskManager {
public:
    struct cmp{
        bool operator()(const tuple<int,int,int>&a, const tuple<int,int,int>&b)const{
            auto [pa,ta,ua]=a;
            auto [pb,tb,ub]=b;
            if(pa!=pb)return pa>pb;
            if(ta!=tb)return ta>tb;
            return ua<ub;
        }
    };
    set<tuple<int,int,int>,cmp>gl;
    unordered_map<int,set<pair<int,int>>>mp; //userid, taskid, priority
    unordered_map<int,pair<int,int>>mp2; //taskid, userid, priority

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &v:tasks){
            mp[v[0]].insert({v[1],v[2]});
            mp2[v[1]]={v[0],v[2]};
            gl.insert({v[2],v[1],v[0]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[userId].insert({taskId,priority});
        mp2[taskId]={userId,priority};
        gl.insert({priority,taskId,userId});
    }
    
    void edit(int taskId, int newPriority) {
        int a=mp2[taskId].first;
        int b=mp2[taskId].second;
        mp[a].erase({taskId,b});
        mp[a].insert({taskId,newPriority});
        gl.erase({b,taskId,a});
        gl.insert({newPriority,taskId,a});
        mp2[taskId]={a,newPriority};
    }
    
    void rmv(int taskId) {
        int a=mp2[taskId].first;
        int b=mp2[taskId].second;
        mp[a].erase({taskId,b});
        if(mp[a].empty())mp.erase(a);
        mp2.erase(taskId);
        gl.erase({b,taskId,a});
    }
    
    int execTop() {
        if(gl.empty())return -1;
        auto [p,t,u]=*gl.begin();
        gl.erase(gl.begin());
        mp[u].erase({t,p});
        if(mp[u].empty())mp.erase(u);
        mp2.erase(t);
        return u;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */