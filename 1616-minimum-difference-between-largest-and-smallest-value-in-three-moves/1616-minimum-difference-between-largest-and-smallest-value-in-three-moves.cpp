class Solution {
public:
    int n;
    int f1(vector<int> arr){
        arr[n-1] = arr[n-2] = arr[n-3] = arr[n-4];
        return arr[n-4]-arr[0];
    }
    int f2(vector<int> arr){
        int i = 0, ele = arr[3];
        while (i<3 && i<n){
            arr[i] = ele;
            i++;
        }
        return arr[n-1]- arr[3];
    }
    int f3(vector<int> arr){
        arr[0] = arr[1];
        arr[n-1] = arr[n-2] = arr[n-3];
        return arr[n-3] - arr[1];
    }
    int f4(vector<int> arr){
        arr[0] = arr[1] = arr[2];
        arr[n-1] = arr[n-2];
        return arr[n-1]-arr[0];
    }
    int minDifference(vector<int>& arr) {
        n = arr.size();
        sort(arr.begin(), arr.end());
        if (n <= 3) return 0;
        int one = f1(arr), second = f2(arr), third = f3(arr), fourth = f4(arr);
        return min(f1(arr), min(f2(arr), min(f3(arr),f4(arr))));
    }
};