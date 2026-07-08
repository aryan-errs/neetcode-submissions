class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;
        int cnt = 0;
        while (i < j) {
            int s = people[i] + people[j];
            if (s <= limit) {
                cnt += 1;
                i++;
                j--;
            } else {
                cnt++;
                j--;
            }
        }
        if (i == j) cnt++;
        return cnt;
    }
};