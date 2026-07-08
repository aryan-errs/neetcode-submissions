class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] += 1;
        }
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        for(int i = 0; i < k; i++) {
            if (!pq.empty()) {
                pair<int,int> p = pq.top();
                pq.pop();
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};
