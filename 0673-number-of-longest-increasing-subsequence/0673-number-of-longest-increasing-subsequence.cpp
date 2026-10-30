class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxLen=1;
        vector<int>count(n,1);
        for(int i=n-1;i>=0;i--){
              dp[i]=1;
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }else if (nums[i]<nums[j] && dp[i] == 1 + dp[j]) {
                        count[i] += count[j];
                  }
            }
            maxLen=max(maxLen,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxLen){
                ans+=count[i];
            }
        }
        return ans;
    }
};