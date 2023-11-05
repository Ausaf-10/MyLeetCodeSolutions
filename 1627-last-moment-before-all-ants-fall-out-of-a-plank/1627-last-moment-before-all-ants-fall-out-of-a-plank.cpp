class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int rightAns = -1e9, leftAns = -1e9;
        // RIGHT ---->
        for (auto it : right){
            rightAns = max(rightAns, n - it);
        }

        // LEFT    <----
        for (auto it : left){
            leftAns = max(leftAns, it);
        }

        return max(rightAns, leftAns);
    }
};