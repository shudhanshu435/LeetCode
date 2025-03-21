class ParkingSystem {
public:
    vector<int>a,b,c;
    int bb,m,s;
    ParkingSystem(int big, int medium, int small) {
        a.resize(big);
        b.resize(medium);
        c.resize(small);
        bb=big,m=medium,s=small;
    }
    int c1=0,c2=0,c3=0;
    bool addCar(int carType) {
        if(carType==1){
            if(c1>=bb)return 0;
            c1++;
        }
        if(carType==2){
            if(c2>=m)return 0;
            c2++;
        }
        if(carType==3){
            if(c3>=s)return 0;
            c3++;
        }
        return 1;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */