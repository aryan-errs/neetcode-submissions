class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int i = 0, j = 0, cnt = 0;
        while (j < arr.size()) {
            sum += arr[j];
            if (j - i + 1 == k) {
                double avg = double(sum) / double(k);
                cnt += avg >= threshold;
                sum -= arr[i];
                i += 1;
            }
            j += 1;
        }
        return cnt;
    }
};