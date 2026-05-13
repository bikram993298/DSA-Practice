class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = height[0];
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);

        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);

        int totalWater = 0;
/// my intition is for each building they hae hteir personal height and left max and right max,, they will store min(leftmax and right max) water - theri height upper to them,,so, lets ifnd  a building height 8 and left 3 and right 3 then 3- iwn height8 ,,then negatuve menas water will not store so then not plaus
        for(int i = 1; i < n-1; i++) {
            int waterLevel = min(leftMax[i-1], rightMax[i+1]);
            int trapped = waterLevel - height[i];

            if(trapped > 0) totalWater += trapped;
        }

        return totalWater;
    }
};