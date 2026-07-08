class KthLargest {
public:
    vector<int> v;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        v = nums;
    }
    
    int add(int val) {
        v.push_back(val);
        sort(v.begin(), v.end());
        return v[v.size()-K];
    }
};
