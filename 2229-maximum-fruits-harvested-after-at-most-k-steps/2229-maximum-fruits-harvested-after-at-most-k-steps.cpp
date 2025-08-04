class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int>pref(n);
        pref[0]=fruits[0][1];
        for(int i=1;i<n;i++)pref[i]=pref[i-1]+fruits[i][1]; //prefix sum of fruits
        int maxi=0;
        int p=startPos;
        int left;
        int right;
        int ind1;
        int ind2;
        vector<int>pos;
        for(auto i:fruits)pos.push_back(i[0]);

        // go left only
        int leff=startPos-k;
        if(startPos>=pos[0]){
            leff=max(leff,0);
            auto it1=lower_bound(pos.begin(),pos.end(),leff);
            int i1=it1-pos.begin();
            auto up1=upper_bound(pos.begin(),pos.end(),startPos);
            int i2=up1-pos.begin();
            if(i1>0)maxi=max(maxi,pref[i2-1]-pref[i1-1]);
            else maxi=max(maxi,pref[i2-1]);
        }


        while(p>=0){
            left=k-2*(startPos-p);
            // if(left<0)break;
            if(startPos-p>k)break;
            right=startPos+left;
            auto it=lower_bound(pos.begin(),pos.end(),p);
            ind1=it-pos.begin();
            auto rt=upper_bound(pos.begin(),pos.end(),right);
            ind2=rt-pos.begin()-1;
            if(ind1<=ind2 and ind2!=-1){
                // cout<<p<<" "<<ind1<<endl;
                // cout<<right<<" "<<ind2<<endl;

                if(ind1>0) maxi=max(maxi,pref[ind2]-pref[ind1-1]);
                else maxi=max(maxi,pref[ind2]);
                // cout<<maxi<<endl<<endl;
            }
            p--;
        }
        // cout<<maxi<<endl;
        p=startPos;
        while(p<=fruits[n-1][0]){
            left=k-2*(p-startPos);
            if(left>k)break;
            int goleft=startPos-left;
            auto iit=lower_bound(pos.begin(),pos.end(),goleft);
            ind1=iit-pos.begin();
            auto rrt=upper_bound(pos.begin(),pos.end(),p);
            ind2=rrt-pos.begin()-1;
            if(ind1<=ind2 and ind2!=-1){
                if(ind1>0) maxi=max(maxi,pref[ind2]-pref[ind1-1]);
                else maxi=max(maxi,pref[ind2]);
            }
            p++;
        }
        return maxi;
    }
};