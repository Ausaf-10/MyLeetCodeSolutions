class Solution {
public:
    
    void merge(vector<int>& arr,int low,int mid,int high){
        int left = low, right = mid+1;
        vector<int> temp;

        while (left<=mid && right <= high){
            if (arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left<=mid){
            temp.push_back(arr[left]);
            left++;
        }

        while (right<=high){
            temp.push_back(arr[right]);
            right++;
        }

        for (int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
        return; 
    }

    void mergeSort(vector<int>& arr,int low,int high){
        if (low < high){
            int mid = (low+high)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
            return ;
        }

        return ;
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }

};