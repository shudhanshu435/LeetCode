class Spreadsheet {
    vector<vector<int>> vec;
    int col(char c){ 
        return (c-'A');
    }
    int row(string s) { 
        return stoi(s.substr(1))-1; 
    }
public:
    Spreadsheet(int rows){
        vec=vector<vector<int>>(rows);
        for(int i=0;i<rows;i++){
            vec[i]=vector<int>(26,0);
        }
    }
    
    void setCell(string cell, int value) {
        int c=col(cell[0]),r=row(cell);
        vec[r][c]=value;
    }
    
    void resetCell(string cell) {
        int c=col(cell[0]),r=row(cell);
        vec[r][c]=0;
        
    }
    
    int getValue(string f) {
        if(f[0]!='=')return stoi(f);
        f=f.substr(1);
        stringstream ss(f);
        string str;
        int ans=0;
        while(getline(ss,str,'+')){ 
            if(isdigit(str.front())){
                ans+=stoi(str);
            }
            else{
                int r=row(str);
                int c=col(str[0]);
                ans+=vec[r][c];
            }
        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */