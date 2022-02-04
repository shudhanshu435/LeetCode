class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        long long int cnt = 0;
        long long int n = maxDoubles;
        while (target != 1)
        {
            if (target & 1)
            {
                target -= 1;
                cnt++;
            }
            else
            {
                if (n != 0)
                {
                    target /= 2;
                    n--;
                    cnt++;
                }
                else
                {
                    cnt += target - 1;
                    target=1;
                }
            }
        }
        return cnt;
    }
};