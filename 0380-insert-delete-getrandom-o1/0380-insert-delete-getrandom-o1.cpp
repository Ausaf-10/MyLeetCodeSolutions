class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> arr;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        arr.push_back(val);
        mp[val] = arr.size()-1;
        return true;    
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int backValue = arr.back();
        int indx = mp[val];
        arr[indx] = arr.back();
        arr.pop_back();
        mp[backValue] = indx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int indx = rand()%arr.size();
        return arr[indx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */