class Node{
public:
    Node *next, *prev;
    int key, val;
    Node(int k, int v){
        key = k, val = v;
        next = prev = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* head, *tail;
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail; tail->prev = head;
        cap = capacity;
    }
    void insertAtBeginning(Node* node){
        Node* afterHead  = head->next;
        head->next = node, node->prev = head;
        node->next = afterHead, afterHead->prev = node;
        return;
    }
    void removeNode(Node* node){
        Node* nextNode = node->next, *prevNode = node->prev;
        nextNode->prev = prevNode, prevNode->next = nextNode;
        return;
    }
    int get(int _key) {
        if (mp.find(_key) == mp.end()) return -1;
        Node* node = mp[_key];
        removeNode(node);
        insertAtBeginning(node);
        return node->val;
    }
    
    void put(int _key, int _value) {
        if (mp.find(_key) != mp.end()){
            Node* node = mp[_key];
            removeNode(node);
            mp.erase(node->key);
        }
        if (cap == mp.size()){
            Node* node = tail->prev;
            removeNode(node);
            mp.erase(node->key);
        }
        Node* newNode = new Node(_key, _value);
        insertAtBeginning(newNode);
        mp[_key] = newNode;
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */