class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;

        for(int i = 1; i < n; i++) {

            //num+1
            num = (num+1) | x;
            
        }

        return num;
    }
};


// This forces all the 1-bits of x to stay ON in the new number.

// Because OR rule:

// If bit is 1 in x → result bit becomes 1 no matter what

// So it guarantees:

// 𝑛
// 𝑢
// 𝑚
 
// &
 
// 𝑥
// =
// 𝑥
// num & x=x

// Meaning every element always contains all bits of x.