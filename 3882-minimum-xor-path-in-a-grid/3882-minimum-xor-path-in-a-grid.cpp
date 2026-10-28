class Solution {
public:
    int m,n;
    int solve(int i,int j,int x,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n){
            return INT_MAX;
        }
         x^=grid[i][j];
        if(i==m-1 && j==n-1){
          return x;
        }
        if (dp[i][j][x] != -1)
            return dp[i][j][x];
        
        int down=solve(i+1,j,x,grid,dp);
        int right=solve(i,j+1,x,grid,dp);

        return dp[i][j][x]=min(down,right); 
    }
    int minCost(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
         vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(1024,-1)));
         return solve(0,0,0,grid,dp);
    }
};