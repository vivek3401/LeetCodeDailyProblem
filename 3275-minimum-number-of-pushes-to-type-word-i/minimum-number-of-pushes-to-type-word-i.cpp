class Solution {
public:
    int minimumPushes(string word) {
        int mini=8;
        int n=word.size();
        if(n<=8) return n;
        int multi=1;
        int ans=0;
        while(n>0){
            int take=min(mini,n);
            ans+=take*multi;
            n-=take;
            multi++;
        }
        return ans;
    }
};