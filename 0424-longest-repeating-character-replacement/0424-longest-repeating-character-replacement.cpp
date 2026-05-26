// T.C : O(n)
// S.C : O(1)


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, maxLen = 0;
        // we need valid windor windowsize-maxfreq<=k

        for(int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // if invalid window
            while((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                // update on maxfreq
                maxFreq=0;
                for(int i=0;i<26;i++){
                    maxFreq=max(maxFreq,freq[i]);
                }
                //we can not update the maxfreq befcause we not computing the exact valid window we only taccking upperboud of maxfreq
                // r example, suppose earlier my window had 3 A’s, so maxFreq = 3. After shrinking, maybe the current window has only 2 A’s, but I still keep maxFreq = 3. This may temporarily make the window look valid, but eventually as the window grows, the condition breaks and shrinking catches up naturall

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};



// Yes — this is the deepest part of Longest Repeating Character Replacement.

// Let’s go VERY slowly.

// ---

// # Problem Formula

// Window valid if:

// [
// windowSize - maxFreq \le k
// ]

// Meaning:

// ```text id="p7m4x2"
// characters to replace <= k
// ```

// ---

// # Example

// String:

// ```text id="v8t2k5"
// AABABBA
// ```

// k = 1

// ---

// # Start Expanding Window

// ---

// ## Window = "A"

// Freq:

// * A = 1

// ```text id="g5r9m1"
// maxFreq = 1
// ```

// Need replacements:

// [
// 1 - 1 = 0
// ]

// Valid.

// ---

// ## Window = "AA"

// Freq:

// * A = 2

// ```text id="x3k7v9"
// maxFreq = 2
// ```

// Need:

// [
// 2 - 2 = 0
// ]

// Valid.

// ---

// ## Window = "AAB"

// Freq:

// * A = 2
// * B = 1

// ```text id="m6q2t4"
// maxFreq = 2
// ```

// Need:

// [
// 3 - 2 = 1
// ]

// Valid.

// ---

// ## Window = "AABA"

// Freq:

// * A = 3
// * B = 1

// ```text id="n4v8p1"
// maxFreq = 3
// ```

// Need:

// [
// 4 - 3 = 1
// ]

// Valid.

// ---

// ## Window = "AABAB"

// Freq:

// * A = 3
// * B = 2

// ```text id="t7x5m3"
// maxFreq = 3
// ```

// Need:

// [
// 5 - 3 = 2
// ]

// INVALID because:

// * k = 1

// So now shrink.

// ---

// # IMPORTANT PART STARTS HERE

// Current window:

// ```text id="c2m8v7"
// AABAB
// ```

// left at first `'A'`.

// We remove it.

// ---

// # After Shrinking

// Window becomes:

// ```text id="w9t3k6"
// ABAB
// ```

// REAL frequencies:

// * A = 2
// * B = 2

// So REAL max frequency should be:

// ```text id="r5m1x8"
// 2
// ```

// BUT CODE DOES NOT UPDATE IT.

// Code still keeps:

// ```text id="h8v4p2"
// maxFreq = 3
// ```

// This is your doubt.

// ---

// # Now Let's See What Happens

// Code checks validity using STALE value:

// Window:

// ```text id="f6k9t1"
// ABAB
// ```

// Size:

// [
// 4
// ]

// Code uses:

// ```text id="d3x7m5"
// maxFreq = 3
// ```

// So:

// [
// 4 - 3 = 1
// ]

// Code thinks:

// ```text id="k2v8r4"
// VALID
// ```

// BUT REALITY:

// Actual maxFreq is 2.

// Real replacements needed:

// [
// 4 - 2 = 2
// ]

// Actually INVALID.

// ---

// # BIG QUESTION

// Why does algorithm STILL work??

// ---

// # THE KEY INSIGHT

// This stale maxFreq can ONLY make window:

// ```text id="s4m7x2"
// look more valid
// ```

// It NEVER makes us lose the answer.

// ---

// # What Happens Next?

// We continue expanding.

// Suppose next char:

// ```text id="v1t9k3"
// A
// ```

// Window:

// ```text id="m5x2r8"
// ABABA
// ```

// Actual frequencies:

// * A = 3
// * B = 2

// Now:

// ```text id="q7v4m1"
// maxFreq = 3
// ```

// becomes correct again naturally.

// Need:

// [
// 5 - 3 = 2
// ]

// Invalid.

// Now shrinking happens.

// ---

// # MOST IMPORTANT UNDERSTANDING

// Even though earlier:

// ```text id="w2m5x9"
// window was temporarily invalid
// ```

// the algorithm eventually fixes itself.

// ---

// # Why Final Answer Never Wrong

// Because:

// ## `maxFreq` came from a REAL earlier window.

// When we had:

// ```text id="j4t8v6"
// AABA
// ```

// there REALLY were 3 A's.

// So:

// ```text id="u9m3k1"
// maxFreq = 3
// ```

// was genuine.

// We are not inventing fake frequencies.

// ---

// # Another Important Insight

// We only care about:

// # Maximum window size ever achieved.

// Not whether EVERY intermediate window is perfectly valid.

// ---

// # Think Like This

// The algorithm is allowed to be:

// ```text id="e7x2m4"
// slightly lazy in shrinking
// ```

// But eventually:

// * invalid windows grow too much
// * shrinking catches up.

// So final maximum stays correct.

// ---

// # Why Interviewers Love This Trick

// Because:

// Without stale maxFreq:

// You would do:

// ```cpp id="b5v9t2"
// recompute max among 26 chars
// ```

// during every shrink.

// ---

// # Optimized Trick

// Keep:

// ```text id="g1m8x7"
// historical maximum frequency
// ```

// instead of exact current frequency.

// This avoids recomputation.

// ---

// # ONE-LINE PROOF

// ```text id="p4k7v1"
// A stale maxFreq may delay shrinking,
// but it can never cause us to miss the optimal answer.
// ```

// That is the entire proof.
