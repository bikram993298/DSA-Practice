class Solution {
public:
vector<int> nextgreater(vector<int> height){
    int m=height.size();
    stack<int>st;
    vector<int> rightSmaller(m,0);
    for (int j = m - 1; j >= 0; --j) {
            while (!st.empty() && height[st.top()] >= height[j])
                st.pop();
            rightSmaller[j] = (st.empty() ? m : st.top());
            st.push(j);
        }
        return rightSmaller;

}
vector<int> prevgreater(vector<int> height){
    int m=height.size();
    stack<int>st;
    vector<int> rightSmaller(m,0);
     for (int j = 0; j < m; ++j) {
            while (!st.empty() && height[st.top()] >= height[j])
                st.pop();
            rightSmaller[j] = (st.empty() ? -1 : st.top());
            st.push(j);
        }
        return rightSmaller;

}

 
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> height(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            height[0][j]=matrix[0][j]-'0';
            // cout<<height[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[i][j]=height[i-1][j]+1;
                }else{
                    height[i][j]=0;
                }

            }
        }

  //traverse through every row
  int ans=0;
  for(int i=0;i<n;i++){
    vector<int> next=nextgreater(height[i]);
      vector<int> prev=prevgreater(height[i]);
      for(int j=0;j<m;j++){
        int w=next[j]-prev[j]-1;
        int h=height[i][j];
        int side=min(w,h);
        ans=max(ans,side*side);

      }

  }
      

        return ans;
    }
};