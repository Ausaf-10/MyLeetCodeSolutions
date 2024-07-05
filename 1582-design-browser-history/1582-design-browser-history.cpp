class Node{
    public:
        string val;
        Node* next, *prev;
        Node(string data){
            val = data;
            next = prev = NULL;
        }
};
class BrowserHistory {
public:
    Node* node;
    BrowserHistory(string homepage) {
        node = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        node->next = newNode, newNode->prev = node;
        node = node->next;
        return ;
    }
    
    string back(int steps) {
        int cnt = 0;
        while (cnt < steps && node->prev!=NULL){
            node = node->prev;
            cnt++;
        }
        return node->val;
    }
    
    string forward(int steps) {
        int cnt = 0;
        while (cnt < steps && node->next!=NULL){
            node = node->next;
            cnt++;
        }
        return node->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */