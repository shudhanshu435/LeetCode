class Solution {
public:
    
    string buildPalindrom(string half, char middle) {

        string ans = half;
        string second = half;
        reverse(begin(second), end(second));

        if (middle != '@') {
            ans.push_back(middle);
        }

        ans += second;

        return ans;
    }

    bool solve(int i, int isGreater, char middle, string& half, string& ans, string& target, vector<int>& freq) {

        if (i == target.length()/2) {

            string currPal = buildPalindrom(half, middle);
            if (currPal > target) {
                ans = currPal;
                return true;
            }

            return false;
        }

        if (isGreater) {

            for (int j = 0; j < 26; j++) {
                half.append(freq[j], j + 'a');
            }

            ans = buildPalindrom(half, middle);
            return true;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (freq[ch - 'a'] == 0) continue;

            if (isGreater == false && target[i] > ch) continue;

            half.push_back(ch);
            freq[ch - 'a']--;

            bool currGreater = isGreater || ch > target[i];

            if (solve(i+1, currGreater, middle, half, ans, target, freq)) {
                return true;
            }

            half.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        

        vector<int> freq(26, 0);

        for (char& ch : s) {
            freq[ch - 'a']++;
        }

        int oddCount = 0;
        char middle = '@';

        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2 != 0) {
                middle = 'a' + i;
                oddCount++;
            }
        }

        if (oddCount > 1) {
            return "";
        }

        string half = "";

        for (int i = 0; i < 26; i++) {

            int count = freq[i] / 2;

            half.append(count, i + 'a');

            freq[i] /= 2;
        }

        string ans = buildPalindrom(half, middle);

        if (ans > target) {
            return ans;
        }

        ans = "";
        half = "";

        solve(0, false, middle, half, ans, target, freq);

        return ans;
    }
};