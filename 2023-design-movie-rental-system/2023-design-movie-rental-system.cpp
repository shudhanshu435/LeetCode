class MovieRentingSystem {
public:
    typedef pair<int,int> P;
    unordered_map<int, set<P>>available; //movie - price - shop
    unordered_map<int, set<P>>movieToShopPrice; // movie - shop - price
    set<tuple<int,int,int>>rented; // price - shop - movie
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e:entries){
            int shop=e[0];
            int movie=e[1];
            int price=e[2];
            available[movie].insert({price,shop}); //insertion is logn
            movieToShopPrice[movie].insert({shop,price});//same logn
        }
    }
    
    vector<int> search(int movie) {
        vector<int>res;
        int cnt=0;
        if(available.count(movie)){
            for(auto &[_,shop]:available[movie]){ //O(5)
                res.push_back(shop);
                cnt++;
                if(cnt>=5)break;
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        auto it=movieToShopPrice[movie].lower_bound({shop,INT_MIN}); //logn
        int price=it->second;

        available[movie].erase({price,shop}); //logn
        rented.insert({price,shop,movie}); //logn
    }
    
    void drop(int shop, int movie) {
        auto it=movieToShopPrice[movie].lower_bound({shop,INT_MIN}); //logn
        int price=it->second;

        available[movie].insert({price,shop}); //logn
        rented.erase({price,shop,movie}); //logn
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>res;
        int cnt=0;
        for(auto &[price,shop,movie]: rented){ //O(5)
            res.push_back({shop,movie});
            cnt++;
            if(cnt>=5)break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */