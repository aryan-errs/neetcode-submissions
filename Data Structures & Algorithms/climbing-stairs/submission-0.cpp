class Solution {
public:
    int solve(int n){
        if(n <= 3) return n;
        int one = solve(n-1);
        int two = solve(n-2);
        return one+two;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};
