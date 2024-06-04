class Node{
    public: 
        int key, value;
        Node* next, *prev;
        Node(int k, int v){
            key = k, value = v;
            next = prev = NULL;
        }
};
class LRUCache {
public:
    int cap;
    Node* head, *tail;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev; 
        Node* nextNode = node->next;
        prevNode->next = nextNode, nextNode->prev = prevNode;
        return ;
    }
    
    void addNode(Node* node){
        Node* afterHead = head->next;
        head->next = node, node->prev = head;
        node->next = afterHead, afterHead->prev = node;
        return ;
    }

    int get(int getKey) {
        if (mp.find(getKey) == mp.end()) return -1;
        Node* node = mp[getKey];
        int val = node->value;
        
        deleteNode(node);
        addNode(node);

        return val;
    }
    
    void put(int getKey, int val) {
        if (mp.find(getKey) != mp.end()){
            Node* node = mp[getKey];
            mp.erase(getKey);
            deleteNode(node);
        }

        if (mp.size() == cap){
            Node* node = tail->prev;
            mp.erase(node->key);
            deleteNode(node);
        }
        Node* newNode = new Node(getKey, val);
        addNode(newNode);

        mp[getKey] = newNode;

        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */