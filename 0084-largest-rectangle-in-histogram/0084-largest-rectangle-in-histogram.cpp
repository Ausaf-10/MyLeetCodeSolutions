class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        stack<int>stk;
        for (int i=0; i<=n; i++){
            while (!stk.empty() && (i==n || heights[stk.top()] > heights[i])){
                int height = heights[stk.top()];
                stk.pop();
                int width;
                if (stk.empty()) width = i ;
                else width = i-stk.top()-1;
                maxi = max(maxi, height*width);
            }
            if (i<n) stk.push(i);
        }
        return maxi;
    }
};