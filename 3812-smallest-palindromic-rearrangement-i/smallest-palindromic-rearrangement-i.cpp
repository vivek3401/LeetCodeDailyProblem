class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        vector<int> cnt(26,0);
        for(char ch : s) cnt[ch-'a']++;
        string firsthalf="";
        string mid="";
        string right="";
        for(int i=0;i<26;i++){
            int val=cnt[i]/2;
            while(val--){
                firsthalf+=char(i+'a');
                }
            if(cnt[i]%2==1){
                mid+=char(i+'a');
            }
        }
        right=firsthalf;
        reverse(right.begin(),right.end());
        return firsthalf+mid+right;
    }
};