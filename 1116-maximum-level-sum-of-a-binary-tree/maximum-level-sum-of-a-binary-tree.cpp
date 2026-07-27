/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front().first;
                int dis=q.front().second;
                q.pop();
                mp[dis].push_back(curr->val);
                if(curr->left) q.push({curr->left,dis+1});
                if(curr->right) q.push({curr->right,dis+1});
            }
        }
        int ans=INT_MIN;
        int level=0;
        for(auto it : mp){
            int size=it.second.size();
            int sum=0;
            for(int i=0;i<size;i++){
                sum+=it.second[i];
            }
            if(sum>ans){
                level=it.first;
                ans=sum;
            }
        }
        return level;
    }
};