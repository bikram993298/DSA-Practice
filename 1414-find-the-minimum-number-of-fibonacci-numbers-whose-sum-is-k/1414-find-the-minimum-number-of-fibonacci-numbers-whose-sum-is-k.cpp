class Solution {
public:
    int findMinFibonacciNumbers(int k) {

        vector<int> fib = {1, 1};

        // generate fibonacci numbers
        while (fib.back() < k) {

            int n = fib.size();

            fib.push_back(fib[n - 1] + fib[n - 2]);
        }

        int count = 0;

        for (int i = fib.size() - 1; i >= 0; i--) {

            if (fib[i] <= k) {

                k -= fib[i];

                count++;
            }

            if (k == 0)
                break;
        }

        return count;
    }
};
// tc O(logk) because fibonacy takes this time

// Zeckendorf's theorem: every number has a unique representation as sum of non-consecutive Fibonacci numbers. Greedy: always subtract the largest Fibonacci ≤ k.