class Node{
    public:
        Node* links[26];
        bool flag = false;
        Node* getNext(char ch){
            return links[ch-'a'];
        }
        bool containsKey(char ch){
            return links[ch-'a']!=NULL;
        }
        void put(char ch, Node* node){
            links[ch-'a'] = node;
            return ;
        }
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i=0; i<word.size(); i++){
            if (!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for (int i=0; i<word.size(); i++){
            if (!node->containsKey(word[i])){
                return false;
            }
            node = node->getNext(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string word) {
        Node* node = root;
        for (int i=0; i<word.size(); i++){
            if (!node->containsKey(word[i])){
                return false;
            }
            node = node->getNext(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */