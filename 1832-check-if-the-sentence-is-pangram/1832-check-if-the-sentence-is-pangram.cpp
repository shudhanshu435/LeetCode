class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        char c = 'a';
        int cnt = 0;
        while (c <= 'z')
        {
            for (int i = 0; i < sentence.length(); i++)
            {
                if (sentence[i] == c)
                {
                    cnt++;
                    break;
                }
            }
            c++;
        }
        if (cnt == 26)
            return 1;
        else
            return 0;
    }
};