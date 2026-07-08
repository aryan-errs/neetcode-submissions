class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (auto num: nums) {
            arr.push_back(to_string(num));
        }
        sort(arr.begin(), arr.end(), cmp);
        string ans = "";
        for (auto s: arr) ans += s;
        return ans[0] == '0' ? "0" : ans;
    }
};