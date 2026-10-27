class Solution {
public:
   int m,n;
    int solve(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>>&dp){
         if(i==m-1 && j==n-1){
           return max(1,1-dungeon[i][j]);
         }
         if(i>=m ||j>=n){
            return INT_MAX;
         }
         if(dp[i][j]!=INT_MAX){
            return dp[i][j];
         }
         int down=solve(i+1,j,dungeon,dp);
         int right=solve(i,j+1,dungeon,dp);
         int need= min(down,right)-dungeon[i][j];
         return dp[i][j]= max(1,need);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        return solve(0,0,dungeon,dp);
    }
};