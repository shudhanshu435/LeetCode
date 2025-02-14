class ProductOfNumbers {
public:
    vector<int>vec;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num==0){
            vec.clear();
        }
        else {
            int top=1;
            if(!vec.empty())top=vec.back();
            vec.push_back(top*num);
        }
    }



    int getProduct(int k) {
        if(k>vec.size())return 0;
        if(k==vec.size())return vec.back();
        int i=vec.size()-k;
        return (vec.back()/vec[i-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */