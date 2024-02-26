class Solution {
public:
    int n,m;
    bool isPossible(vector<int>& arr, vector<int>& changeIndices, int& seconds){
        vector<int> last(n,-1);
        for (int s=0; s<seconds; s++){
            last[changeIndices[s]] = s;
        }
        int mark =0, operation = 0;
        for (int i=0; i<seconds; i++){
            if (i == last[changeIndices[i]]){
                if (operation < arr[changeIndices[i]]) return false;
                else{
                    operation -= arr[changeIndices[i]];
                    mark++;
                }
            }
            else operation++;
        }
        return mark==n;
    }
    int earliestSecondToMarkIndices(vector<int>& arr, vector<int>& changeIndices) {
        n = arr.size(), m = changeIndices.size();
        for (int& number: changeIndices){
            number--;
        }
        int low = 0, high = m;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (isPossible(arr, changeIndices, mid)){
                high = mid - 1;
            }
            else low = mid + 1;

        }
        if (high == m) return -1; 
        return low;
    }
};