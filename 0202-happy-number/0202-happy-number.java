class Solution {
    public boolean isHappy(int n) {
        HashSet<Long>set=new HashSet<>();
        long m=n;
        while(true){
            long sum=0;
            while(m>0){
                sum+=(m%10)*(m%10);
                m/=10;
            }
            if(sum==1)return true;
            if(set.contains(sum))return false;
            set.add(sum);
            m=sum;
        }
    }
}