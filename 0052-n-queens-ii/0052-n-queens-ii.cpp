class Solution {
public:
    int count = 0;

    bool check(int p, int q, vector<string>& temp) {
        int n = temp.size();
        int m = temp[0].size();

        for(int i = 0; i < n; i++)
            if(temp[i][q] == 'Q') return false;

        for(int j = 0; j < m; j++)
            if(temp[p][j] == 'Q') return false;

        int x = p, y = q;
        while(x > 0 && y > 0) {
            x--; y--;
            if(temp[x][y] == 'Q') return false;
        }

        x = p; y = q;
        while(x < n-1 && y < n-1) {
            x++; y++;
            if(temp[x][y] == 'Q') return false;
        }

        x = p; y = q;
        while(x > 0 && y < n-1) {
            x--; y++;
            if(temp[x][y] == 'Q') return false;
        }

        x = p; y = q;
        while(x < n-1 && y > 0) {
            x++; y--;
            if(temp[x][y] == 'Q') return false;
        }

        return true;
    }

    void solve(int i, int n, vector<string>& temp) {
        if(i == n) {
            count++;
            return;
        }

        for(int j = 0; j < n; j++) {
            if(check(i, j, temp)) {
                temp[i][j] = 'Q';
                solve(i+1, n, temp);
                temp[i][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        solve(0, n, temp);
        return count;
    }
};