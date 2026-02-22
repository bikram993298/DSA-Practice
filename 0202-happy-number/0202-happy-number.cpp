class Solution {
public:
    
    int getNext(int n) {
        int sum = 0;
        while(n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        
        unordered_set<int> seen;
        
        while(n != 1 && seen.find(n) == seen.end()) {
            
            seen.insert(n);
            n = getNext(n);
        }
        
        return n == 1;
    }
};

// for cheking repittaioan use map
// n = 2

// 2² = 4
// 4² = 16
// 1²+6²=37
// 3²+7²=58
// 5²+8²=89
// 8²+9²=145
// 1²+4²+5²=42
// 4²+2²=20
// 2²+0²=4 → cycle starts