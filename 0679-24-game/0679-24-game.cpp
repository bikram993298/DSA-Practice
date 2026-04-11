class Solution {
public:
    bool solve(vector<double> a) {
        // if only one number left
        if (a.size() == 1) {
            return abs(a[0] - 24) < 1e-6;
        }

        // pick any 2 numbers
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a.size(); j++) {
                if (i == j) continue;

                vector<double> b;

                // put remaining numbers
                for (int k = 0; k < a.size(); k++) {
                    if (k != i && k != j) {
                        b.push_back(a[k]);
                    }
                }

                double x = a[i], y = a[j];

                // try all operations
                vector<double> temp;
                temp.push_back(x+y);
                temp.push_back(x-y);
                temp.push_back(y-x);
                temp.push_back(x*y);
                //  = {x + y, x - y, y - x, x * y};

                if (y != 0) temp.push_back(x / y);
                if (x != 0) temp.push_back(y / x);

                // try each result
                for (double v : temp) {
                    b.push_back(v);

                    if (solve(b)) return true;

                    b.pop_back(); // backtrack
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> a(cards.begin(), cards.end());
        return solve(a);
    }
};