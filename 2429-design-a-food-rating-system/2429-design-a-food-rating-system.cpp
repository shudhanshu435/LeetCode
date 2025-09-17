class FoodRatings{
public:
    unordered_map<string, pair<string,int>>mp; //food - cuisine - rating
    map<string, set<pair<int,string>>>mpc;    //cuisine - rating - food

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            mp[foods[i]]={cuisines[i],ratings[i]};
            mpc[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string a=mp[food].first;
        int b=mp[food].second;
        mpc[a].erase({-b,food});
        mpc[a].insert({-newRating,food});
        mp[food]={a,newRating};
    }
    
    string highestRated(string cuisine) {
        return mpc[cuisine].begin()->second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */