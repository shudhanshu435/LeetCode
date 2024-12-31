vector<int> mp(366);
class Solution {
public:

int solve(int index, vector<int>& days, vector<int>& costs) {
    if (index >= days.size()) {
        return 0;
    }

    if (mp[index] != -1) {
        return mp[index];
    }

    int option1 = costs[0] + solve(index + 1, days, costs);

    int i = index;
    while (i < days.size() && days[i] < days[index] + 7) i++;
    int option2 = costs[1] + solve(i, days, costs);

    i = index;
    while (i < days.size() && days[i] < days[index] + 30) i++;
    int option3 = costs[2] + solve(i, days, costs);

    return mp[index] = min({option1, option2, option3});
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    fill(mp.begin(), mp.end(), -1);
    return solve(0, days, costs);
}
};