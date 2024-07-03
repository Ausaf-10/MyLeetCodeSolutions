class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size(), maxi = *max_element(skills.begin(), skills.end());
        deque<int> dq;
        for (int i=0; i<n; i++){
            dq.push_back(i);
        }
        int ans = 0, indx = -1, cnt = 0;
        while (true){
            int first = dq.front(); dq.pop_front();
            if (skills[first] == maxi) return first;
            int second = dq.front(); dq.pop_front();
            if (skills[first] > skills[second]){
                dq.push_front(first);
                dq.push_back(second);
                if (indx == first){
                    cnt++;
                    if (cnt == k) return indx;
                }
                else{
                    cnt = 1;
                    indx = first;
                    if (k == 1) return indx;
                }
                
            }
            else{
                dq.push_front(second);
                dq.push_back(first);
                if (indx == second){
                    cnt++;
                    if (cnt == k) return indx;
                }
                else{
                    cnt = 1;
                    indx = second;
                    if (k == 1) return indx;
                }
            }
        }
        return -1;
    }
};