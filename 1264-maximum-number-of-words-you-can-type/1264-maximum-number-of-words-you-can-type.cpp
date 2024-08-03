class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for (auto it : brokenLetters) st.insert(it);
        int i = 0, j = 0, n = text.size(), cnt = 0;;
        while (i < n){
            while (j < n && text[j] != ' ') j++;
            string str = text.substr(i, j-i);
            bool flag = 1;
            for (auto it : str){
                if (st.count(it)){
                    flag = 0;
                    break;
                }
            }
            if (flag) cnt++;
            j++, i = j;
        } 
        return cnt;
    }
};