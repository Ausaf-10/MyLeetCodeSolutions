class Solution {
public:
    bool isPalindrome(int x) {
        if (x>0){
            int d,num=x;
            unsigned int rev=0;
            while (num>0){
                d=num%10;
                rev=rev*10+d;
                num/=10;
            }
            if (rev==x){
                return 1;
            }
            else {
                return 0;
            }
        }
        else if (x==0){
            return 1;
        }
        else{
            return 0;
        }
        
    }
};