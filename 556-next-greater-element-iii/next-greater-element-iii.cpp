class Solution {
public:
    int solve(string s){
        long long  num=0;
        for(char ch : s){
            num=num*10+(ch-'0');
            if(num>INT_MAX){
                return -1;
            }
        }
        return (int)num;
    }
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int piv=-1;
        int k=s.size();
        for(int i=k-2;i>=0;i--){
            if(s[i] < s[i+1]){
                piv=i;
                break;
            }
        }
        if(piv==-1) return -1;
        for(int i=k-1;i>piv;i--){
            if(s[piv]< s[i]){
                swap(s[piv],s[i]);
                break;
            }
        }
        reverse(s.begin()+piv+1,s.end());
        return solve(s);
    }
};