class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        priority_queue<pair<int,int>> maxHeap;

        // STORING THE FREQUENCY OF EVERY CHARACTER IN MAP
        for (int i=0; i<s.size(); i++) mp[s[i]]++;

        //NOW PUTTING ALL THE CHARACTERS BASED ON THEIR FREQUENCY IN MAXHEAP
        for (auto number : mp){
            maxHeap.push({number.second,number.first});
        }

        // NOW POP ALL THE ELEMENT BASED ON THE FREQUENCY INTO A STRING 
        while (!maxHeap.empty()){
            int freq = maxHeap.top().first;
            char element = maxHeap.top().second;
            for (int i=0; i<freq; i++){
                ans.push_back(element);
            }
            maxHeap.pop();
        }

        return ans;
    }
};