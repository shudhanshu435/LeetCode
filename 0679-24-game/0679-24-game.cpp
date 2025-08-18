class Solution {
public:
     bool ans = false;

    void get_ans(vector<double>&cards, int op) {
        if (op == 3) {
            for (auto x : cards) {
                if (fabs(x - 24.0) <= (1e-1)*4) ans = true;  
            }
            return;
        }
        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size(); j++) {
                if (i == j || cards[i] == -1000 || cards[j] == -1000) continue;
                double val1 = cards[i];
                double val2 = cards[j];
                cards[i] = -1000;
                cards[j] = -1000;

                cards.push_back(val1 + val2);
                get_ans(cards, op + 1);
                cards.pop_back();

                cards.push_back(val1 - val2);
                get_ans(cards, op + 1);
                cards.pop_back();

                cards.push_back(val1 * val2);
                get_ans(cards, op + 1);
                cards.pop_back();

                if (fabs(val2) > 1e-9) {
                    cards.push_back(val1 / val2);
                    get_ans(cards, op + 1);
                    cards.pop_back();
                }

                cards[i] = val1;
                cards[j] = val2;
            }
        }
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> arr(cards.begin(), cards.end()); 
        get_ans(arr, 0);
        return ans;
    }
};