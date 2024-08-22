class MyHashSet {
public:
    int M = 1e4+1;
    vector<list<int>> vec;
    MyHashSet() {
        vec = vector<list<int>>(M,list<int>{});
    }

    int getIndx(int key){
        return key%M;
    }
    
    void add(int key) {
        int indx = getIndx(key);
        auto it = find(vec[indx].begin(), vec[indx].end(), key);
        if (it != vec[indx].end()){
            return ;
        }
        vec[indx].push_back(key);
        return ;
    }
    
    void remove(int key) {
        int indx = getIndx(key);
        auto it = find(vec[indx].begin(), vec[indx].end(), key);
        if (it == vec[indx].end()){
            return ;
        }
        vec[indx].erase(it);
        return ;
    }
    
    bool contains(int key) {
        int indx = getIndx(key);
        for (auto it = vec[indx].begin(); it!=vec[indx].end(); it++){
            if (*it == key){
                return true;
            }
        }
        return false;
    }
};