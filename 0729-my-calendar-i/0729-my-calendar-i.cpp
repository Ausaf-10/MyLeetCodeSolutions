class MyCalendar {
public:
    vector<vector<int>> arr;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if (arr.empty()){
            arr.push_back({start, end});
            return true;
        }
        else{
            for (int i=0; i<arr.size(); i++){
                if (arr[i][0] <= start && start < arr[i][1]) return false;
                else if (start <= arr[i][0] && end > arr[i][0]) return false;
            }
            arr.push_back({start,end});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */