class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair <int,int>>> maxHeap;
        
        for (int i=0; i<points.size(); i++){
           
            int x_square = points[i][0]*points[i][0];
            int y_square = points[i][1]*points[i][1];

            int value = x_square + y_square;

            maxHeap.push({value,{points[i][0],points[i][1]}});

            if (maxHeap.size() > k) maxHeap.pop();
        }

        while (!maxHeap.empty()){
            ans.push_back({maxHeap.top().second.first,maxHeap.top().second.second});
            maxHeap.pop();
        }
        
        return ans;
    }
};