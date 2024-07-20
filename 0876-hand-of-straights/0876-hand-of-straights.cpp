class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> vis(n,0);
        for (int i=0; i<n; i++){
            if (!vis[i]){
                vector<int> temp;
                temp.push_back(arr[i]);
                bool flag = false; 
                if (temp.size() == k) flag = true;
                for (int j=i+1; j<n; j++){
                    if (!vis[j] && arr[j]-1 == temp.back()){
                        vis[j] = 1;
                        temp.push_back(arr[j]);
                        if (temp.size() == k){
                            flag = true;
                            break;
                        }
                    }
                }
                if (!flag) return false;
            }
        }
        return true;
    }
};