class Solution {
public:
    bool isPathCrossing(string path) {
        
        set<pair<int,int>> st;

        int x = 0;
        int y = 0;

        st.insert({0,0});

        for(char ch : path){

            if(ch == 'N') y++;

            else if(ch == 'S') y--;

            else if(ch == 'E') x++;

            else x--;

            // already visited
            if(st.count({x,y}))
                return true;

            st.insert({x,y});
        }

        return false;
    }
};