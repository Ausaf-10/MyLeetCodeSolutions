

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        unordered_map <int,int> mp; // TO STORE THE COUNT OF EVERY ELEMENT IN ARRAY
        vector <int> ans; // TO STORE THE ANS 
        
        for(int i=0; i<nums.size(); i++)  mp[nums[i]]++;
           
        for(auto number:mp){
            minHeap.push({number.second, number.first}); // PUSHING THE PAIR BY COUNT FIRST THEN THE NUMBER ALONG WITH IT 
            if(minHeap.size() > k)
                minHeap.pop();
        }
        
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return ans;
    }
};