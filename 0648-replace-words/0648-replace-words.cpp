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
    
    string search(string word) {
        Node* node = root; 
        string ans;
        for (int i=0; i<word.size(); i++){
            if (!node->containsKey(word[i])){
                return "";
            }
            ans.push_back(word[i]);
            node = node->getNext(word[i]);
            if (node->flag) return ans;
        }
        return ans;
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

void fun(vector<string> &allWords, string &sentence){
    int i=0,j=0,n=sentence.size();
    while (j < n){
        while (j<n && sentence[j]!=' ') j++;
        string str = sentence.substr(i,j-i);
        allWords.push_back(str);
        j++;
        i=j;
    }
    return ;
}

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (auto it : dictionary) trie.insert(it);
        vector<string> allWords;
        fun(allWords, sentence);

        for (int i=0; i<allWords.size(); i++){
            string str = trie.search(allWords[i]);
            if (str!=""){
                allWords[i] = str;
            }
        }

        string ans="";
        for(auto it : allWords){
            ans+=it;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};