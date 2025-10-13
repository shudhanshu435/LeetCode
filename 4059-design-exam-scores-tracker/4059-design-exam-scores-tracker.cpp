class ExamTracker {
public:
    vector<long long>ind,sco;
    ExamTracker() {
    }
    
    void record(int time, int score) {
        ind.push_back(time);
        if(sco.size()>=1)sco.push_back(sco.back()+score*1ll);
        else sco.push_back(score*1ll);
    }
    int left=0,right=0;
    long long totalScore(int st, int et) {
        int n=ind.size();

        auto it=lower_bound(ind.begin(),ind.end(),st);
        left=it-ind.begin();
        auto itt=upper_bound(ind.begin(),ind.end(),et);
        right=itt-ind.begin()-1;

        if(right<0 or left>=n or left>right)return 0;
        if(left==0)return sco[right];
        return sco[right]-sco[left-1];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */