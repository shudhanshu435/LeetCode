class RideSharingSystem {
public:
    queue<int>q1,q2;
    unordered_map<int,bool>mp;
    RideSharingSystem() {
        
    }
    
    void addRider(int rd) {
        q1.push(rd);
        mp[rd]=0;
    }
    
    void addDriver(int dd) {
        q2.push(dd);
    }
    
    vector<int> matchDriverWithRider() {
        while(!q1.empty() and mp[q1.front()]==1){
            q1.pop();
        }
        if(!q1.empty() and !q2.empty()){
            int t=q1.front();
            int q=q2.front();
            q1.pop();
            q2.pop();
            return {q,t};
        }
        return {-1,-1};

    }
    
    void cancelRider(int rd) {
        mp[rd]=1;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */