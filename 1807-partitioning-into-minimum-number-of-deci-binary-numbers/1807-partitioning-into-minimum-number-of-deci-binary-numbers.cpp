class Solution {
public:
    int minPartitions(string str) {
        int maxNo = -1;
        for (int i=0; i<str.size(); i++){
            int number = str[i]-'0';
            maxNo = max(maxNo, number);
        }
        return maxNo;
    }
};