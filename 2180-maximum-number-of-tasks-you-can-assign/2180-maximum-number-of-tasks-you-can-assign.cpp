class Solution {
public:
    bool canAssign(const vector<int>& tasks, const vector<int>& workers, int pills, int strength, int taskCount) {
        deque<int> boosted;
        int w = workers.size() - 1;
        int freePills = pills;

        for (int t = taskCount - 1; t >= 0; --t) {
            int task = tasks[t];

            if (!boosted.empty() && boosted.front() >= task) {
                boosted.pop_front();
            } else if (w >= 0 && workers[w] >= task) {
                --w;
            } else {
                while (w >= 0 && workers[w] + strength >= task) {
                    boosted.push_back(workers[w--]);
                }
                if (boosted.empty() || freePills == 0) {
                    return false;
                }
                boosted.pop_back();
                --freePills;
            }
        }

        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min(tasks.size(), workers.size());

        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (canAssign(tasks, workers, pills, strength, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};

/*
    1 2 3
    0 2 3

    -2 -1 0
    -1 0 1
    1 2 3


    5 5 8 9 9
    1 2 4 6 6

    -1 -1 2 3 3
    -1 -1 2 3 3
     1  1 4 5 5
     3  3 6 7 7
     4  4 7 8 8

    3 7 8 9 9
    1 2 4 6 6

    -3  1 2 3 3
    -3  1 2 3 3
    -1  3 4 5 5
     1  5 6 7 7
     2  6 7 8 8

    1 2 3 3 8
*/