class Solution {
public:
    string convertDateToBinary(string date) {
        int year=(date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
        int mon=(date[5]-'0')*10+(date[6]-'0');
        int dat=(date[8]-'0')*10+(date[9]-'0');
        string a="";
        string m="";
        string d="";
        while(year){
            if(year%2)a+='1';
            else a+='0';
            year/=2;
        }
        reverse(a.begin(),a.end());
        while(mon){
            if(mon%2)m+='1';
            else m+='0';
            mon/=2;
        }
        reverse(m.begin(),m.end());
        while(dat){
            if(dat%2)d+='1';
            else d+='0';
            dat/=2;
        }
        reverse(d.begin(),d.end());

        return a+"-"+m+"-"+d;
    }
};