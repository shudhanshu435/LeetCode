class Spreadsheet {
public:
    pair<int,int> func(string cell){
        int c=cell[0]-'A';
        int num=0;
        for(int i=1;i<cell.size();i++){
            num=(num*10)+(cell[i]-'0');
        }
        return {num,c};
    }
    vector<vector<int>>vec;
    Spreadsheet(int rows) {
        vec.assign(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        pair<int,int>p=func(cell);
        vec[p.first-1][p.second]=value;
    }
    
    void resetCell(string cell) {
        pair<int,int>p=func(cell);
        vec[p.first-1][p.second]=0;
    }
    
    int getValue(string formula) {
        int num1=0,num2=0;
        string a="";
        int i;
        for(i=1;i<formula.size();i++){
            if(formula[i]!='+'){
                a+=formula[i];
            }
            else break;
        }
        if(a[0]>='A' and a[0]<='Z'){
            pair<int,int>p=func(a);
            num1=vec[p.first-1][p.second];
        }
        else num1=stoi(a);
        a=formula.substr(i+1);
        if(a[0]>='A' and a[0]<='Z'){
            pair<int,int>p=func(a);
            num2=vec[p.first-1][p.second];
        }
        else num2=stoi(a);
        return num1+num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */