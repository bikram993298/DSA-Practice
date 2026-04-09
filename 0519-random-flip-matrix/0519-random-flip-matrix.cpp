class Solution {
    int rows, cols;
    int remaining;
    unordered_map<int, int> mp;

public:
    Solution(int m, int n) {
        rows = m;
        cols = n;
        remaining = m * n;
    }

    vector<int> flip() {
        //pick random index
        int r = rand() % remaining;

        //  find actual value at r
        int actualIndex;
        if (mp.find(r) != mp.end()) {
            actualIndex = mp[r];
        } else {
            actualIndex = r;
        }
// li ke initially 1 2 3 4 5 6,,now after random 3 delete,,so we will decreasereamaing and  map me 3 index me last value 6 dal do,,q  ki 3 to remove ho chuka he and remaning bhi ek kom so 6 ko ou position pe daldo
        // find last available value
        int lastIndex;
        if (mp.find(remaining - 1) != mp.end()) {
            lastIndex = mp[remaining - 1];
        } else {
            lastIndex = remaining - 1;
        }

        // Step 4: move last value to position r
        mp[r] = lastIndex;

        // Step 5: reduce available size
        remaining--;

        // Step 6: convert to 2D
        return {actualIndex / cols, actualIndex % cols};
    }

    void reset() {
        mp.clear();
        remaining = rows * cols;
    }
};


// class Solution {
//     int rows, cols;
//     int remaining;
//     unordered_map<int, int> mp;

// public:
//     Solution(int m, int n) {
//         rows = m;
//         cols = n;
//         remaining = m * n;

//         // initialize full map (NOT OPTIMAL)
//         for (int i = 0; i < remaining; i++) {
//             mp[i] = i;
//         }
//     }

//     vector<int> flip() {
//         int r = rand() % remaining;

//         int val = mp[r];

//         // swap with last
//         mp[r] = mp[remaining - 1];

//         remaining--;

//         return {val / cols, val % cols};
//     }

//     void reset() {
//         mp.clear();
//         remaining = rows * cols;

//         for (int i = 0; i < remaining; i++) {
//             mp[i] = i;
//         }
//     }
// };