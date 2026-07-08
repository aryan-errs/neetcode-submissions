class Adj {
    vector<int> parent;
    vector<int> size;
public:
    Adj(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            this->parent[i] = i;
        }
        this->size.resize(n, 1);
    }
    int find(int x) {
        if (this->parent[x] != x) {
            return find(this->parent[x]);
        }
        return x;
    }
    void join(int x, int y) {
        int py = this->find(y);
        int px = this->find(x);
        if (px == py) return;
        if (this->size[px] > this->size[py]) {
            this->parent[py] = px;
            this->size[px] += this->size[py];
        } else {
            this->parent[px] = py;
            this->size[py] += this->size[px];
        }
    }
    int maxSize(int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, this->size[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        Adj* adj = new Adj(nums.size());
        map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.contains(nums[i])) continue;
            if (mp.contains(nums[i]-1)) {
                adj->join(i, mp[nums[i]-1]);
            }
            if (mp.contains(nums[i]+1)) {
                adj->join(i, mp[nums[i]+1]);
            }
            mp[nums[i]] = i;
        }
        return adj->maxSize(nums.size());
    }
};
