class Solution {
public:
    string removeOccurrences(string s, string part) {
        // s.find() -> FIRST INDEX OF THE STRING 
        while (s.length()!=0 && s.find(part)<s.length()){
            // STARTING INDEX SE KITNE AUR CHARACTER REMOVE KRNE HAIN!
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};