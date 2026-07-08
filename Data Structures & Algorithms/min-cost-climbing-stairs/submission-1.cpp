class Solution {
public:
    // int solve(int index, vector<int>& cost){
    //     if(index < 0){
    //         return 0;
    //     }

    //     int oneStep = cost[index] + solve(index-1, cost);
    //     int twoStep = cost[index] + solve(index-2, cost);
    //     return min(oneStep, twoStep);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = cost.size() - 3; i>=0; i--){
            cost[i] += min(cost[i+1], cost[i+2]);
        }
        return min(cost[0], cost[1]);
    }
};
