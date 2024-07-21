class Solution {
public:
    string losingPlayer(int x, int y) {
        int cnt = 1;
        while (true){
            if (x>=1 && y>=4){
                x-=1;
                y-=4;
                cnt++;
            }
            else break;
        }
        cnt-=1;
        if (cnt&1) return "Alice";
        return "Bob";
    }
};