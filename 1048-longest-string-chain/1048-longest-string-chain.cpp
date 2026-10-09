class Solution {
public:
  bool check(string &s1,string &s2){
     if(s1.size()!=s2.size()+1) return false;
      int i=0;
      int j=0;
      while(i < s1.size() && j < s2.size()){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }else{
            i++;
        }
      }
      return j == s2.size();
  }
   int solve(int i, int prev,vector<string>& words,vector<vector<int>>&dp){
        if(i==words.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take=0;
        if(prev==-1||words[i].size()==1+words[prev].size() && check(words[i],words[prev])){
            take=1+solve(i+1,i,words,dp);
        }
        int notTake=solve(i+1,prev,words,dp);
        return dp[i][prev+1]= max(take,notTake);
   }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string a, string b) {
                 return a.size() < b.size();
             });
             int n=words.size();
             vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,words,dp);
    }
};