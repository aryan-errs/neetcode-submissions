class TrieNode {
public:
    TrieNode* child[26] = {nullptr};
    bool isEnd = false;
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        if(!root) root = new TrieNode();
        TrieNode* curr = root;
        for(auto c: word){
            if(curr->child[c-'a'] == nullptr){
                curr->child[c-'a'] = new TrieNode();
            }
            curr = curr->child[c-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        if(!root) return false;
        TrieNode* curr = root;
        for(auto c: word){
            if(curr->child[c-'a'] == nullptr){
                return false;
            }
            curr = curr->child[c-'a'];
        }
        return curr->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        if(!root) return false;
        TrieNode* curr = root;
        for(auto c: prefix){
            if(curr->child[c-'a'] == nullptr){
                return false;
            }
            curr = curr->child[c-'a'];
        }
        return true;
    }
};
