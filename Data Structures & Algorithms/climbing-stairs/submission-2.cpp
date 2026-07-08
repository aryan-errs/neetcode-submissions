class Solution {
public:
    // int solve(int n, vector<int> &memo){
    //     if(n <= 3){
    //         memo[n] = n;
    //         return memo[n];
    //     }
    //     int one = memo[n-1] != 0? memo[n-1] : solve(n-1, memo);
    //     int two = memo[n-2] != 0? memo[n-2] : solve(n-2, memo);
    //     memo[n] = one+two;
    //     return memo[n];
    // }
    int climbStairs(int n) {
        if(n <= 2) return n;
        int first = 1;
        int second = 2;
        for(int i = 2; i <= n; i++){
            int temp = second;
            second += first;
            first = temp;
        }
        return first;
        
    }
};
