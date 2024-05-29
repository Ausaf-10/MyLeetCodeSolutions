class Solution {
public:
    void addOne(string& str){
        int carry = 0;
        if (str[str.size()-1] == '0') str[str.size()-1] = '1';
        else{
            str[str.size()-1] = '0';
            carry = 1;
        }
        if (!carry) return;
        int i = str.size()-2;
        while (carry && i>=0){
            if (str[i] == '0'){
                carry = 0;
                str[i] = '1';
                break;
            }
            else{
                str[i] = '0';
            }
            i--;
        }
        if (carry) str.insert(str.begin(), '1');
        return ;
    }
    int numSteps(string s) {
        int cnt = 0;
        while (s.size()!=1){
            if (s[s.size()-1] == '0'){
                s.pop_back();
            }
            else{
                addOne(s);
            }
            cnt++;
        }
        return cnt;
    }
};