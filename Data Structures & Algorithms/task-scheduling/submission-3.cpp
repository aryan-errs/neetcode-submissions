class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto task: tasks) {
            freq[task-'A'] += 1;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) pq.push(freq[i]);
        }
        int time = 0;
        queue<pair<int,int>> q;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (pq.empty()) {
                time = q.front().second;
            } else {
                int f = pq.top();
                pq.pop();
                f -= 1;
                if (f > 0) {
                    q.push({f,time + n});
                }
            }
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
