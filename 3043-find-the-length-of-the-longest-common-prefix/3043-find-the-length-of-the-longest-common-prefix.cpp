class Node{
    public:
        Node* links[10];
        bool flag = false;
        Node* getNext(char ch){
            return links[ch-'0'];
        }
        bool containsKey(char ch){
            return links[ch-'0']!=NULL;
        }
        void put(char ch, Node* node){
            links[ch-'0'] = node;
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
    
    int search(string word) {
        Node* node = root;
        int cnt = 0;
        for (int i=0; i<word.size(); i++){
            if (!node->containsKey(word[i])){
                return cnt;
            }
            cnt++;
            node = node->getNext(word[i]);
        }
        return cnt;
    }

};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for (auto it : arr1){
            string str = to_string(it);
            trie.insert(str);
        }
        int maxi = 0;
        for (auto it : arr2){
            string str = to_string(it);
            int count = trie.search(str);
            maxi = max(maxi, count);
        }
        return maxi;
    }
};