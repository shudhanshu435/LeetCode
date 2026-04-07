class Robot {
public:
    vector<vector<int>>vec;
    int tot=0;
    int div;
    int w,h;
    bool b=1;
    Robot(int ww, int hh) {
        vec.resize(hh,vector<int>(ww,0));
        div=ww*2+(hh-2)*2;
        w=ww,h=hh;
    }
    
    void step(int num) {
        tot+=num;b=0;
        return;
    }
    
    vector<int> getPos() {
        tot%=div;
        if(tot<w){
            return {tot,0};
        }
        else if(tot>=w and tot<w+h-2){
            return {w-1,tot-w+1};
        }
        else if(tot>=w+h-2 and tot<w+w+h-2){
            int m=tot-(w+h-2);
            return {w-1-m,h-1};
        }
        else{
            int m=tot-(w+w-1+h-2);
            return {0,h-1-m};
        }
    }
    
    string getDir() {
        // cout<<tot<<endl;
        if(b and tot==0)return "East";
        tot%=div;
        if(tot==0)return "South";
        if(tot<w){
            return "East";
        }
        else if(tot>=w and tot<=w+h-2){
            return "North";
        }
        else if(tot>=w+h-2 and tot<w+w+h-2){
            return "West";
        }
        else{
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */