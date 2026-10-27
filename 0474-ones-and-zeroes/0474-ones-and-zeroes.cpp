class Solution {
public:
    int solve(int i,int m,int n,vector<string>& strs,vector<vector<vector<int>>>&dp){
        if(i==0){
          int zero = 0, one = 0;
            for (char c : strs[0]) {
                if (c == '0') zero++;
                else one++;
            }
            if (zero <= m && one <= n) return 1;
            return 0;
        }
        int zero=0,one=0;
        for(char c: strs[i]){
              if(c=='0'){
                zero++;
              }else{
                one++;
              }
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int take=0;
        if(zero<=m && one<=n){
            take=1+solve(i-1,m-zero,n-one,strs,dp);
        }
        int skip=solve(i-1,m,n,strs,dp);
        return dp[i][m][n]=max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<vector<vector<int>>>dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(size-1,m,n,strs,dp);
    }
};