class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;

        if (nums.size() == 0 ) return 0;

        for (int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        int cnt,maxCnt=0;
        
        for (int i=0; i<nums.size(); i++){
            cnt=0;
            int number = nums[i];
            if (st.find(number-1) != st.end()) continue;
            else if (st.find(number-1) == st.end()){
                while (st.find(number) != st.end()){
                    cnt++;
                    number = number + 1;
                }
            }
            maxCnt = max(cnt,maxCnt);
        }

        return maxCnt;
        


    }
};