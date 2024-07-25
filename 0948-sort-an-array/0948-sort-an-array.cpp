class Solution {
public:
    int n;
    void heapify(int i, vector<int>& arr, int n){
        int largest = i, left = 2*i+1, right = 2*i+2;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (i!=largest){
            swap(arr[i], arr[largest]);
            heapify(largest, arr, n);
        }
        return ;
    }
    void buildHeap(vector<int>& arr){
        for (int i=n/2-1; i>=0; i--){
            heapify(i, arr, n);
        }
        return ;
    }
    void heapSort(vector<int>& arr){
        for (int i=n-1; i>=1; i--){
            swap(arr[i], arr[0]);
            heapify(0, arr, i);
        }
        return ;
    }
    vector<int> sortArray(vector<int>& arr) {
        n = arr.size();
        buildHeap(arr);
        heapSort(arr);
        return arr;
    }
};