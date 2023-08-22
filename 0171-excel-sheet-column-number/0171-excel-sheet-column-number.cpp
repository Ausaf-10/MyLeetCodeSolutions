class Solution {
public:
    int titleToNumber(string columnTitle) {
        int number = 0;
        int k = columnTitle.size()-1;
       
        for (int i=0; i<columnTitle.size(); i++){
            number+=pow(26,k)*(columnTitle[i]-'A'+1);
            k--;
        }


        return number;
    }
};