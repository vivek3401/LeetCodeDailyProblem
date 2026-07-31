class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        for(char ch : word){
            mp[ch]++;
        }
        priority_queue<int> pq;
        for(auto it : mp){
            int val=it.second;
            pq.push(val);
        }
        int multi=1;
        int cnt=1;
        int ans=0;
        while(!pq.empty()){
            int val=pq.top();
            pq.pop();
            if(cnt<=8){
                ans+=val*multi;
                cnt++;
            }else{
                multi++;
                cnt=2;
                ans+=val*multi;
            }
        }
        return ans;
    }
};