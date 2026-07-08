/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        queue<Node*> q;;
        Node* newNode = new Node(1);
        unordered_map<Node*, Node*> clones;
        clones[node] = newNode;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* it: curr->neighbors){
                if (clones.find(it) == clones.end()) {
                    clones[it] = new Node(it->val);
                    q.push(it);
                }
                clones[curr]->neighbors.push_back(clones[it]);
            }
        }
        return clones[node];
    }
};
