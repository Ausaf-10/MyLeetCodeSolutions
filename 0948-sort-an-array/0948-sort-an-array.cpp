class Solution {
public:

    void heapify(vector<int>& arr,int i,int n){
        int largest = i;

        int left = 2*i+1, right = 2*i+2;

        if (left < n && arr[largest] < arr[left]) largest = left;

        if (right < n && arr[largest] < arr[right]) largest = right;

        if (largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }

        return; 
    }

    void buildHeap(vector<int>& arr,int n){
        for (int i=n/2-1; i>=0; i--){
            heapify(arr,i,n);
        }

        return;
    }

    void heapSort(vector<int>& arr, int n){
        for (int i=n-1; i>=0; i--){
            swap(arr[0],arr[i]);
            heapify(arr,0,i);
        }

        return ;
    }

    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        buildHeap(arr,n);
        heapSort(arr,n);
        return arr;
    }
};