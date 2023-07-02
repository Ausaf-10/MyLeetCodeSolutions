class LRUCache {
public:
    class Node{
      public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key,int val){
            this->key = key;
            this->val = val;
        }
    };

    // INITIALISZE THE HEAD AND TAIL POINTERS
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int cap;
    unordered_map<int,Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deletenode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        return ;
    }

    void addnode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        return ;
    }
    
    int get(int _key) {
        if (mp.find(_key) != mp.end()){
            Node* resNode = mp[_key];
            int res = resNode->val;
            mp.erase(_key);
            deletenode(resNode);
            addnode(resNode);
            mp[_key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int _key, int _value) {
        if (mp.find(_key) != mp.end()){
            Node* existingNode = mp[_key];
            mp.erase(_key);
            deletenode(existingNode);
        }
        if (mp.size() == cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
 
        addnode(new Node (_key,_value));
        mp[_key] = head->next;

        return; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */