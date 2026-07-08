class Solution {
public:
    int solve(int index, vector<int>& cost){
        if(index < 0){
            return 0;
        }

        int oneStep = cost[index] + solve(index-1, cost);
        int twoStep = cost[index] + solve(index-2, cost);
        return min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int ans = min(solve(cost.size()-1, cost), solve(cost.size()-2, cost));
        return ans;
    }
};
