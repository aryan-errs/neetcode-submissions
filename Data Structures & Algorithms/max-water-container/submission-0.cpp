class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, h = heights.size()-1;
        int ans = 0;
        while(l < h){
            ans = max(ans, min(heights[l], heights[h])*(h-l));
            if(heights[l] > heights[h]){
                h--;
            }else l++;
        }
        return ans;
    }
};
