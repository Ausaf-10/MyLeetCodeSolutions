class Solution {
public:
    int nextGreaterElement(int n) {
        // PUTTING THE DIGITS INTO THE ARRAY
        vector<int> arr;
        stack<int> stk;
        int num = n;
        while (num > 0){
            int d = num%10;
            stk.push(d);
            num/=10;
        }

        while (!stk.empty()){
            arr.push_back(stk.top());
            stk.pop();
        }

        // 1. FIND THE DIP OR BREAK POINT
        int indx = -1;
        for(int i=arr.size()-2; i>=0; i--){
            if (arr[i] < arr[i+1]){
                indx = i;
                break;
            }
        }

        if (indx == -1) return -1;

        // 2. FIND THE NEXT GREATER ELEMENT AND SWAP
        for (int i=arr.size()-1; i>=indx; i--){
            if (arr[i] > arr[indx]){
                swap(arr[i],arr[indx]);
                break;
            }
        }

        // 3. REVERSE THE REMAINING HALF OF THE ARRAY
        reverse(arr.begin()+indx+1,arr.end());

        long long number=0;
        for (int i=0; i<arr.size(); i++){
            number = number* 1LL *10 + (long long)arr[i] ;
        }

        if (number > INT_MAX) return -1;

        return number;
    }
};