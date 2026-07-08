class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>> pq;
        int n = position.size();
        for(int i = 0; i < n; i++){
            pq.push({position[i],speed[i]});
        }
        int cnt = 0;
        while(!pq.empty()){
            int pos = pq.top().first;
            int pace = pq.top().second;
            pq.pop();
            double time = (double)(target-pos)/(double)pace;
            cnt++;
            while(!pq.empty()){
                int nextCarpos = pq.top().first;
                int nextCarspeed = pq.top().second;
                double timeTaken = (double)(target-nextCarpos)/(double)nextCarspeed;
                if(timeTaken <= time){
                    pq.pop();
                }else break;
            }
        }
        return cnt;
    }
};
