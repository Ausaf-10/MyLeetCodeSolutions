class Solution {
public:
    static bool cmp(string &a, string &b){
        string one = a+b, two = b+a;
        if (one > two) return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr(n);
        for (int i=0; i<n; i++){
            arr[i] = to_string(nums[i]);
        }
        sort(arr.begin(), arr.end(), cmp);
        string res;
        for (auto it : arr) {
            res+=it;
            if (res[0] == '0') return "0";
        }
        // if (res[0] == res[1] && res[0] == '0') return "0";
        return res;
    }
};