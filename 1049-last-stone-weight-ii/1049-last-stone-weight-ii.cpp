class Solution {
public:
// treating as a difference of 2 subset and we have to minimize the diff sum
    int solve(int i,int sum1,int total,vector<int>& stones,vector<vector<int>>&dp){
        if(i==stones.size()){
            return abs(total-2*sum1);
        }
        if(dp[i][sum1]!=-1){
            return dp[i][sum1];
        }
        int take=solve(i+1,sum1+stones[i],total,stones,dp);
        int notTake=solve(i+1,sum1,total,stones,dp);
        return dp[i][sum1]= min(take,notTake);
       
    }
    int lastStoneWeightII(vector<int>& stones) {
        int total=0;
        for(int stone:stones){
            total+=stone;
        }
        int n=stones.size();
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return solve(0,0,total,stones,dp);
    }
};