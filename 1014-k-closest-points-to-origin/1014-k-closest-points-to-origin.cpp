class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair <long long,long long>>> maxHeap;
        
        for (int i=0; i<points.size(); i++){
           
            long long x_square = points[i][0]*points[i][0];
            long long y_square = points[i][1]*points[i][1];

            long long value = x_square + y_square;

            maxHeap.push({value,{points[i][0],points[i][1]}});

            if (maxHeap.size() > k) maxHeap.pop();
        }

        while (!maxHeap.empty()){
            ans.push_back({(int)maxHeap.top().second.first,(int)maxHeap.top().second.second});
            maxHeap.pop();
        }
        
        return ans;
    }
};