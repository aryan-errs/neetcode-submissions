class Node{
    public:
    Node* children[26] = {nullptr};
    bool isEnd = false;
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        if(!root) root = new Node();
        Node* curr = root;
        for(auto c: word){
            if(!curr->children[c-'a']) curr->children[c-'a'] = new Node();
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        if(!root) return false;
        Node* curr = root;
        return solve(word, 0, curr);
    }
private:
    bool solve(string word, int index, Node* curr){
        if(!curr) return false;
        if(index == word.length()) return curr->isEnd;
        char c = word[index];
        if(c == '.'){
            for(int i = 0; i < 26; i++){
                if(curr->children[i] && solve(word, index+1, curr->children[i])){
                    return true;
                }
            }
            return false;
        }
        return curr->children[c-'a'] && solve(word, index+1, curr->children[c-'a']);
    }
};
