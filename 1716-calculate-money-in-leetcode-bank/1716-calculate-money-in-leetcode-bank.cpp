class Solution {
public:
    int totalMoney(int n) {
        int money = 0;
        int curr;
        for (int days = 0; days<n; days++){
            if (days % 7 == 0){
                int whichMonday = days/7;
                curr =  whichMonday + 1;
                money+=curr;
            }
            else{
                money+=curr;
            }
            curr+=1;
            
        }
        return money;
    }
};