class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0, k = 0;
        for (int i=0; i<32; i++){
            int cnt = 0;
            for (auto no: nums){
                if ((1<<i)&no) cnt++;
            }
            if (cnt%3!=0) num = num | (1 << i);
            k++;
        }
        return num;
    }
};