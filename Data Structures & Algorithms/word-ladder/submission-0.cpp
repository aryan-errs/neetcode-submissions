class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
        set<string> st(wordList.begin(), wordList.end());
        st.insert(beginWord);
        pq.push({1,beginWord});
        while(!pq.empty()){
            string curr = pq.top().second;
            int steps = pq.top().first;
            pq.pop();
            if(curr == endWord) return steps;
            for(int i = 0; i < curr.length(); i++){
                char original = curr[i];
                for(char c = 'a'; c <= 'z'; c++){
                    curr[i] = c;
                    if(st.find(curr) != st.end()){
                        pq.push({steps+1, curr});
                        st.erase(curr);
                    }
                }
                curr[i] = original;
            }
        }
        return 0;
    }
};
