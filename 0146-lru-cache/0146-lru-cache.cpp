class LRUCache {
public:
    int cap;
    list<pair<int, int>>lp;
    unordered_map<int, list<pair<int,int>>::iterator>mp;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        auto it=mp[key];
        lp.splice(lp.begin(),lp,it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            auto it=mp[key];
            lp.splice(lp.begin(),lp,it);
            it->second=value;
        }
        else{
            if(lp.size()<cap){
                lp.push_front({key,value});
                mp[key]=lp.begin();
            }
            else{
                auto last=lp.back();
                mp.erase(last.first);
                lp.pop_back();
                lp.push_front({key,value});
                mp[key]=lp.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */