using ll = long long int;
class Solution {
public:
    int fun(vector<int>& arr, int pages){
        int stud = 1, load = 0;
        for (int i=0; i<arr.size(); i++){
            if (load + arr[i] <= pages){
                load+=arr[i];
                
            }
            else{
                stud++;
                load = arr[i];
            }
        }
        return stud;
    }
    int splitArray(vector<int>& arr, int painters) {
        int maxi = *max_element(arr.begin(), arr.end());
        ll s = 0;
        for (auto it : arr) s+=it;

        ll low = maxi, high = s;
        while (low <= high){
            ll mid = low + (high - low)/2;
            int reqPainter = fun(arr,mid);
            if (reqPainter > painters){
                low = mid + 1;
            }
            else high = mid -1;
        }
        return low;
    }
};