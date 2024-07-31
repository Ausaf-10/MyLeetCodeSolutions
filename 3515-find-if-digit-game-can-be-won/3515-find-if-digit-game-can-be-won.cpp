class Solution {
public:
    bool canAliceWin(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int singleDigit = 0, doubleDigit = 0;
        for (auto it : arr){
            string str = to_string(it);
            if (str.size() == 2){
                doubleDigit+=it;
            }
            else singleDigit+=it;
        }
        if (singleDigit > doubleDigit) return true;
        else if (doubleDigit > singleDigit) return true;
        return false;
    }
};