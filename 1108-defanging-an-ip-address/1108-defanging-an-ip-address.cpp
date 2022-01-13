
class Solution
{
public:
    string defangIPaddr(string address)
    {
        int len=address.length();
        string ss="";
        for (int i = 0; i < len; i++)
        {
            if (address[i] == '.')
            {
                ss+="[.]";
            }else ss+=address[i];
            
        }
            return ss;
     }
};