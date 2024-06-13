class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.size() == 1 && bills[0]!=5) return false;
        int fiveDollar = 0, tenDollar = 0;
        for (int i=0; i<bills.size(); i++){
            if (bills[i] == 5) fiveDollar++;
            else if (bills[i] == 10){
                if (fiveDollar == 0) return false; 
                fiveDollar--;
                tenDollar++;
            }
            else{
                if (tenDollar > 0){
                    tenDollar--;
                    if (fiveDollar > 0) fiveDollar--;
                    else return false;
                }
                else{
                    if (fiveDollar >= 3) fiveDollar-=3;
                    else return false;
                }
            }
        }
        return true;
    }
};