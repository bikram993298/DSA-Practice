class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> freq(10, 0);
        
      
        for(char c : num) {
            freq[c - '0']++;
        }
        
        string left = "";
        
        // Build left half (largest to smallest)
        for(int d = 9; d >= 0; d--) {
            int count = freq[d] / 2;
            
            //avoid leading zerovv
            if(d == 0 && left.empty()) continue;
            
            left += string(count, char('0' + d));
            freq[d] -= count * 2;
        }
        
       //find the largeest odd frequnccy
        string middle = "";
        for(int d = 9; d >= 0; d--) {
            if(freq[d] > 0) {
                middle = char('0' + d);
                break;
            }
        }
        
        // Reverse left to form right
        string right = left;
        reverse(right.begin(), right.end());
        
        string result = left + middle + right;
        
  
        if(result.empty()) return "0";
        
        return result;
    }
};