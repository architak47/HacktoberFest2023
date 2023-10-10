class Solution {
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &arr, 
    vector<pair<int, int>> &v, int row0, int col0){
        vis[row] [col] = 1;
        v.push_back({row - row0, col-col0});
        int n = vis.size();
        int m = vis[0].size();
    
        int delrow[] = { -1, 0, 1, 0 };
        int delcol[] = { 0, 1, 0, -1 };
    
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
    
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] &&
            arr[nrow][ncol] == 1){
                dfs(nrow, ncol, vis, arr, v, row0, col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && arr[i][j] == 1){
                    vector<pair<int, int>> v;
                    dfs(i, j, vis, arr, v, i, j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
