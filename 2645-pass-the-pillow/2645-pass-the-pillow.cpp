class Solution {
public:
    int passThePillow(int n, int time) {
        int person = 1, t = 0, flag = 0;
        while (true){
            if (person == 1) flag = 0;
            if (!flag) person += 1;
            else person -= 1;
            t++;
            if (person == n){
                flag = 1;
            }
            if (t == time) break;
        }
        return person;
    }
};