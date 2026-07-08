class Solution {
    void toposort(string &ans, vector<int> adj[], vector<int>& indegree, unordered_map<int,bool> isPresent){
        queue<int> q;
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(isPresent[i] && indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            count++;
            q.pop();
            ans += curr + 'a';
            for(auto it: adj[curr]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        int totalPresent = 0;
        for(auto it: isPresent){
            if(it.second) totalPresent++;
        }
        if(count != totalPresent) ans = "";
    }
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> adj[26];
        unordered_map<int,bool> isPresent;
        vector<int> indegree(26, 0);
        for(int i = 0; i < words.size(); i++) {
            for(char c : words[i]) {
                isPresent[c - 'a'] = true; 
            }
        }
        for(int i = 0; i < words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) {
                return "";  
            }
            for(int j = 0; j < min(s1.size(), s2.size()); j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[s2[j]-'a']++;
                    break;
                }
                
            }
        }
        string ans = "";
        toposort(ans, adj, indegree, isPresent);
        return ans;
    }
};
