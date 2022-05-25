class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0, sum = 0;

        while (i >= 0 or j >= 0)
        {
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';

            sum += carry;

            ans += to_string(sum % 2);

            carry = sum > 1 ? 1 : 0;
            sum = 0;
        }

        if (carry)
            ans += to_string(carry);

        reverse(begin(ans), end(ans));
        return ans;
    }
};