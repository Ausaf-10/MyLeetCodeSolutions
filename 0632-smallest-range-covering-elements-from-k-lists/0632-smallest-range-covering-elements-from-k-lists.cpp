class Node{
    public:
        int data,r,c;
        Node(int d,int row, int col){
            data = d , r = row, c = col;
        }
};
class cmp{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*,vector<Node*>,cmp> pq;
        int k = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        
        for (int i=0; i<k; i++){
            int element = nums[i][0];
            mini = min(mini,  nums[i][0]);
            maxi = max(maxi,  nums[i][0]);
            pq.push(new Node(element,i,0));
        }

        int start = mini, end = maxi;

        while (!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int row = node->r;
            int col = node->c;
            int val  = node->data;

            mini = val;

            if ( (long long)maxi - (long long)mini < (long long)end - (long long)start ){
                start = mini, end = maxi;
            }

            if (col+1 < nums[row].size()){
                pq.push(new Node(nums[row][col+1],row,col+1));
                maxi = max(maxi, nums[row][col+1]);
            }

            else break;

        }

        return {(int)start,(int)end};

    }
};