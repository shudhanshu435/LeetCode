class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>vec;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C")vec.pop_back();
            else if(ops[i]=="D")vec.push_back(2*vec[vec.size()-1]);
            else if(ops[i]=="+")vec.push_back(vec[vec.size()-1] + vec[vec.size()-2]);
            else 
            {
                vec.push_back(stoi(ops[i]));
                cout<<vec[vec.size()-1]<<" ";
            }
        }
        int sum=0;
        for(int i=0;i<vec.size();i++)sum+=vec[i];
        
        return sum;
    }
};
