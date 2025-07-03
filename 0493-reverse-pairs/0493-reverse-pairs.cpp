class Solution {
public:

    int merge(vector<int>& arr,int low,int mid,int high){
        int left = low, right = mid+1;
        vector<int> temp; 
        int cnt=0;  

        for (int i=low; i<=mid; i++){
            while (right <= high && arr[i] > 2*1ll*arr[right]) right++;
            cnt += (right- (mid+1));
        }

        left = low;
        right = mid + 1;
        while (left <= mid && right <= high){
            if (arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid){
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high){
            temp.push_back(arr[right]);
            right++;
        }

        for (int j=low; j<=high; j++){
            arr[j] = temp[j-low];
        }
        return cnt;

    }

    int mergeSort(vector<int>& arr,int low,int high){
        if (low >= high) return 0;
        int mid = (low+high)/2;
        int left = mergeSort(arr,low,mid);
        int right = mergeSort(arr,mid+1,high);
        return left + right + merge(arr,low,mid,high);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};