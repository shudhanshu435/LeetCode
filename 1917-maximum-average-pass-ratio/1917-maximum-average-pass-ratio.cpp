class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P> pq; //max-heap //(max-delta, idx}
        int n=classes.size();

        for(int i=0; i < n; i++) { //O(n)
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR-current_PR;
            pq.push({delta, i});
        }

        //t.c = (extrastudents*logn)
        while(extraStudents--) { //O(k)
            auto curr = pq.top();
            pq.pop(); //O(logn)
            double delta = curr.first;
            int idx= curr.second;
            classes[idx][0]++; //incremeent total passing students in the class
            classes[idx][1]++; //increment total students oin the class
            double current_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = new_PR-current_PR;
            pq.push({delta, idx}); //O(logn)
        }

        double result = 0.0;
        for(int i=0;i<n;i++){
            result+=(double)classes[i][0]/classes[i][1];
        }
        return result/n;
    }
};