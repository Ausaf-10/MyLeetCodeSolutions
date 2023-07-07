class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // THIS QUESTION IS THE SAMES AS ***TOP K FREQUENT ELEMENTS*** BUT IN THIS WE ARE TAKING
        // MAXHEAP BECAUSE WHEN THE COUNT OF 2 ELEMENTS ARE SAME THEN THE GREATER WILL BE 
        // AT THE TOP SO WE WOULD NOT HAVE TO DO ANYHTING EXTRA!!!
        priority_queue<pair<int,int>> maxHeap;
        vector<int> ans;
        unordered_map<int,int> mp;

        for (int i=0; i<nums.size(); i++) mp[nums[i]]++;

        // NOW PUTTING ELEMENTS FROM MAP TO MAXHEAP ACCORDING TO THEIR FREQUENCY
        for (auto number:mp){
            maxHeap.push({-1*number.second,number.first});
        }


        // NOW PUTTING ALL THE ELEMENTS FROM MAXHEAP TO ANS 
        while (!maxHeap.empty()){
            int freq = abs(maxHeap.top().first);
            int currentValue = maxHeap.top().second;

            for (int i=0; i<freq; i++){
                ans.push_back(currentValue);
            }

            maxHeap.pop();
        }

        return ans;
    }
};