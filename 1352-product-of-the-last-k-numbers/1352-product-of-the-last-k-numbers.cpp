class ProductOfNumbers {
public:
    vector<long long>vec;
    ProductOfNumbers() {
    }
    // 2 4 3  2 
    // 2 8 24 48
    void add(int num) {
        if(num==0)vec.clear();
        else if(!vec.empty())vec.push_back(num*vec.back());
        else vec.push_back(num);
    }
    
    int getProduct(int k) {
        int s=vec.size();
        if(k>s)return 0;
        if(s==k)return vec[s-1];
        return vec[s-1]/vec[s-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */