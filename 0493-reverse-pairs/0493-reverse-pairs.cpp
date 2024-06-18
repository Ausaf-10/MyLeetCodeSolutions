class Solution {
public:

    void merge(vector<int>& arr,int low,int mid,int high){
        int left = low, right = mid+1;
        vector<int> temp; 
        int cnt=0;  
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

        return ;
    }
    
    int countPairs(vector<int>& arr,int low,int mid,int high){
        int cnt = 0,right=mid+1;
        for (int i=low; i<=mid; i++){
            while (right <= high && arr[i]>2*(long long)arr[right]) right++;
            cnt+=(right - (mid+1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& arr,int low,int high){
        int cnt=0;
        if (low < high){
            int mid = (low+high)/2;
            cnt+=mergeSort(arr,low,mid);
            cnt+=mergeSort(arr,mid+1,high);
            cnt+=countPairs(arr,low,mid,high);
            merge(arr,low,mid,high);
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};