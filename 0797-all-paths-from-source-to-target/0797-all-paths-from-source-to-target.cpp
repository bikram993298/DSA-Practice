class Solution {
public:
  vector<vector<int>> ans;
    vector<int>res;
    void dfs(int node,int parent,vector<vector<int>>& graph){
      
        res.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(res);
           
        }
        for(auto it:graph[node]){
            if(it==parent)continue;
            dfs(it,node,graph);

        }
           res.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0,-1,graph);


        return ans;

    }
};