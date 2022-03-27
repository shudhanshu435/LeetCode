class Solution
{
public:
    bool isValid(string s)
    {   int count = 0;
        if(s.size() % 2 == 1) return false;
        stack<char> temp;
        if(s[0]==')'||s[0]=='}'||s[0]==']'){
            cout<<0<<endl;
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                temp.push(s[i]);
            else
            {   
                count++;
                if (temp.empty()){
                    cout<<-1<<endl;
                    return false;
                }
                else if (s[i] == ')')
                {
                    // if(temp.empty())return false;
                    if (temp.top() != '('){
                        cout<<2<<endl;
                        return false;
                    }
                    else{
                        temp.pop();
                    }
                }
                else if (s[i] == '}')
                {
                    if (temp.top() != '{'){
                        cout<<3<<endl;
                        return false;
                    }
                    else{
                        temp.pop();
                    }
                }
                else if(s[i] == ']')
                {
                    if (temp.top() != '['){
                        cout<<4<<endl;
                        return false;
                    }
                    else{
                        temp.pop();
                    }
                }
            }
        }
        if(count == 0 || temp.empty() == false){
            return false;
        }
        return true;
    }
};