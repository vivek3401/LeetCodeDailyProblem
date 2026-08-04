class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_freq=0,max_len=0;
        int left=0,right=0;
        vector<int> freq(26,0);
        while(right<s.size()){
            freq[s[right]-'A']++;
            max_freq=max(max_freq,freq[s[right]-'A']);
            while((right-left+1)-max_freq>k){
                freq[s[left]-'A']--;
                left++;
            }
            max_len=max(max_len,right-left+1);
            right++;
        }
        return max_len;
    }
};