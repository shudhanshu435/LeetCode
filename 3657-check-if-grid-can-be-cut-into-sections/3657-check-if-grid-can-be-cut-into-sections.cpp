#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(a) ((int)a.size())
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // for (auto i : rec) {
        //     for (auto ii : i) {
        //         cout << ii << " ";
        //     }
        //     cout << endl;
        // }
        // unordered_map<int, vector<int>> mp;
        // vector<int> v1, v2;
        // for (auto i : rec) {
        //     mp[i[1]].push_back(i[3]);
        //     v1.push_back(i[1]);
        //     v2.push_back(i[3]);
        // }
        // sort(v1.begin(), v1.end());
        // sort(v2.begin(), v2.end());

        // int mini = v2[0];
        // auto it = lower_bound(v1.begin(), v1.end(), mini);
        // bool f=1;
        // if(it==v1.end()){
        //     f=0;
        // }
        // else{
        //     int num=*it;
        //     vector<int>v=mp[num];
        //     num=*min_element(v.begin(),v.end());
        //     auto itt=lower_bound(v1.begin(),v1.end(),num);
        //     if(itt==v1.end())f=0;
        //     else return 1;
        // }
        // // cout<<"JNNN";
        // // vertical
        // mp.clear();
        // vector<int> v3, v4;
        // for (auto i : rec) {
        //     mp[i[0]].push_back(i[2]);
        //     v3.push_back(i[0]);
        //     v4.push_back(i[2]);
        // }
        // sort(v3.begin(), v3.end());
        // sort(v4.begin(), v4.end());

        // mini = v4[0];
        // it = lower_bound(v3.begin(), v3.end(), mini);
        // f=1;
        // if(it==v3.end()){
        //     return 0;
        // }
        // else{
        //     int num=*it;
        //     vector<int>v=mp[num];
        //     num=*min_element(v.begin(),v.end());
        //     auto itt=lower_bound(v3.begin(),v3.end(),num);
        //     if(itt==v3.end())return 0;
        //     else return 1;
        // }
        // return 0;
            sort(all(rectangles),[&](vi&a, vi&b){ return (a[0]!=b[0] ? a[0]<b[0] : a[2]>b[2]); });
            int cnt=0,m=sz(rectangles),last=rectangles[0][2];
            loop(i,1,m) cnt+=(last<=rectangles[i][0]),last=max(rectangles[i][2],last);
            if(cnt>=2) return 1;
            sort(all(rectangles),[&](vi&a, vi&b){ return (a[1]!=b[1] ? a[1]<b[1] : a[3]>b[3]); });
            cnt=0,last=rectangles[0][3];
            loop(i,1,m) cnt+=(last<=rectangles[i][1]),last=max(rectangles[i][3],last);
            return (cnt>=2);
    }

    
};

/*
    0 2 2 4
    0 4 4 5
    1 0 5 2
    3 2 5 3
*/