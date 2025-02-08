class NumberContainers {
public:
    NumberContainers() {
        
    }
    map<int,set<int>>mp;
    unordered_map<int,int>m;
    
    void change(int index, int number) {
        if(m.count(index)){
            int sec=m[index];
            mp[sec].erase(index);
        }
        m[index]=number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(mp[number].empty())return -1;
        return *(mp[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */