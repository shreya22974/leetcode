class Solution {
public: 
   bool solve(int i,string &s, vector<string>& wordDict,vector<int>&dp){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=0;j<wordDict.size();j++){
            string word=wordDict[j];
            if(s.substr(i,word.length())==word){
                if(solve(i+word.length(),s,wordDict,dp)){
                    return dp[i]= true;
                }
            }
        }
        return dp[i]= false;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,wordDict,dp);
    }
};