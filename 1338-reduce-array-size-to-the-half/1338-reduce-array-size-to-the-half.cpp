class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int siz=arr.size();
        int hss[100001]={0};
        for(int i=0;i<arr.size();i++){
            hss[arr[i]]++;
        }
        long long int sum=0;
        vector<int>vec;
        for(int i=0;i<100001;i++){
            if(hss[i]!=0){
                vec.push_back(hss[i]);
                sum+=hss[i];
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        int cnt=1;
        int m=vec.size();    
        for(int i=m-1;i>=0;i--){
            if(sum-vec[i] > (siz/2)){
                cnt++;
                sum-=vec[i];
            }
            else break;
        }
        return cnt;
        
    }
};