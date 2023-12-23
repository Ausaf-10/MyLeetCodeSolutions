class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        int x = 0, y = 0;
        st.insert({0,0});
        for (int i=0; i<path.size(); i++){
            if (path[i] == 'N'){
                y+=1;
            }
            else if (path[i] == 'S'){
                y-=1;
            }
            else if (path[i] == 'E'){
                x+=1;
            }
            else{
                x-=1;
            }
            if (st.find({x,y}) != st.end()) return true;
            st.insert({x,y});
        }
        return false;
    }
};