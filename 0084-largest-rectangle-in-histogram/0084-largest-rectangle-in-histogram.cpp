class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> s1,s2;
        int n = arr.size();
        vector<int> prevSmaller(n),nextSmaller(n);

        // CALCULATE THE PREVSMALLER
        for (int i=0; i<n; i++){
            int element = arr[i];
            while (!s1.empty() && arr[s1.top()] > element){
                s1.pop();
            }
            if (s1.empty()) prevSmaller[i] = 0;
            else prevSmaller[i] = s1.top() + 1;
            s1.push(i);
        } 

        // CALCULATE THE NEXTSMALLER
        for (int i=n-1; i>=0; i--){
            int element = arr[i];
            while (!s2.empty() && arr[s2.top()] >= element){
                s2.pop();
            }
            if (s2.empty()) nextSmaller[i] = n-1;
            else nextSmaller[i] = s2.top() - 1;
            s2.push(i);
        }

        int area = 0, maxArea = 0;
        for (int i=0; i<n; i++){
            area = arr[i] * (nextSmaller[i] - prevSmaller[i] + 1);
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};